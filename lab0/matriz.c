#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
aponta para o vetor linha.
m é o numero de linhas
n é o numero de colunas */
double** matcria (int m, int n) //Não sei se está finalizado
{
  double **matriz;
  int i;

  matriz = vetcria(n);
  for(i=0; i<n; i++)
  {
    matriz[i][] = vetcria(m); //ta errado aqui
  }

  return matriz;
}

void matlibera (int m, double** A)
{
  int i;
  for(i=0; i<m; i++)
  {
    vetlibera(A[i]);
  }
}

void transposta (int m, int n, double** A, double** T)
{
  int i, j;
  T = matcria(n, m);
  for(i=0; i<m; i++)
  {
    for(j=0; j<n; j++)
    {
      T[i][j] = A[j][i];
    }
  }
}

void multmv (int m, int n, double** A, double* v, double* w)
{
  int i,j;
  w = vetcria(m);
  for(i=0; i<n; i++)
  {
    for(j=0; j<m; j++)
    {
      w[i] += A[i][j]*v[j];
    }
  }
}

void multmm (int m, int n, int q, double** A, double** B, double** C)
{
  
}
