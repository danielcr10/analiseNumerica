#ifndef _SPARSE_H
#define _SPARSE_H

#include "list.h"

struct matrix {
   list *linha;
   size_t len;
};

struct matrix *reduceRep (int n, int m, double **M);
void setValue (int linha,int coluna,struct matrix *M,double value);
list *getValue (int linha, int coluna, struct matrix *M);
int gradienteConjugado (int n, struct matrix* A, double* b, double* x, double tol);
int gcJacobi (int n, struct matrix* A, double* b, double* x, double tol);
int gcSSOR (int n, struct matrix* A, double* b, double* x, double tol,double w);

#endif