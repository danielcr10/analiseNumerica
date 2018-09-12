#include "sistlinear.h"
#include "matriz.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double **eliminacaoDeGauss(int n, double **matriz, int *permutacao);
static void initVetorPermutacao(int *vetor, int n);
static void pivotamento(int n, double **matriz, int j, int *permutacao);
static void matinit(double **A, int m, int n);
static void matsoma(double **A, double **B, int m, int n);

void fatoracao(int n, double** A, int* p)
{
	int *permutacao = (int *) malloc(n * sizeof(int));
	if(permutacao == NULL) {
		printf("Falta memoria. \n");
		exit(1);
	}

	initVetorPermutacao(permutacao, n);

	double **f = eliminacaoDeGauss(n, A, permutacao);
	matsoma(f, A, n, n);

	for(int i = 0; i < n; i++)
		p[i] = permutacao[i];
}

void substituicao(int n, double** A, int* p, double* b, double* x)
{
	int i, j;

	double soma;

	double v[n];

	for(i = 0; i < n; i++) {
		soma = 0;
		for(j = 0; j < i; j++) {
			soma += A[i][j] * v[j];
		}

		v[i] = b[p[i]] - soma; 
	}

	for(i = n - 1; i >= 0; i--) {
		soma = 0;
		for(j = i + 1; j < n; j++) {
			soma += A[i][j] * x[j];
		}
		x[i] = (v[i] - soma) / A[i][i];
	}
}

static double **eliminacaoDeGauss(int n, double **matriz, int *permutacao)
{
	int i, j, k, linha;
	double fator;
	double **f = matcria(n, n);
	matinit(f, n, n);

	for(j = 0; j < n-1; j++) {
		pivotamento(n, matriz, j, permutacao);

		for(i = j+1; i < n; i++) {
			if(matriz[i][j] == 0) {
				continue;
			}
			fator = matriz[i][j] / matriz[j][j];
			for(k = j; k < n; k++) {
				matriz[i][k] -= fator * matriz[j][k];
			}
			f[i][j] = fator;
		}
	}

	return f;
}

static void pivotamento(int n, double **matriz, int j, int *permutacao)
{
	int i, aux;
	int maior = j;
	double *auxLinha;

	for(i = j + 1; i < n; i++) {
		if(fabs(matriz[i][j]) > fabs(matriz[maior][j])) {
			maior = i;
		}
	}

	auxLinha = matriz[j];
	matriz[j] = matriz[maior];
	matriz[maior] = auxLinha;

	aux = permutacao[j];
	permutacao[j] = permutacao[maior];
	permutacao[maior] = aux;
}

static void initVetorPermutacao(int *vetor, int n)
{
	int i;
	for(i = 0; i < n; i++) {
		vetor[i] = i;
	}
}

static void matinit(double **A, int m, int n)
{
	int i, j;
	for(i = 0; i < m; i++) {
		for(j = 0; j < n; j++) {
			A[i][j] = 0;
		}
	}
}

static void matsoma(double **A, double **B, int m, int n)
{
	int i, j;
	for(i = 0; i < m; i++) {
		for(j = 0; j < n; j++) {
			B[i][j] += A[i][j];
		}
	}
}
