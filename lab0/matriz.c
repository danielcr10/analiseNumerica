#include "matriz.h"

double* vetcria (int n)
{
  double *vet = (double *) malloc(n *sizeof(double));
  if(vet == NULL)
  {
    printf("falta de memória");
    exit(1);
  }
  return vet;
}

void vetlibera (double* v)
{
  free(v);
}

double escalar (int n, double* v, double* w)
{
  double esc=0;
  for(int i = 0; i < n; i++)
  {
    esc = esc + (v[i] * w[i]);
  }
  return esc;
}

double norma2 (int n, double* v)
{
  double norma;
  norma = escalar(n, v, v);
  norma = sqrt(norma);
  return norma;
}


/* A matriz será representada por um vetor de ponteiros, onde cada elemento
aponta para o vetor linha.*/
double** matcria (int m, int n)
{
  return double n=0;
}

void matlibera (int m, double** A)
{

}

void transposta (int m, int n, double** A, double** T)
{

}

void multmv (int m, int n, double** A, double* v, double* w)
{

}

void multmm (int m, int n, int q, double** A, double** B, double** C)
{

}
