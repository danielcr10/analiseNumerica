#include <stdio.h>

#include "sistlinear.h"
#include "matriz.h"

int main()
{
	double **matriz = matcria(6, 6);
	matriz[0][0] = 3;
	matriz[0][1] = -1;
	matriz[0][2] = 0;
	matriz[0][3] = 0;
	matriz[0][4] = 0;
	matriz[0][5] = 0.5;
	matriz[1][0] = -1;
	matriz[1][1] = 3;
	matriz[1][2] = -1;
	matriz[1][3] = 0;
	matriz[1][4] = 0.5;
	matriz[1][5] = 0;
	matriz[2][0] = 0;
	matriz[2][1] = -1;
	matriz[2][2] = 3;
	matriz[2][3] = -1;
	matriz[2][4] = 0;
	matriz[2][5] = 0;
	matriz[3][0] = 0;
	matriz[3][1] = 0;
	matriz[3][2] = -1;
	matriz[3][3] = 3;
	matriz[3][4] = -1;
	matriz[3][5] = 0;
	matriz[4][0] = 0;
	matriz[4][1] = 0.5;
	matriz[4][2] = 0;
	matriz[4][3] = -1;
	matriz[4][4] = 3;
	matriz[4][5] = -1;
	matriz[5][0] = 0.5;
	matriz[5][1] = 0;
	matriz[5][2] = 0;
	matriz[5][3] = 0;
	matriz[5][4] = -1;
	matriz[5][5] = 3;

	double b[] = {2.5, 1.5, 1, 1, 1.5, 2.5};

	int *p;
	fatoracao(6, matriz, p);

	double s[6];
	substituicao(6, matriz, p, b, s);
	printf("Solucao\n");
	for(int i = 0; i < 6; i++)
		printf("%f - ", s[i]);
	printf("\n");

	return 0;
}