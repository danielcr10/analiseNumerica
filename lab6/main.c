//matcria
#include <stdio.h>
#include "matriz.h"
#include "qr.h"

int main()
{
	double erro;
	//Teste 1
	double **A = matcria(5, 3);
	A[0][0] = 3;
	A[0][1] = -1;
	A[0][2] = 2;
	A[1][0] = 4;
	A[1][1] = 1;
	A[1][2] = 0;
	A[2][0] = -3;
	A[2][1] = 2;
	A[2][2] = 1;
	A[3][0] = 1;
	A[3][1] = 1;
	A[3][2] = 5;
	A[4][0] = -2;
	A[4][1] = 0;
	A[4][2] = 3;

	double *b = vetcria(5);
	b[0] = 10;
	b[1] = 10;
	b[2] = -5;
	b[3] = 15;
	b[4] = 0;


	double *sol = vetcria(3);
	double x = mmqQR(5, 3, A, b, sol);
}