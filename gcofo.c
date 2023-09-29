#include "gcofo.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int insereProduto(gCofo *gc, Produto *produto) {
    if (gc != NULL && produto != NULL) {
        if (gc->numItens < gc->maxItens) {
            gc->item[gc->numItens] = produto;
            gc->numItens++;
            return 1;
        }
    }
    return 0;
}

Produto *consultaProduto(gCofo *gc, char *nome) {
    if (gc != NULL && nome != NULL) {
        if (gc->numItens > 0) {
            for (int i = 0; i < gc->numItens; i++) {
                Produto *produto = (Produto *)gc->item[i];
                if (strcmp(produto->nome, nome) == 0) {
                    return produto;
                }
            }
        }
    }
    return NULL;
}

Produto *removeProduto(gCofo *gc, char *nome) {
    int status = 0, i = 0;
    if (gc != NULL && nome != NULL) {
        if (gc->numItens > 0) {
            while (i < gc->numItens) {
                Produto *produto = (Produto *)gc->item[i];
                if (strcmp(produto->nome, nome) == 0) {
                    status = 1;
                    break;
                }
                i++;
            }
            if (status == 1) {
                Produto *removed_produto = (Produto *)gc->item[i];
                for (int j = i; j < gc->numItens - 1; j++) {
                    gc->item[j] = gc->item[j + 1];
                }
                gc->numItens--;
                return removed_produto;
            }
        }
    }
    return NULL;
}


void *elementsCof(gCofo *c, int pos) {
    void *data;
    if (c == NULL) {
        return NULL; 
    }
    if (c->numItens > 0 && pos < c->numItens) {
        data = c->item[pos];
        return data;
    }
    return NULL;  
}


gCofo *gcofCreate(int max_itens){ 
    gCofo *gc;
    if ( max_itens > 0) {
        gc = (gCofo *) malloc(sizeof(gCofo));
        if ( gc != NULL ) {
            gc->item = (void **) malloc (sizeof(void *)*max_itens);
            if ( gc->item != NULL) {
                gc->numItens = 0;
                gc->maxItens = max_itens;
                gc->cur = -1;
                return gc;
            }
        free(gc);
        }
    }
    return NULL;
}

int drainOutCof(gCofo *c){
    if(c!=NULL){
        while(c->numItens > 0){
            free(c->item[c->numItens-1]);   // Libera a memória do elemento
            c->numItens--;
        }
        return 1;
    }
    return 0;
}


int colDestroy(gCofo *gc){
    if(gc!=NULL){
        free(gc->item);  // Libera a memória dos elementos
        free(gc);
        return 1;
    }
    return 0;
}


int getQtdItens(gCofo *gc) {
     return gc->numItens;
}