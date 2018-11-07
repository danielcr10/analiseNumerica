#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vetmat.h"
 
double* vetcria(int n)
{
    double *vetor = (double *) malloc(n * sizeof(double));
    if(vetor == NULL) {
        printf("Memory allocation error. \n");
        exit(-1);
    }
 
    return vetor;
}
 
void vetlibera(double* v)
{
    free(v);
}
 
double escalar(int n, double* v, double* w)
{
    int i;
    double produtoEscalar = 0;
    for(i = 0; i < n; i++) {
        produtoEscalar += v[i] * w[i];
    }
 
    return produtoEscalar;
}
 
double norma2(int n, double* v)
{
    int i;
    double somatorio = 0;
    for(i = 0; i < n; i++) {
        somatorio += pow(v[i], 2);
    }
 
    return sqrt(somatorio);
}
 
int vetiguais(int n, double* v, double* w, double tol)
{
    int i;
    for(i = 0; i < n; i++) {
        if(fabs(v[i] - w[i]) > tol) {
            return 0;
        }
    }
 
    return 1;
}
 
void vetimprime(int n, double* v, char* format)
{
    int i;
    for(i = 0; i < n; i++) {
        printf(format, v[i]);
        printf("\n");
    }
}
 
double** matcria(int m, int n)
{
    int i;
    double **matriz = (double **) malloc(m * sizeof(double*));
    if(matriz == NULL) {
        printf("Memory allocation error. \n");
        exit(-1);
    }
 
    for(i = 0; i < m; i++) {
        matriz[i] = (double *) malloc(n * sizeof(double));
        if(matriz[i] == NULL) {
            printf("Memory allocation error. \n");
            exit(-1);
        }
    }
 
    return matriz;
}
 
void matlibera(int m, double** A)
{
    int i;
    for(i = 0; i < m; i++) {
        free(A[i]);
    }
 
    free(A);
}
 
void transposta(int m, int n, double** A, double** T)
{
    int i, j;
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            T[j][i] = A[i][j];
        }
    }
}
 
void multmv(int m, int n, double** A, double* v, double* w)
{
    int i;
    for(i = 0; i < m; i++) {
        w[i] = escalar(n, A[i], v);
    }
}
 
void multmm(int m, int n, int q, double** A, double** B, double** C)
{
    int i, j;
    double **fatorColuna = matcria(m, n);
    transposta(m, n, B, fatorColuna);
    for(i = 0; i < m; i++) {
        for(j = 0; j < q; j++) {
            C[i][j] = escalar(n, A[i], fatorColuna[j]);
        }
    }
 
    matlibera(m, fatorColuna);
}
 
int matiguais(int m, int n, double** A, double** B, double tol)
{
    int i, j;
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            if(fabs(A[i][j] - B[i][j]) > tol) {
                return 0;
            }
        }
    }
 
    return 1;
}
 
void matimprime(int m, int n, double** A, char* format)
{
    int i, j;
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf(format, A[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}
