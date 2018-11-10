#include <string.h>
#include <math.h>
#include "metiter.h"
#include "matriz.h"


static void obtemLU(double **A, double **D, double **C, int n); 
static void matrizDiagonal(double **A, double **D, int n);
static void inicializaMatriz(double **A, int n, double valor);
static void matrizDiagonalInversa(double **D, int n);
static void vetorDiferenca(double *v1, double *v2, double *resultado, int n);
static void obtemL(double **A, double **L, int n);
static void obtemU(double **A, double **U, int n);
static double vetnorma2(int n, double* v);
static void matsoma(double **A, double **B, int m, int n);

int Jacobi(int n, double** A, double* b, double* x, double tol) {
	double **D = matcria(n , n);
	double **LU = matcria(n, n);
	double *ultima = vetcria(n);
	double *vetorDif = vetcria(n);
	double *aux = vetcria(n);
	double *aux2 = vetcria(n);
	int i = 0;

	matrizDiagonal(A, D, n);

	// Obtem L + U
	obtemLU(A, D, LU, n);

	matrizDiagonalInversa(D, n);

	do {
		memcpy(ultima, x, sizeof(double) * n);

		multmv(n, n, LU, ultima, aux);
		vetorDiferenca(b, aux, aux2, n); 
		multmv(n, n, D, aux2, x);

		vetorDiferenca(x, ultima, vetorDif, n);
		i++;
	} while(vetnorma2(n, vetorDif) > tol);

	return i;
}

int GaussSeidel(int n, double** A, double* b, double* x, double tol) {
	double **D = matcria(n , n);
	double **L = matcria(n, n);
	double **U = matcria(n, n);
	double *ultima = vetcria(n);
	double *vetorDif = vetcria(n);
	double *aux = vetcria(n);
	double *aux2 = vetcria(n);
	double *aux3 = vetcria(n);
	int i = 0;
	obtemL(A, L, n);
	obtemU(A, U, n);

	matrizDiagonal(A, D, n);

	matrizDiagonalInversa(D, n);

	do {
		memcpy(ultima, x, sizeof(double) * n);


		multmv(n, n, L, x, aux);

		multmv(n, n, U, ultima, aux2);

		vetorDiferenca(aux, aux2, aux3, n);

		vetorDiferenca(b, aux3, aux, n);
		multmv(n, n, D, aux, x);

		vetorDiferenca(x, ultima, vetorDif, n);
		i++;
	} while(vetnorma2(n, vetorDif) > tol);

	return i;
}

int SOR (int n, double** A, double* b, double* x, double tol, double w) {
	double **D = matcria(n , n);
	double **L = matcria(n, n);
	double **U = matcria(n, n);
	double *ultima = vetcria(n);
	double *vetorDif = vetcria(n);
	double *aux = vetcria(n);
	double *aux2 = vetcria(n);
	double *aux3 = vetcria(n);
	int r = 0;
	int i;
	obtemL(A, L, n);
	obtemU(A, U, n);

	matrizDiagonal(A, D, n);

	matrizDiagonalInversa(D, n);

	do {
		memcpy(ultima, x, sizeof(double) * n);


		multmv(n, n, L, x, aux);

		multmv(n, n, U, ultima, aux2);
 
		vetorDiferenca(aux, aux2, aux3, n);

		vetorDiferenca(b, aux3, aux, n);
		multmv(n, n, D, aux, x);

		// sobre-relaxamento
		for(i = 0; i < n; i++) {
			x[i] = (1 - w) * ultima[i] + w * x[i];
		}

		vetorDiferenca(x, ultima, vetorDif, n);
		r++;
	} while(vetnorma2(n, vetorDif) > tol);

	return r;
}

static void matrizDiagonal(double **A, double **D, int n) {
	int i;
	inicializaMatriz(D, n, 0);
	for(i = 0; i < n; i++) {
		D[i][i] = A[i][i];
	}
}

static void matrizDiagonalInversa(double **D, int n) {
	int i;
	for(i = 0; i < n; i++) {
		D[i][i] = 1 / D[i][i];
	}
}

static void inicializaMatriz(double **A, int n, double valor) {
	int i, j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			A[i][j] = 0;
		}
	}
}

static void obtemL(double **A, double **L, int n) {
	int i, j;
	inicializaMatriz(L, n, 0);
	for(i = 0; i < n; i++) {
		for(j = 0; j < i; j++) {
			L[i][j] = A[i][j];
		}
	}
}

static void obtemU(double **A, double **U, int n) {
	int i, j;
	inicializaMatriz(U, n, 0);
	for(i = 0; i < n; i++) {
		for(j = i + 1; j < n; j++) {
			U[i][j] = A[i][j];
		}
	}
}

static void obtemLU(double **A, double **D, double **C, int n) {
	double **aux = matcria(n, n);
	int i;
	inicializaMatriz(aux, n, 0);
	
	for(i = 0; i < n; i++) {
		aux[i][i] = -1;
	}
	multmm(n, n, n, D, aux, C);
	matsoma(A, C, n, n);
}

static void vetorDiferenca(double *v1, double *v2, double *resultado, int n) {	
	int i;
	for(i = 0; i < n; i++) {
		resultado[i] = v1[i] - v2[i];
	}
}

static double vetnorma2(int n, double* v)
{
	int i;
	double somatorio = 0;
	for(i = 0; i < n; i++) {
		somatorio += pow(v[i], 2);
	}

	return sqrt(somatorio);
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
