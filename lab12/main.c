#include <stdio.h>
#include <math.h>
#include "matriz.h"
#include "gradconj.h"

int main()
{
	int repeticoes;


	double **A1 = matcria(2, 2);
	double *b1 = vetcria(2);
	double *x1 = vetcria(2);

	double **A2 = matcria(6, 6);
	double *b2 = vetcria(6);
	double *x2 = vetcria(6);

	A1[0][0] = 3;
	A1[0][1] = 1;
	A1[1][0] = 1;
	A1[1][1] = 2;

	b1[0] = 5;
	b1[1] = 5;

	x1[0] = 0;
	x1[1] = 0;

	repeticoes = GradConj(2, A1, b1, x1, pow(10.0, -7));
	printf("solucao primeiro sistema: (numero de repeticoes = %d)\n", repeticoes);
	printf("x = [%.f, %.f]\n\n", x1[0], x1[1]);
	
	x1[0] = 0;
	x2[0] = 0;

	repeticoes = GradConjJacobi(2, A1, b1, x1, pow(10.0, -7));
	printf("solucao primeiro sistema com pre-condicionador: (numero de repeticoes = %d)\n", repeticoes);
	printf("x = [%.f, %.f]\n\n", x1[0], x1[1]);

	
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

	b2[0] = 2.5;
	b2[1] = 1.5;
	b2[2] = 1;
	b2[3] = 1;
	b2[4] = 1.5;
	b2[5] =	2.5;

	x2[0] = 1.5;
	x2[1] = 1.5;
	x2[2] = 1.5;
	x2[3] = 1.5;
	x2[4] = 1.5;
	x2[5] = 1.5;
	
	repeticoes = GradConj(6, A2, b2, x2, pow(10.0, -7));
	printf("solucao segundo sistema: (numero de repeticoes = %d)\n", repeticoes);
	printf("x = [%.f, %.f, %.f, %.f, %.f, %.f]\n\n", x2[0], x2[1], x2[2], x2[3], x2[4], x2[5]);

	x2[0] = 0;
	x2[1] = 0;
	x2[2] = 0;
	x2[3] = 0;
	x2[4] = 0;
	x2[5] = 0;

	repeticoes = GradConjJacobi(6, A2, b2, x2, pow(10.0, -7));
	printf("solucao segundo sistema com pre-condicionador: (numero de repeticoes = %d)\n", repeticoes);
	printf("x = [%.f, %.f, %.f, %.f, %.f, %.f]\n\n", x2[0], x2[1], x2[2], x2[3], x2[4], x2[5]);

	return 0;
}
