#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "interp.h"

double f(double x)
{
	return cos(x);
}

int main()
{
	int n = 6;
	double aval;
	double *xi = (double *) malloc(n * sizeof(double));
	double *bi = (double *) malloc(n * sizeof(double));

	if(xi == NULL) {
		printf("Falta memoria. \n");
		exit(1);
	}
	if(bi == NULL) {
		printf("Falta memoria. \n");
		exit(1);
	}

	chebyshev (n, 0, pi/2, xi);

	printf("\n\n");
	newtonCoef (n, xi, &f, bi);

	for (int i = 0; i < n; i++)
	{
		printf("%f\n", bi[i]);
	}
	
	aval = newtonAval (n, xi, bi, pi/4);
	printf("\n\n%.15f\n", aval);
	printf("%.15f\n", cos(M_PI/4));

	return 0;
}
