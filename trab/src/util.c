#include <stdlib.h>
#include <stdio.h>

#include "util.h"
#include "matriz.h"

void *myrealloc(void *ptr, size_t newsz)
{
   void *ret;

   if ((ret = realloc(ptr, newsz)) == NULL) {
      fprintf(stderr, "memory error\n");
   }

   return ret;
}

double **geraNULL(int n, int m)
{
   int i, j;

   double **ret = matcria(n, m);

   for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
         ret[i][j] = 0;

   return ret;
}
