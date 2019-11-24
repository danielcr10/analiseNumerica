#ifndef _LIST_H
#define _LIST_H

typedef struct _list list;

struct _list {
   list *next;
   list *prev;
   int coluna;
   double value;
};

list *list_cria(void);
void list_destroi(list *l);
void list_insere(list *l, int coluna, double value);
void list_remove(list *l, int coluna);
int list_getColuna(list *l, int idx);
double list_getValue(list *l, int idx);
void list_setValue(list *l, int idx, double value);

#endif