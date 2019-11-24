#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "sparse.h"
#include "cond.h"
#include "matriz.h"
#include "util.h"
#include "list.h"

struct matrix *reduceRep(int n, int m, double **M)
{
   int i, j;
   struct matrix *ret = myrealloc(NULL, sizeof(struct matrix) * n);

   for (i = 0; i < n; i++) {
      ret[i].linha = list_cria();
      for (j = 0; j < m; j++) {
         if (M[i][j] != 0) {
            list_insere(ret[i].linha, j, M[i][j]);
            ret[i].len += 1;
         }
      }
   }

   return ret;
}



list *getValue(int linha, int coluna, struct matrix *M)
{
   list *aux = M[linha].linha;

   while (aux) {
	if(aux -> coluna == coluna)
	   return aux;
        aux = aux -> next;
   }

   return NULL;
}

void setValue(int linha, int coluna, struct matrix *M, double value)
{
      if (list_getColuna(M[linha].linha, coluna) >= 0) {
         if (value == 0) { 
            list_remove(M[linha].linha, coluna);
            M[linha].len += -1;
         } else {
            list_setValue(M[linha].linha, coluna, value);
         }
      } else {
         if (value != 0) {
            list_insere(M[linha].linha, coluna, value);
            M[linha].len += 1;
         }
      }
}

int gradienteConjugado(int n, struct matrix *A, double *b, double *x, double tol)
{
   double *d = myrealloc(NULL, n * sizeof(double));
   double *r = myrealloc(NULL, n * sizeof(double));
   double *aux = myrealloc(NULL, n * sizeof(double));
   double alpha = 0, beta = 0;
   double norma2;
   double den,num;
   int k;

    multmv(n, n, A, x, d);
    for (int c = 0; c < n; c++) {
      d[c] = b[c] - d[c];
      r[c] = d[c];
   }

   for (k = 0; k < n; k++) {
      den = 0;
      num = 0;
      norma2 = 0;
      for (int c = 0; c < n; c++)
         norma2 += r[c] * r[c];
      norma2 = sqrt(norma2);

      if (norma2 < tol) break;

      multmv(n, n, A, d, aux);
      for (int c = 0; c < n; c++) {
         num += r[c] * r[c];
         den += d[c] * aux[c];
      }
      alpha = num/den;

      den = 0;
      num = 0;
      for (int c = 0; c < n; c++) {
         den += r[c] * r[c];
         x[c] = x[c] + alpha * d[c];
         r[c] = r[c] - alpha * aux[c];
         num += r[c] * r[c];
      }
      beta = num/den;
      for (int c = 0; c < n; c++)
         d[c] = r[c] + beta * d[c];
   }
   return k;
}

int gcJacobi(int n, struct matrix *A, double *b, double *x, double tol)
{
   double *d = myrealloc(NULL, n * sizeof(double));
   double *r = myrealloc(NULL, n * sizeof(double));
   double *aux = myrealloc(NULL, n * sizeof(double));
   double alpha = 0, beta = 0;
   double norma2;
   double den, num;
   int k;

   struct matrix *R = reduceRep(n, n, geraNULL(n, n));
   struct matrix *D = Jacobi(n, n, A);
   multmv(n, n, D, b, b);
   multmm(n, n, n, A, D, R);

   for (k = 0; k < n; k++) {
      d[k] = 0;
      aux[k] = 0;
   }

   multmv(n, n, R, x, d);

   for (int c = 0; c < n; c++) {
      d[c] = b[c] - d[c];
      r[c] = d[c];
   }

   for (k = 0; k < n; k++) {
      num = 0;
      den = 0;
      norma2=0;
      for(int c = 0; c < n; c++)
         norma2 += r[c] * r[c];
      norma2 = sqrt(norma2);

      if (norma2 < tol) break;

      multmv(n, n, R, d, aux);
      for(int c = 0; c < n; c++) {
         num += r[c] * r[c];
         den += d[c] * aux[c];
      }
      alpha = num/den;

      den = 0;
      num = 0;
      for (int c = 0; c < n; c++) {
         den += r[c] * r[c];
         x[c] = x[c] + alpha * d[c];
         r[c] = r[c] - alpha * aux[c];
         num += r[c] * r[c];
      }
      beta = num/den;
      for (int c = 0; c < n; c++)
         d[c] = r[c] + beta * d[c];
   }
   return k;
}

int gcSSOR(int n, struct matrix *A, double *b, double *x, double tol, double w)
{
   double *d = myrealloc(NULL, n * sizeof(double));
   double *r = myrealloc(NULL, n * sizeof(double));
   double *aux = myrealloc(NULL, n * sizeof(double));
   double alpha = 0;
   double beta = 0;
   double norma2;
   double den,num;
   int k;

   struct matrix *R = reduceRep(n, n, geraNULL(n, n));
   struct matrix *M = SSOR(n, n, A, w);
   multmv(n, n, M, b, b);
   multmm(n, n, n, A, M, R);

   multmv(n, n, R, x, d);

   for (int c = 0; c < n; c++) {
      d[c] = b[c] - d[c];
      r[c] = d[c];
   }

   for (k = 0; k < n; k++) {
      den = 0;
      num = 0;
      norma2 = 0;
      for (int c = 0; c < n; c++)
         norma2 += r[c] * r[c];
      norma2 = sqrt(norma2);

      if (norma2 < tol) break;

      multmv(n, n, R, d, aux);
      for (int c = 0; c < n; c++) {
         num += r[c] * r[c];
         den += d[c] * aux[c];
      }
      alpha = num/den;

      den = 0;
      num = 0;
      for (int c = 0; c < n; c++) {
         den += r[c] * r[c];
         x[c] = x[c] + alpha * d[c];
         r[c] = r[c] - alpha * aux[c];
         num += r[c] * r[c];
      }
      beta = num/den;
      for (int c = 0; c < n; c++)
         d[c] = r[c] + beta * d[c];
   }
   return k;
}
