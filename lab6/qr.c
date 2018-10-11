#include <stdio.h>
#include <math.h> 
#include "matriz.h"
double escalar(int n, double* v, double* w);
double norma (int m, double* v);
double* escalarVetor(int n, double a, double* v);
void substituicao (int n, double** a, double* v, double* x);

void QR (int m, int n, double** A, double** Q, double** R)
{
  double* v = vetcria(n);
  double* w = vetcria(n);
  double** QT = matcria(n, m);
 
  for(int j = 0; j < n; j++)
  {
  
    for(int i = 0; i < m; i++)//preenche o vetor v e w = v
    {
      v[i] = A[i][j]; //todos elementos da primeira coluna
      w[i] = v[i];
    }
    
    for(int i = 0; i < j; i++)
    {
      transposta(m, n, Q, QT);
      //multmv();
      R[i][j] = escalar(n, QT[i], w);
      w = escalarVetor(n, R[i][j], Q[i]);
    }
    R[j][j] = norma(n, w);
    R[j][j] = 1/R[j][j];
    Q[j] = escalarVetor(n, R[j][j], w);
  }
}

double mmqQR (int m, int n, double** A, double* b, double* x)//retornar 0
{
  double** Q = matcria(m, n);
  double** R = matcria(n, n);
  double** Rx = matcria(m, n);

  QR(m, n, A, Q, R);

  substituicao (n, A, b, x);
  for (int i = 0; i < n; ++i)
  {
    printf("%f - ", x[i]);
  }
  return 0;
}

double norma (int m, double* v)
{
  double resul = 0;
  for(int i = 0; i < m; i++)
  {
    resul += pow(v[i], 2);
  }
  resul = sqrt(resul);
  return resul;
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

double* escalarVetor(int n, double a, double* v)
{
  int i;
  double* w = vetcria(n);
  for(i = 0; i < n; i++){
    w[i] = v[i] * a;
  }
  return w;
}

void substituicao (int n, double** a, double* v, double* x)
{
  for (int i=n-1; i>=0; --i) {
    double s = 0;
    for (int j=i+1; j<n; ++j) 
      s += a[i][j]*x[j];
    x[i] = v[i] / a[i][i];
  }
}