//matcria
#include <stdio.h>
#include "matriz.h"
#include "sistlinear.h"
#include "mmq.h"

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
	MMQ(5, 3, A, b, sol);
	for(int i = 0; i < 3; i++) {
		printf("%f - ", sol[i]);
	}
	printf("\n");
//TODO:
	erro = RMSE(5, 3, A, b, sol);
	printf("Erro: %f \n", erro);

	matlibera(5, A);
	vetlibera(b);

	//Teste 2
	A = matcria(5, 4);
	A[0][0] = 4;
	A[0][1] = 2;
	A[0][2] = 3;
	A[0][3] = 0;
	A[1][0] = -2;
	A[1][1] = 3;
	A[1][2] = -1;
	A[1][3] = 1;
	A[2][0] = 1;
	A[2][1] = 3;
	A[2][2] = -4;
	A[2][3] = 2;
	A[3][0] = 1;
	A[3][1] = 0;
	A[3][2] = 1;
	A[3][3] = -1;
	A[4][0] = 3;
	A[4][1] = 1;
	A[4][2] = 3;
	A[4][3] = -2;

	b = vetcria(5);
	b[0] = 10;
	b[1] = 0;
	b[2] = 2;
	b[3] = 0;
	b[4] = 5;

	double *sol2 = vetcria(4);
	MMQ(5, 4, A, b, sol2);
	for(int i = 0; i < 4; i++) {
		printf("%.15f - ", sol2[i]);
	}
	printf("\n");

	erro = RMSE(5, 3, A, b, sol2);
	printf("Erro sistema 2: %f \n", erro);

	matlibera(5, A);
	vetlibera(b);

	return 0;
}



//matlibera
