#include <string.h>
#include <math.h>
#include "gradconj.h"
#include "matriz.h"

static void vetsoma(int n, double *v, double *w, double *r);
static void vetdif(int n, double *v, double *w, double *r);
static void produtovetporescalar(int n, double escalar, double *v, double *r);
static double **matrizDiagonalInversa(int n, double **A);
static void inicializaMatriz(int n, int m, double **A);
static double vetnorma2(int n, double* v);
static double escalar(int n, double* v, double* w);

int GradConj(int n, double** A, double* b, double* x, double tol)
{
	int i;
	const int max = 100;
	double *r = vetcria(n);
	double *d = vetcria(n);
	double alpha;
	double beta;

	double *v = vetcria(n);
	double *w = vetcria(n);
	double *prox_r = vetcria(n);

	multmv(n, n, A, x, v);
	vetdif(n, b, v, r);
	memcpy(d, r, sizeof(double) * n);
	for(i = 0; i < max && vetnorma2(n, r) > tol; i++) {
		multmv(n, n, A, d, v);
		alpha = escalar(n, r, r) / escalar(n, d, v);
		produtovetporescalar(n, alpha, d, w);
		vetsoma(n, x, w, x);
		produtovetporescalar(n, alpha, v, w);
		vetdif(n, r, w, prox_r);
		beta = escalar(n, prox_r, prox_r) / escalar(n, r, r);
		produtovetporescalar(n, beta, d, w);
		vetsoma(n, prox_r, w, d);
		r = prox_r;
	}

	return i;
}

int GradConjJacobi(int n, double** A, double* b, double* x, double tol) {
	int i;
	const int max = 100;
	double **MInversa = matrizDiagonalInversa(n, A);
	double *r = vetcria(n);
	double *z = vetcria(n);
	double *d = vetcria(n);
	double alpha;
	double beta;

	double *v = vetcria(n);
	double *w = vetcria(n);
	double *prox_r = vetcria(n);
	double *prox_z = vetcria(n);

	multmv(n, n, A, x, v);
	vetdif(n, b, v, r);
	multmv(n, n, MInversa, r, z);
	memcpy(d, z, sizeof(double) * n);
	for(i = 0; i < max && vetnorma2(n, r) > tol; i++) {
		multmv(n, n, A, d, v);
		alpha = escalar(n, r, z) / escalar(n, d, v);
		produtovetporescalar(n, alpha, d, w);
		vetsoma(n, x, w, x);
		produtovetporescalar(n, alpha, v, w);
		vetdif(n, r, w, prox_r);
		multmv(n, n, MInversa, prox_r, prox_z);
		beta = escalar(n, prox_r, prox_z) / escalar(n, r, z);
		produtovetporescalar(n, beta, d, w);
		vetsoma(n, prox_z, w, d);
		r = prox_r;
		z = prox_z;
	}

	return i;
}

static void vetsoma(int n, double *v, double *w, double *r) {
	int i;
	for(i = 0; i < n; i++) {
		r[i] = v[i] + w[i];
	}
}

static void vetdif(int n, double *v, double *w, double *r)
{
	int i;
	for(i = 0; i < n; i++) {
		r[i] = v[i] - w[i];
	}
}

static void produtovetporescalar(int n, double escalar, double *v, double *r) {
	int i;
	for(i = 0; i < n; i++) {
		r[i] = escalar * v[i];
	}
}

static double **matrizDiagonalInversa(int n, double **A) {
	int i;
	double **D = matcria(n, n);
	inicializaMatriz(n, n, D);
	for(i = 0; i < n; i++) {
		D[i][i] = 1 / A[i][i];
	}

	return D;
}

static void inicializaMatriz(int n, int m, double **A) {
	int i, j;
	for(i = 0; i < n; i ++) {
		for(j = 0; j < m; j++) {
			A[i][i] = 0;
		}
	}
}

static double vetnorma2(int n, double* v){

	int i;
	double somatorio = 0;
	for(i = 0; i < n; i++) {
		somatorio += pow(v[i], 2);
	}

	return sqrt(somatorio);
}

static double escalar(int n, double* v, double* w){

	int i;
	double produtoEscalar = 0;
	for(i = 0; i < n; i++) {
		produtoEscalar += v[i] * w[i];
	}

	return produtoEscalar;
}