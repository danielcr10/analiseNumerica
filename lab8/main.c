#include <stdio.h>
#include <math.h>
#include "simpson.h"

double f1(double x);
double f2(double x);
double f3(double x);

int main()
{
	double integral1, integral2, integral3;
	const double tol = 0.5 * pow(2, -7);
	integral1 = AdaptiveSimpson(0, 1, f1, tol);
	printf("integral1 (AdaptiveSimpson): %.10f\n", integral1);
	integral2 = AdaptiveSimpson(-1, 1, f2, tol);
	printf("integral2 (AdaptiveSimpson): %.10f\n", integral2);
	integral3 = AdaptiveSimpson(0, 3, f3, tol);
	printf("integral3 (AdaptiveSimpson): %.10f\n\n", integral3);


	integral1 = Quadratura2(0, 1, f1);
	printf("integral1 (Quadratura2): %f\n", integral1);
	integral2 = Quadratura2(-1, 1, f2);
	printf("integral2 (Quadratura2): %f\n", integral2);
	integral3 = Quadratura2(0, 3, f3);
	printf("integral3 (Quadratura2): %f\n\n", integral3);

	integral1 = Quadratura3(0, 1, f1);
	printf("integral1 (Quadratura3): %f\n", integral1);
	integral2 = Quadratura3(-1, 1, f2);
	printf("integral2 (Quadratura3): %f\n", integral2);
	integral3 = Quadratura3(0, 3, f3);
	printf("integral3 (Quadratura3): %f\n", integral3);

	return 0;
}

double f1(double x)
{
	return x / sqrt(pow(x, 2) + 9);
}

double f2(double x)
{
	return 1 / sqrt(2 * M_PI) * pow(M_E, -1 * pow(x, 2) / 2);
}

double f3(double x)
{
	return 2 / sqrt(M_PI) * pow(M_E, -1 * pow(x, 2));
}