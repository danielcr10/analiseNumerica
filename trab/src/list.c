#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "util.h"
#include "list.h"

list *list_cria(void)
{
   list *ret;

   ret = myrealloc(NULL, sizeof(list));

   ret->next = NULL;
   ret->prev = NULL;
   ret->coluna = -1;
   ret->value = 0.0;

   return ret;
}

void list_destroi(list *l)
{
   list *p;

   while (l) {
      p = l;
      l = l->next;
      free(p);
   }
}

void list_insere(list *l, int coluna, double value)
{
   if (l->coluna == -1) {
      l->coluna = coluna;
      l->value = value;
   } else {
      while (l) {
         if (l->coluna > coluna) {
            list *next = myrealloc(NULL, sizeof(list));
            next->coluna = coluna;
            next->value = value;
            if (l->prev) {
               next->prev = l->prev;
               l->prev->next = next;
            } else {
               next->prev = NULL;
            }
            next->next = l;
            return;
         }
         if (l->next == NULL) {
            list *next = myrealloc(NULL, sizeof(list));
            next->next = NULL;
            next->prev = l;
            next->coluna = coluna;
            next->value = value;
            l->next = next;
            return;
         }
         l = l->next;
      }
   }
}

void list_remove(list *l, int coluna)
{
   list *p;

   while (l) {
      if (l->coluna == coluna) {
         if (!l->prev && !l->next) {
            l->coluna = -1;
            l->value = 0;
            return;
         }
         if (l->prev) {
            l->prev->next = l->next;
         }
         if (l->next) {
            l->next->prev = l->prev;
         }
         p = l;
         l = l->next;
         free(p);
         return;
      }
      l = l->next;
   }
}

void list_setValue(list *l, int idx, double v)
{
   while (l) {
      if (l->coluna == idx) {
         l->value = v;
         return;
      }
      l = l->next;
   }
}

int list_getColuna(list *l, int idx)
{
   while (l) {
      if (l->coluna == idx)
         return idx;
      l = l->next;
   }

   return -1;
}

double list_getValue(list *l, int idx)
{
   while (l) {
      if (l->coluna == idx)
         return l->value;
      l = l->next;
   }

   return -1.0;
}
