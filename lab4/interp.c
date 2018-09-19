#include <stdio.h>
#include <math.h>
#include "interp.h"

#define pi 3.14159265359 

void chebyshev (int n, double a, double b, double* xi)
{
  int i, beta = -1;
  
  for(i = 0; i < n; i++)
  {
    beta += 2;
    xi[i] = ((b - a)/2) * cos((beta * pi)/(2*n)) + (a + b)/2;
  }
  
}

void newtonCoef (int n, double* xi, double (*f) (double), double* bi)
{
  int i, j, k;
  Matriz F = mat_cria(n, n);
  double *b = malloc(sizeof(double *) * n);
  if(b == NULL) {
    printf("Falta memoria. \n");
    exit(1);
  }

  for (k = 0; k < n; k++) {
    i = 0;
    for (j = k; j < n; j++, i++) {
      if (i == j)
        F[i][j] = f(xi[i]);
      else
        F[i][j] = (F[i+1][j] - F[i][j-1]) / (xi[j] - xi[i]);
    }
  }
  
  for (i = 0; i < n; i++)
    bi[i] = F[0][i];
}

double newtonAval (int n, double* xi, double* bi, double x)
{
  int i,j;
  double s = 0, t;

  for(i = 0; i < n; i++)
  {
    t = bi[i];
    for(j = 0; j < i; j++)
    {
      t *= ( x - xi[j] );
    }
    s += t;
  }
  return s;
}

static Matriz mat_cria (int m, int n) {
  int i;
  double **matriz;
  
  matriz = malloc(m * sizeof(double *));
  
  for (i = 0; i < m; i++) {
    matriz[i] = malloc(n * sizeof(double));
  }
  
  return matriz;
}