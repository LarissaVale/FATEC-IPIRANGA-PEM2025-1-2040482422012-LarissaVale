/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Modularização de código de       *
* controle de estoque.                                   *
* Data - 15/03/2025                                      * 
* Autor: Larissa Vitória Nogueira do Vale                *
*--------------------------------------------------------*/

#include <stdio.h>

//Declaração das funções
void inicializarEstoque(char (*estoque)[10][6]);
void adicionarProduto(char (*estoque)[10][6]);
void buscarProduto(char (*estoque)[10][6]);
void removerProduto(char (*estoque)[10][6]);
void exibirMenu();

//Função principal
int main() {
    char estoque[3][10][6]; //Matriz para armazenar códigos dos produtos
    int menu = 0;

    inicializarEstoque(estoque);

    while (menu != 4) {
        exibirMenu();
        scanf("%d", &menu);

        if (menu == 1) {
            adicionarProduto(estoque);
        } else if (menu == 2) {
            buscarProduto(estoque);
        } else if (menu == 3) {
            removerProduto(estoque);
        } else if (menu == 4) {
            printf("\nSaindo do programa...\n");
        } else {
            printf("\nOpcao invalida! Tente novamente.\n");
        }
    }
    return 0;
}

//Função para inicializar o estoque
void inicializarEstoque(char (*estoque)[10][6]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 10; j++) {
            estoque[i][j][0] = '\0'; //Inicializa as gôndolas com vazio
        }
    }
}

//Função para adicionar um produto
void adicionarProduto(char (*estoque)[10][6]) {
    char codigo[6];
    int quantidade, i, j, k, encontrado = 0;

    printf("\nDigite o codigo do produto (Letra + 3 numeros, Ex: S123): ");
    scanf("%s", codigo);
    printf("\nDigite a quantidade de produtos a ser armazenada: ");
    scanf("%d", &quantidade);

    //Verifica se o produto já está armazenado em alguma gôndola
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 10; j++) {
            for (k = 0; k < 6; k++) {
                if (estoque[i][j][k] != codigo[k]) {
                    break;
                }
                if (codigo[k] == '\0') {
                    printf("\nErro! Produto %s ja armazenado na Rua %c, Gondola %d.\n", codigo, 'A' + i, j);
                    encontrado = 1;
                    break;
                }
            }
            if (encontrado) break;
        }
        if (encontrado) break;
    }

    if (!encontrado) {
        printf("\nProduto %s armazenado.\n", codigo);
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 10; j++) {
                if (estoque[i][j][0] == '\0') {
                    for (k = 0; k < 6; k++) {
                        estoque[i][j][k] = codigo[k];
                    }
                    break;
                }
            }
        }
    }
}

//Função para buscar um produto
void buscarProduto(char (*estoque)[10][6]) {
    char codigo[6];
    int i, j, k, encontrado = 0;

    printf("\nDigite o codigo do produto para busca: ");
    scanf("%s", codigo);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 10; j++) {
            for (k = 0; k < 6; k++) {
                if (estoque[i][j][k] != codigo[k]) {
                    break;
                }
                if (codigo[k] == '\0') {
                    printf("\nProduto encontrado na Rua %c, Gondola %d.\n", 'A' + i, j);
                    encontrado = 1;
                    break;
                }
            }
            if (encontrado) break;
        }
        if (encontrado) break;
    }

    if (!encontrado) {
        printf("\nProduto nao encontrado no estoque.\n");
    }
}

//Função para remover um produto
void removerProduto(char (*estoque)[10][6]) {
    char codigo[6];
    int i, j, k, encontrado = 0;

    printf("\nDigite o codigo do produto para remover: ");
    scanf("%s", codigo);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 10; j++) {
            for (k = 0; k < 6; k++) {
                if (estoque[i][j][k] != codigo[k]) {
                    break;
                }
                if (codigo[k] == '\0') {
                    estoque[i][j][0] = '\0'; // Remove o produto
                    printf("\nProduto %s removido da Rua %c, Gondola %d.\n", codigo, 'A' + i, j);
                    encontrado = 1;
                    break;
                }
            }
            if (encontrado) break;
        }
        if (encontrado) break;
    }

    if (!encontrado) {
        printf("\nProduto nao encontrado no estoque.\n");
    }
}

//Função para exibir o menu igual ao original
void exibirMenu() {
    printf("\nMenu de operacoes do estoque:\n");
    printf(" 1- Adicionar produto\n");
    printf(" 2- Buscar produto\n");
    printf(" 3- Remover produto\n");
    printf(" 4- Sair\n");
    printf("Digite sua opcao: ");
}