#ifndef _GCOFO_H_
#define _GCOFO_H_

typedef struct gcofo {
    int numItens;
    int maxItens;
    int cur;
    void **item;
}gCofo;

typedef struct produto{
  char nome[30];
  int quantidade;
  float preco;
} Produto;

gCofo *gcofCreate( int max_itens );

void *elementsCof(gCofo *c, int pos);   // ver todos os elementos do cofo;

int drainOutCof(gCofo *c);  //esvaziar todos os elementos do cofo

int colDestroy(gCofo *c);

int getQtdItens(gCofo *gc);

int insereProduto(gCofo *gc, Produto *produto);

Produto *consultaProduto(gCofo *gc, char *nome);

Produto *removeProduto(gCofo *gc, char *nome);

#endif // _GCOFO_H_
