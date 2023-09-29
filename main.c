#include <stdio.h>
#include <stdlib.h>
#include "gcofo.h"

//Nome do aluno: Therlyson Ryan Souza Santos

int main(){
    gCofo *gcofo;
    int tamanho_max;
    int opcao = 1;
    
    while(opcao!=0){
        printf("\n\t========= Menu =========\n");
        printf("1 - Criar cofo\n");
        printf("2 - Inserir produto no cofo\n");
        printf("3 - Consultar produto no cofo\n");
        printf("4 - Listar produtos do cofo\n");
        printf("5 - Remover produto do cofo\n");
        printf("6 - Esvaziar cofo\n");
        printf("7 - Destruir cofo\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        if(opcao == 1){
            printf("Digite o tamanho maximo do seu cofo: ");
            scanf("%d", &tamanho_max);
            gcofo = gcofCreate(tamanho_max);
            if(gcofo == NULL){
                printf("ERRO AO CRIAR COFO");
            }
            else{
                printf("Cofo criado com sucesso!\n");
            }
        }

        else if(opcao == 2){
            Produto *novo_produto = (Produto *)malloc(sizeof(Produto));
            if (novo_produto == NULL) {
                printf("ERRO DE ALOCAÇÃO!");
            } else {
                printf("Digite o nome do produto: ");
                scanf("%s", novo_produto->nome);
                printf("Digite a quantidade do produto: ");
                scanf("%d", &(novo_produto->quantidade));
                printf("Digite o preco do produto: ");
                scanf("%f", &(novo_produto->preco));
                if(insereProduto(gcofo, novo_produto)){
                    printf("Produto inserido com sucesso!\n");
                } else {
                    free(novo_produto);
                    printf("ERRO AO INSERIR PRODUTO\n");
                }
            }
        }

        else if(opcao == 3){
            char nome[30];
            printf("Digite o nome do produto que deseja consultar: ");
            scanf("%s", nome);
            Produto *produto = consultaProduto(gcofo, nome);
            if(produto != NULL){
                printf("Produto encontrado:\n");
                printf("Nome: %s\n", produto->nome);
                printf("Quantidade: %d\n", produto->quantidade);
                printf("Preco: %.2f\n", produto->preco);
            }
            else{
                printf("Produto nao encontrado.\n");
            }
        }

        else if (opcao == 4) {
            Produto *elemento;
            for (int i = 0; i < getQtdItens(gcofo); i++) { 
                elemento = (Produto*)elementsCof(gcofo, i);
                if (elemento == NULL) {
                    printf("ERRO AO MOSTRAR LISTA!");
                } else {
                    printf("Nome: %s\nQuantidade: %d\nPreco: %.2f\n\n", elemento->nome, elemento->quantidade, elemento->preco);
                }
            }
            printf("\n");      
        } 

        else if(opcao == 5){
            char nome[30];
            printf("Digite o nome do produto que deseja remover: ");
            scanf("%s", nome);
            Produto *produto = removeProduto(gcofo, nome);
            if(produto != NULL){
                printf("Produto removido com sucesso:\n");
                printf("Nome: %s\n", produto->nome);
                printf("Quantidade: %d\n", produto->quantidade);
                printf("Preco: %.2f\n", produto->preco);
                free(produto);
            }
            else{
                printf("Produto nao encontrado.\n");
            }
        }

        else if(opcao == 6){
            int drain = drainOutCof(gcofo);
            if(drain == 0){
                printf("ERRO AO ESVAZIAR COFO!");
            }
            else{
                printf("Cofo vazio!\n");
            }
        }

        else if(opcao == 7){
            int destroy = colDestroy(gcofo);
            if(destroy == 0){
                printf("ERRO AO DESTRUIR COFO, ESVAZIE PRIMEIRO!");
            }
            else{
                printf("Cofo DESTRUIDO!\n");
            }
            
        }

        else if(opcao == 0){
            printf("PROGRAMA ENCERRADO COM SUCESSO!\n");
            break;
        }
        
        else{
            printf("Voce digitou uma opcaoo invalida!\n");
        }
    } 
}