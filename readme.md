# Trabalho de Implementação 02 - TAD cofo genérico - Estrutura de Dados 1

## IDE UTILIZADA: Visual Studio Code

## Aluno: Therlyson Ryan Souza Santos

## TAD - Introdução

Este código em C tem o objetivo de implementar um TAD Cofo, uma estrutura que permite armazenar e manipular uma coleção de itens de forma genérica. O TAD Cofo oferece operações para inserção, consulta, remoção, entre outras funcionalidades.

O código é organizado em três arquivos principais: `gcofo.h`, `gcofo.c` e `main.c`:

- `gcofo.h`: Contém os protótipos das funções e a estruturas utilizada no TAD Cofo.

- `gcofo.c`: Implementa as operações do TAD Cofo, seguindo os protótipos definidos em `gcofo.h`.

- `main.c`: Apresenta uma interface de linha de comando para interagir com o TAD Cofo, permitindo criar, inserir, consultar, listar, remover, esvaziar e destruir um Cofo.

Os arquivos `gcofo.o` e `app.exe` são os arquivos objeto e executável, respectivamente, necessários para executar o programa.

## Funcionalidades:

1. **gcofCreate**:
   - *Descrição*: Cria um novo Cofo com um número máximo de itens especificado.
   - *Parâmetros*:
     - `max_itens`: Número máximo de itens que o Cofo pode armazenar.
   - *Retorno*:
     - `gCofo *`: Um ponteiro para a estrutura do Cofo criada, ou NULL em caso de falha.

2. **elementsCof**:
   - *Descrição*: Obtém um elemento específico do Cofo com base em sua posição.
   - *Parâmetros*:
     - `c`: Um ponteiro para a estrutura do Cofo.
     - `pos`: A posição do elemento desejado no Cofo.
   - *Retorno*:
     - `void *`: Um ponteiro para o elemento na posição especificada, ou NULL se a posição for inválida.

3. **drainOutCof**:
   - *Descrição*: Remove todos os itens do Cofo, liberando a memória associada a cada elemento.
   - *Parâmetros*:
     - `c`: Um ponteiro para a estrutura do Cofo.
   - *Retorno*:
     - `int`: Retorna 1 se a operação foi bem-sucedida (Cofo esvaziado) ou 0 caso contrário.

4. **colDestroy**:
   - *Descrição*: Libera a memória associada ao Cofo, incluindo seus elementos.
   - *Parâmetros*:
     - `c`: Um ponteiro para a estrutura do Cofo.
   - *Retorno*:
     - `int`: Retorna 1 se a operação foi bem-sucedida (Cofo destruído) ou 0 caso contrário.

5. **getQtdItens**:
   - *Descrição*: Obtém a quantidade atual de itens no Cofo.
   - *Parâmetros*:
     - `gc`: Um ponteiro para a estrutura do Cofo.
   - *Retorno*:
     - `int`: A quantidade atual de itens no Cofo.

6. **insereProduto**:
   - *Descrição*: Insere um produto no Cofo.
   - *Parâmetros*:
     - `gc`: Um ponteiro para a estrutura do Cofo.
     - `produto`: Um ponteiro para a estrutura do Produto a ser inserido.
   - *Retorno*:
     - `int`: Retorna 1 se o produto foi inserido com sucesso no Cofo, ou 0 caso contrário.

7. **consultaProduto**:
   - *Descrição*: Consulta um produto no Cofo com base no nome.
   - *Parâmetros*:
     - `gc`: Um ponteiro para a estrutura do Cofo.
     - `nome`: O nome do produto a ser consultado.
   - *Retorno*:
     - `Produto *`: Um ponteiro para a estrutura do Produto encontrado, ou NULL se o produto não foi encontrado.

8. **removeProduto**:
   - *Descrição*: Remove um produto do Cofo com base no nome.
   - *Parâmetros*:
     - `gc`: Um ponteiro para a estrutura do Cofo.
     - `nome`: O nome do produto a ser removido.
   - *Retorno*:
     - `Produto *`: Um ponteiro para a estrutura do Produto removido, ou NULL se o produto não foi encontrado.

## Como executar o programa no Visual Studio Code:

1. Para o programa ser executado, basta criar uma pasta no PC e adicionar todos os arquivos na mesma pasta (`main.c`, `gcofo.c`, `gcofo.h`, `gcofo.o`, `app.exe`)

2. Após isso abre o Visual Studio Code -> File -> open Folder, abri a pasta que tá os arquivos.

3. Logo após basta ir no Terminal -> new terminal, no terminal digite: `./app`

4. Pronto, agora o programa está funcionando corretamente.


## Estrutura Produto

```c
typedef struct produto {
    char nome[30];
    int quantidade;
    float preco;
} Produto;