#include "util.h"
#include "sparse.h"
#include "matriz.h"
#include "cond.h"

struct matrix *Jacobi(int n, int m, struct matrix *M)
{
   int i, j;

   double **A = matcria(n, m);

   for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
         if (i == j) {
            list *aux = getValue(i, j, M);
            A[i][j] = aux -> value;
         } else {
            A[i][j] = 0;
         }
      }
   }

   return reduceRep(n, m, A);
}

struct matrix *SSOR(int n, int m, struct matrix *M, double w)
{
   int i, j;

   double **DwL = matcria(n, m), **D1 = matcria(n, m), **DwU = matcria(n, m);
   struct matrix *r1 = reduceRep(n, n, geraNULL(n, n));
   struct matrix *ret = reduceRep(n, n, geraNULL(n, n));

   list *d = NULL, *wl = NULL, *wu = NULL;
   double v1, v2, v3;

   for (i = 0; i < n; i++)
      for (j = 0; j < m; j++) {
         if (i == j)
            d = getValue(i, j, M);
         else if(i > j)
            wl = getValue(i, j, M);
         else
            wu = getValue(i, j, M);

         if (d) v1 = d -> value;
         else v1 = 0;

         if (wl) v2 = wl -> value;
         else v2 = 0;

         if (wu) v3 = wu -> value;
         else v3 = 0;

         DwL[i][j] = v1 + w * v2;
         D1[i][j] = 1/v1;
         DwU[i][j] = v1 + w * v3;

      }


   multmm(n, n, n, reduceRep(n,m,DwL), reduceRep(n,m,D1), r1);
   multmm(n, n, n, r1, reduceRep(n,m,DwU), ret);

   free(DwL);
   free(DwU);
   free(D1);

   return ret;
}
