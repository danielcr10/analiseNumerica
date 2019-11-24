#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "matriz.h"
#include "sparse.h"

double* vetcria(int n)
{
   double *vetor = (double *) malloc(n * sizeof(double));
   if(vetor == NULL) {
      printf("Memory allocation error. \n");
      exit(-1);
   }

   return vetor;
}

void vetlibera(double* v)
{
   free(v);
}

double escalar(int n, double* v, double* w)
{
   int i;
   double produtoEscalar = 0;
   for(i = 0; i < n; i++) {
      produtoEscalar += v[i] * w[i];
   }

   return produtoEscalar;
}

double norma2(int n, double* v)
{
   int i;
   double somatorio = 0;
   for(i = 0; i < n; i++) {
      somatorio += pow(v[i], 2);
   }

   return sqrt(somatorio);
}

int vetiguais(int n, double* v, double* w, double tol)
{
   int i;
   for(i = 0; i < n; i++) {
      if(fabs(v[i] - w[i]) > tol) {
         return 0;
      }
   }

   return 1;
}

void vetimprime(int n, double* v, char* format)
{
   int i;
   for(i = 0; i < n; i++) {
      printf(format, v[i]);
      printf("\n");
   }
}

double** matcria(int m, int n)
{
   int i;
   double **matriz = (double **) malloc(m * sizeof(double*));
   if(matriz == NULL) {
      printf("Memory allocation error. \n");
      exit(-1);
   }

   for(i = 0; i < m; i++) {
      matriz[i] = (double *) malloc(n * sizeof(double));
      if(matriz[i] == NULL) {
         printf("Memory allocation error. \n");
         exit(-1);
      }
   }

   return matriz;
}

void matlibera(int m, double** A)
{
   int i;
   for(i = 0; i < m; i++) {
      free(A[i]);
   }

   free(A);
}

void transposta(int m, int n, double** A, double** T)
{
   int i, j;
   for(i = 0; i < m; i++) {
      for(j = 0; j < n; j++) {
         T[j][i] = A[i][j];
      }
   }
}

void multmv (int m, int n, struct matrix* A, double* v, double* w)
{
   int i, j; 
   for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++){
         list *aux = getValue(i, j, A);
         if (aux)
            w[i] += aux -> value * v[j];
         else
            w[i] += 0;
      }
   }
}

void multmm (int m, int n, int q, struct matrix* A, struct matrix* B, struct matrix* C)
{
   int i, k, j;
   for (i = 0; i < m; i++) {
      for (k = 0; k < q; k++) {
         for (j=0; j < n; j++){
           list *aux = getValue(i, j, A);
           if (aux) {
            double val;
            list *aux2 = getValue(j, k, B);
            list *aux3 = getValue(i, k, C);
            if (aux2)
            	val = aux -> value * aux2 -> value;
            else
             val = 0.0;
          if (aux3)
           setValue(i, k, C, val + aux3->value);
        else
          setValue(i, k, C, val + 0);
    }
 }
}
}
}

int matiguais(int m, int n, double** A, double** B, double tol)
{
   int i, j;
   for(i = 0; i < m; i++) {
      for(j = 0; j < n; j++) {
         if(fabs(A[i][j] - B[i][j]) > tol) {
            return 0;
         }
      }
   }

   return 1;
}

void matimprime(int m, int n, double** A, char* format)
{
   int i, j;
   for(i = 0; i < m; i++) {
      for(j = 0; j < n; j++) {
         printf(format, A[i][j]);
         printf(" ");
      }
      printf("\n");
   }
}
