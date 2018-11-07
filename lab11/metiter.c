#include <stdio.h>
#include "matriz.h"

int Jacobi (int n, double** A, double* b, double* x, double tol){
  double** L = matcria (int n, int n);
  double** D = matcria (int n, int n);
  double** U = matcria (int n, int n);
  
  decompoeMatriz(A, L, D, U);
}

int GaussSeidel (int n, double** A, double* b, double* x, double tol){

}

int SOR (int n, double** A, double* b, double* x, double tol, double w){

}

void decompoeMatriz(double** A, double** L, double** D, double** u){
double** matcria (int m, int n)
}
