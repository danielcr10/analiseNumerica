#include <math.h>
#include <stdio.h>
#include "ode.h"

double f(double t, double y);
double y(double t);

int c = 0;

int main (void)
{
	double yt1, erro;
	c = 0;
	printf("Com 0.01:\n\n");
	printf("Resultado Real: %lf\n\n", y(2.4));
	yt1 = Euler(0, 2.4, 0.01, -1, f);
	erro = fabs(yt1 - y(2.4))/yt1;
	printf("Resultado Euler: %lf\n", yt1);
	printf("Quantidade de avaliacoes: %d\n", c);

	c = 0;
	yt1 = EulerAdapt(0, 2.4, 0.01, -1, f, 0.1);
	printf("Erro relativo Euler: %lf\n", erro);
	erro = fabs(yt1 - y(2.4))/yt1;
	printf("Resultado Euler Adaptativo: %lf\n", yt1);
	printf("Quantidade de avaliacoes: %d\n", c);
	printf("Erro relativo Euler Adaptativo: %lf\n\n", erro);


	c = 0;
	printf("Com 0.001:\n\n");
	printf("Resultado Real: %lf\n\n", y(2.4));
	yt1 = Euler(0, 2.4, 0.001, -1, f);
	erro = fabs(yt1 - y(2.4))/yt1;
	printf("Resultado Euler: %lf\n", yt1);
	printf("Quantidade de avaliacoes: %d\n", c);
	printf("Erro relativo Euler: %lf\n", erro);

	c = 0;
	yt1 = EulerAdapt(0, 2.4, 0.001, -1, f, 0.001);
	erro = fabs(yt1 - y(2.4))/yt1;
	printf("Resultado Euler Adaptativo: %lf\n", yt1);
	printf("Quantidade de avaliacoes: %d\n", c);
	printf("Erro relativo Euler Adaptativo: %lf\n\n", erro);


	c = 0;
	printf("Com 0.0001:\n\n");
	printf("Resultado Real: %lf\n\n", y(2.4));
	yt1 = Euler(0, 2.4, 0.0001, -1, f);
	erro = fabs(yt1 - y(2.4))/yt1;
	printf("Resultado Euler: %lf\n", yt1);
	printf("Quantidade de avaliacoes: %d\n", c);
	printf("Erro relativo Euler: %lf\n", erro);

	c = 0;
	yt1 = EulerAdapt(0, 2.4, 0.0001, -1, f, 0.0001);
	erro = fabs(yt1 - y(2.4))/yt1;
	printf("Resultado Euler Adaptativo: %lf\n", yt1);
	printf("Quantidade de avaliacoes: %d\n", c);
	printf("Erro relativo Euler Adaptativo: %lf\n\n", erro);
}

double f(double t, double y)
{
	c++;
	return t * y + pow(t, 3);
}

double y(double t)
{
	return exp(pow(t, 2)/2) - pow(t, 2) - 2;
}
