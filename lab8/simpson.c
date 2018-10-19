#include <math.h>

#include "simpson.h"

double DoubleSimpson(double a, double b, double (*f) (double x), double* v)
{
	double intAB, intAC, intCB;
	double erro;
	double h = b - a;
	double c = (a + b) / 2;

	intAB = simpson(f, a, b, 1);
	intAC = simpson(f, a, c, 1);
	intCB = simpson(f, c, b, 1);

	erro = fabs(intAB - (intAC + intCB)) / 15;

	*v = intAC + intCB - erro;

	return erro;
}

double AdaptiveSimpson(double a, double b, double (*f) (double x), double tol)
{
	double c;
	double resultado;
	double erro = DoubleSimpson(a, b, f, &resultado);

	if(erro <= tol) {
		return resultado;
	}

	c = (a + b) / 2;

	return AdaptiveSimpson(a, c, f, tol / 2) + AdaptiveSimpson(c, b, f, tol/ 2);
}

double Quadratura2(double a, double b, double (*f) (double x))
{
	const int n = 2;
	int i;
	double resultado = 0;
	double x[] = {-sqrt(1 / 3), sqrt(1 / 3)};
	double novoX;

	for(i = 0; i < n; i++) {
		novoX = ((b - a) * x[i] + b + a) / 2;
		resultado += f(novoX);
	}

	resultado *= (b - a) / 2;

	return resultado;
}

double Quadratura3(double a, double b, double (*f) (double x))
{
	const int n = 3;
	int i;
	double resultado = 0;
	double x[] = {-sqrt(3.0 / 5), 0, sqrt(3.0 / 5)};
	double c[] = {(5.0 / 9), (8.0 / 9), (5.0 / 9)};
	double novoX;

	for(i = 0; i < n; i++) {
		novoX = ((b - a) * x[i] + b + a) / 2;
		resultado += f(novoX);
	}

	resultado *= (b - a) / 2;

	return resultado;
}

static double simpson(double (*f) (double), double a, double b, int n)
{
	double soma = 0;
	double h = (b - a) / n;
	double ini, fim, medio;

	for(int i = 0; i < n; i++) {
		ini = a + (i * h);
		fim = ini + h;
		medio = (ini + fim) / 2;

		soma += h / 6 * (f(ini) + 4 * f(medio) + f(fim));
	}

	return soma;
}