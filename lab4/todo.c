#include <stdio.h>
#include <math.h>
#include "interp.h"

#define pi 3.14159265359 

typedef double ** Matriz;
void chebyshev (int n, double a, double b, double* xi) //xi vetor pre-alocado
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
  int i;
  for(i = 0; i < n; i++)
    bi[i] = calculaF(0, i, xi, f);
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

static double calculaF (int i, int j, double * xi, double (*f) (double))
{
  if(i == j){
    return f(xi[i]);
    printf("\nEntrou%f\n", xi[i]);
  }
  printf("nao entra\n");
  printf("\nAqui%f\n", xi[i]);printf("\nAqui3%f\n", f(xi[i]));
  return (calculaF(i+1, j, xi, f) - calculaF(i, j-1, xi, f)) / (xi[j] - xi[i]);
}

//2a ja ta feito
//comparar a minha fnc com a fnc cos da matematica
