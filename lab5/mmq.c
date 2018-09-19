#include <stdio.h>
#include<math.h>
#include "mmq.h"

void MMQ (int m, int n, double** A, double* b, double* x)
{
  double** T;
  double** TA;
  double** TAx;
  double** Tb;
  int* p;
  
  T = matcria(n, m);
  TA = matcria(m, m);
  Tb = vetcria(m);

  transposta(m, n, A, T);
  multmm(n, m, n, T, A, TA);
  multmv(n, m, T, b, Tb);
   
  fatoracao(n, TA, p);
  substituicao(n, TA, p, Tb, x);  
}

double RMSE (int m, int n, double** A, double* b, double* x)
{
  double norma;
  double * r = (double *) malloc(sizeof(double) * m);
  double * Ax = (double *) malloc(sizeof(double) * m);
  
  mat_multv(m, n, A, x, Ax);
  for (i = 0; i < m; i++)
    r[i] = b[i] - Ax[i];
  norma = norma2(m-1, r);
  
  return norma/sqrt(m);
} //respo teste 1a = 1.08

double periodico (int n, double* t, double* v, double* c)
{

}
