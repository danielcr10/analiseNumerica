#include <math.h>
#define pi 3.14159265359 

void chebyshev (int n, double a, double b, double* xi) //xi vetor pre-alocado
{
  //xis - valores distribuidos no intervalo
  int i, beta = -1;
  
  for(i = 0; i < n; i++)
  {
    beta += 2;
    xi[i] = ((b - a)/2) * cos((beta * pi)/2*n) + (a + b)/2;
  }
  
}

void newtonCoef (int n, double* xi, double (*f) (double), double* bi)
{
  int i, aux;
  double res = 0;
  double *b = (double *) malloc(n - 1 * sizeof(double));
	if(b == NULL) {
		printf("Falta memoria. \n");
		exit(1);
	}
	
  for(i = 0; i < n - 1; i++)
    b[i] = calculaF(0, i, xi, f);
    
    for(i = 0; i < n - 1; i++)
    {
      calculaTermo(i, b, x, xi);
    }
    
    res =

}

double newtonAval (int n, double* xi, double* bi, double x)
{

}

static double calculaF (int i, int j, double * xi, double (*f) (double))
{
  if(i == j)
    return f(i);
  return (calculaF(i+1, j, xi, f) - calculaF(i, j-1, xi, f)) / xi[j] - xi[i];
}

static double calculaTermo(int i, double* b, double x, double* xi)
{
  double res;
  int j;
  
  res = b[i];
  for(j = 0; j<i; j++)
    res *= (x - xi[j]);
  return res;
}

//2a ja ta feito
//comparar a minha fnc com a fnc cos da matematica
