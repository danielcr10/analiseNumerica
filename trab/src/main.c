#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "sparse.h"
#include "matriz.h"

double **geraMatrizA1(int n, int m)
{
   int i, j;
   double **ret = matcria(n, m);

   for (i = 0; i < n; i++)
      for (j = 0; j < m; j++) {
         ret[i][j] = 0;
      }

      for (i = 0; i < n; i++)
         for (j = 0; j < m; j++) {
            if (i == j) {
               ret[i][j] = i+1;
               if (i + 1 < n) {
                  ret[i][j + 1] = 0.5;
                  ret[i + 1][j] = 0.5;
               }
               if (i + 2 < n) {
                  ret[i][j + 2] = 0.5;
                  ret[i + 2][j] = 0.5;
               }
            }
         }

         return ret;
      }

      double **geraMatrizA2(int n, int m)
      {
         int i, j;

         double **ret = geraMatrizA1(n, m);


         for (i = 0; i < n; i++)
            for (j = 0; j < m; j++) {
               if (i == j) {
                  if (2*i < n) {
                     ret[2 * i][j] = 0.5;
                     ret[i][j * 2] = 0.5;
                  }
               }
            }

            return ret;
         }

         double erro(double *xb, double *x, int n)
         {
            int i;
            double err = 0.0;

            for (i = 0; i < n; i++) {
               err += fabs(xb[i] - x[i]) / x[i];
            }

            return err / n;
         }

         int main(void)
         {
            int p = 100;
            double **A1 = geraMatrizA1(p, p);
            double **A2 = geraMatrizA2(p, p);
            double *x = malloc(p * sizeof(double));
            double *b = malloc(p *sizeof(double));
            double *xbarra = malloc(p *sizeof(double));
            struct matrix *A = reduceRep(p, p, A1);
            struct matrix *AA = reduceRep(p, p, A2);
            int n;
            int w = 0;
            clock_t end,start;

               printf("Matriz simples:\n");
               printf(" N = %d\n\n", p);
               printf("Sem pre-cond\n");
               start = clock();
               for (int i = 0; i < p; i++) {
                  x[i] = 1.0;
                  b[i] = 0.0;
                  xbarra[i] = 0.0;
               }
               multmv(p, p, A, x, b);
               n = gradienteConjugado(p, A, b, xbarra, 0.00001);
               end = clock();
               printf("Erro: %.7f\n", erro(xbarra, x, p));
               printf("Iteracoes: %d\n", n);
               printf("Tempo: %lf\n\n\n", (double)(end-start) / CLOCKS_PER_SEC);

               printf("Jacobi\n");
               start = clock();
               for (int i = 0; i < p; i++) {
                  x[i] = 1.0;
                  b[i] = 0.0;
                  xbarra[i] = 0.0;
               }
               multmv(p, p, A, x, b);
               n = gcJacobi(p, A, b, xbarra, 0.00001);
               end = clock();
               printf("Erro: %.7f\n", erro(xbarra, x, p));
               printf("Iteracoes: %d\n", n);
               printf("Tempo: %lf\n\n\n", (double)(end-start) / CLOCKS_PER_SEC);

               printf("Gauss-Seidel\n");
               start = clock();
               for (int i = 0; i < p; i++) {
                  x[i] = 1.0;
                  b[i] = 0.0;
                  xbarra[i] = 0.0;
               }
               multmv(p, p, A, x, b);
               n = gcSSOR(p, A, b, xbarra, 0.00001, 1.0);
               end = clock();
               printf("Erro: %.7f\n", erro(xbarra, x, p));
               printf("Iteracoes: %d\n", n);
               printf("Tempo: %lf\n\n\n", (double)(end-start) / CLOCKS_PER_SEC);

               printf("SSOR\n");
               start = clock();
               for (int i = 0; i < p; i++) {
                  x[i] = 1.0;
                  b[i] = 0.0;
                  xbarra[i] = 0.0;
               }
               multmv(p, p, A, x, b);
               n = gcSSOR(p, A, b, xbarra, 0.00001, 1.2);
               end = clock();
               printf("Erro: %.7f\n", erro(xbarra, x, p));
               printf("Iteracoes: %d\n", n);
               printf("Tempo: %lf\n\n\n", (double)(end-start) / CLOCKS_PER_SEC);
               

               printf("------------------------\n");
               

               printf("Matriz estendida:\n");
               printf(" N = %d\n\n", p);
               printf("Sem pre-cond\n");
               start = clock();
               for (int i = 0; i < p; i++) {
                  x[i] = 1.0;
                  b[i] = 0.0;
                  xbarra[i] = 0.0;
               }
               multmv(p, p, AA, x, b);
               n = gradienteConjugado(p, AA, b, xbarra, 0.00001);
               end = clock();
               printf("Erro: %.7f\n", erro(xbarra, x, p));
               printf("Iteracoes: %d\n", n);
               printf("Tempo: %lf\n\n\n", (double)(end-start) / CLOCKS_PER_SEC);

               printf("Jacobi\n");
               start = clock();
               for (int i = 0; i < p; i++) {
                  x[i] = 1.0;
                  b[i] = 0.0;
                  xbarra[i] = 0.0;
               }
               multmv(p, p, AA, x, b);
               n = gcJacobi(p, AA, b, xbarra, 0.00001);
               end = clock();
               printf("Erro: %.7f\n", erro(xbarra, x, p));
               printf("Iteracoes: %d\n", n);
               printf("Tempo: %lf\n\n\n", (double)(end-start) / CLOCKS_PER_SEC);

               printf("Gauss-Seidel\n");
               start = clock();
               for (int i = 0; i < p; i++) {
                  x[i] = 1.0;
                  b[i] = 0.0;
                  xbarra[i] = 0.0;
               }
               multmv(p, p, AA, x, b);
               n = gcSSOR(p, AA, b, xbarra, 0.00001, 1.0);
               end = clock();
               printf("Erro: %.7f\n", erro(xbarra, x, p));
               printf("Iteracoes: %d\n", n);
               printf("Tempo: %lf\n\n\n", (double)(end-start) / CLOCKS_PER_SEC);

               printf("SSOR\n");
               start = clock();
               for (int i = 0; i < p; i++) {
                  x[i] = 1.0;
                  b[i] = 0.0;
                  xbarra[i] = 0.0;
               }
               multmv(p, p, AA, x, b);
               n = gcSSOR(p, AA, b, xbarra, 0.00001, 1.2);
               end = clock();
               printf("Erro: %.7f\n", erro(xbarra, x, p));
               printf("Iteracoes: %d\n", n);
               printf("Tempo: %lf\n\n\n", (double)(end-start) / CLOCKS_PER_SEC);

            return 0;
         }
