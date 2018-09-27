#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mmq.h"
#include "matriz.h"
#include "sistlinear.h"
void matimprime(int m, int n, double** A, char* format);

void MMQ (int m, int n, double** A, double* b, double* x)
{
  double** T;
  double** TA;
  double* Tb;
  double* p;
  
  T = matcria(n, m);
  TA = matcria(m, m);
  Tb = vetcria(m);
  p = vetcria(m);

  transposta(m, n, A, T);
  matimprime(n, m, T, "%f");
  multmm(n, m, n, T, A, TA);
  printf("\n\n\n");
  matimprime(m, n, TA, "%f");

  multmv(n, m, T, b, Tb);

  fatoracao(n, TA, (int*)p);
  printf("\n\n\n");
  for (int i = 0; i < m; ++i)
    {
      printf("%f\n",p[i]);
    }  
  substituicao(m, TA, (int*)p, Tb, x);
  printf("\n\n\n");
  for (int i = 0; i < m; ++i)
    {
      printf("%f\n",x[i]);
    }  
}

double RMSE (int m, int n, double** A, double* b, double* x)
{
  double norma;
  double * r = (double *) malloc(sizeof(double) * m);
  double * Ax = (double *) malloc(sizeof(double) * m);
  
  multmv(m, n, A, x, Ax);
  for (int i = 0; i < m; i++){
    r[i] = b[i] - Ax[i];
    printf("r:%f\n", r[i]);
    printf("b:%f\n", b[i]);
    printf("Ax:%f\n", Ax[i]);
    printf("x:%f\n", x[i]);
  }
  norma = norma2(m, r);
  printf("Norma:%f e raiz:%f\n", norma, sqrt(m));
  return norma/sqrt(m);
} //respo teste 1a = 1.08

double periodico (int n, double* t, double* v, double* c)
{
  double** T;
  T = matcria(n, 5);
  for (int i = 0; i < 5; i++)
  {
    T[i][0] = 1;
    T[i][1] = t[i];
    T[i][2] = sin(2 * M_PI * t[i]);
    T[i][3] = cos(2 * M_PI * t[i]);
    T[i][4] = cos(4 * M_PI * t[i]);
  }

  MMQ(n, 5, T, v, c);

  /*for (int i = 0; i < n; i++)
  {
    v[i] = c[0] + c[1] * t[i] + c[2] * sin(2 * M_PI * t[i]) + c[3] * cos(2 * M_PI * t[i]) + c[4] * cos(4 * M_PI * t[i]);
  }*/
  return RMSE(n, 5, T, v, c);

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