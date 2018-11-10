#include <stdio.h>
#include <math.h>
#include "metiter.h"
#include "matriz.h"

void vetimprime(int n, double* v, char* format);

int main()
{
	double **A = matcria(2, 2);	
	A[0][0] = 3;
	A[0][1] = 1;
	A[1][0] = 1;
	A[1][1] = 2;


	double *b = vetcria(2);
	b[0] = 5;
	b[1] = 5;

	double *x = vetcria(2);
	x[0] = 0;
	x[1] = 0;

	double tol = pow(10, -7);
	printf("\n\nJacobi: \n");
	Jacobi(2, A, b, x, tol);
	vetimprime(2, x, "%.4f");
	x[0] = 0;
	x[1] = 0;
	printf("\n\nSeidel: \n");
	GaussSeidel(2, A, b, x, tol);
	vetimprime(2, x, "%.4f");
	x[0] = 0;
	x[1] = 0;
	printf("\n\nSeidel com sobre-relaxamento: \n");
	SOR(2, A, b, x, tol, 1.1);
	vetimprime(2, x, "%.4f");

	double **A2 = matcria(6, 6);
	A2[0][0] = 3;
	A2[0][1] = -1; 
	A2[0][2] = 0;
	A2[0][3] = 0;
	A2[0][4] = 0;
	A2[0][5] = 0.5;
	A2[1][0] = -1;
	A2[1][1] = 3;
	A2[1][2] = -1;
	A2[1][3] = 0;
	A2[1][4] = 0.5;
	A2[1][5] = 0;
	A2[2][0] = 0;
	A2[2][1] = -1;
	A2[2][2] = 3;
	A2[2][3] = -1;
	A2[2][4] = 0;
	A2[2][5] = 0;
	A2[3][0] = 0;
	A2[3][1] = 0;
	A2[3][2] = -1;
	A2[3][3] = 3;
	A2[3][4] = -1;
	A2[3][5] = 0;
	A2[4][0] = 0;
	A2[4][1] = 0.5;
	A2[4][2] = 0;
	A2[4][3] = -1;
	A2[4][4] = 3;
	A2[4][5] = -1;
	A2[5][0] = 0.5;
	A2[5][1] = 0;
	A2[5][2] = 0;
	A2[5][3] = 0;
	A2[5][4] = -1;
	A2[5][5] = 3;
	
	double *b2 = vetcria(6);
	b2[0] = 2.5;
	b2[1] = 1.5;
	b2[2] = 1;
	b2[3] = 1;
	b2[4] = 1.5;
	b2[5] = 2.5;

	double *x2 = vetcria(6);
	x2[0] = 0;
	x2[1] = 0;
	x2[2] = 0;
	x2[3] = 0;
	x2[4] = 0;
	x2[5] = 0;

	printf("\n\nJacobi: \n");
	Jacobi(6, A2, b2, x2, tol);
	vetimprime(6, x2, "%.4f");
	x2[0] = 0;
	x2[1] = 0;
	x2[2] = 0;
	x2[3] = 0;
	x2[4] = 0;
	x2[5] = 0;
	printf("\n\nSeidel: \n");
	GaussSeidel(6, A2, b2, x2, tol);
	vetimprime(6, x2, "%.4f");
	x2[0] = 0;
	x2[1] = 0;
	x2[2] = 0;
	x2[3] = 0;
	x2[4] = 0;
	x2[5] = 0;
	printf("\n\nSeidel com sobre-relaxamento: \n");
	SOR(6, A2, b2, x2, tol, 1.1);
	vetimprime(6, x2, "%.4f");

	return 0;
}

void vetimprime(int n, double* v, char* format)
{
	int i;
	for(i = 0; i < n; i++) {
		printf(format, v[i]);
		printf("\t");
	}
}