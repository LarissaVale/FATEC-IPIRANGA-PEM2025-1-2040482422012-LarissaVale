/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Controlar estoque                *
* Data - 07/03/2025                                      * 
* Autor: Larissa Vitória Nogueira do Vale                *
*--------------------------------------------------------*/

#include <stdio.h>

int main() {
    
    char estoque[3][10][6]; // Matriz para armazenar códigos dos produtos
    char rua, codigo[6]; // Variáveis para armazenar a rua e o código do produto
    int i, j, k, menu = 0, encontrado, quantidade;

    // Inicializa o estoque vazio
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 10; j++) {
            // Preenche cada posição da matriz com o caractere nulo ('\0')
            // Isso significa que inicialmente não há nenhum produto armazenado
            estoque[i][j][0] = '\0'; 
        }
    }

    // Loop principal do menu
    while (menu != 4) {
        printf("\nMenu de operacoes do estoque:\n 1- Adicionar produto\n 2- Buscar produto\n 3- Remover produto\n 4- Sair\n Digite sua opcao: ");
        scanf("%d", &menu);

        if (menu == 1) {
            // Adiciona um produto ou lote de produtos ao estoque
            printf("\nDigite o codigo do produto (Letra + 3 numeros, Ex: S123): ");
            scanf("%s", codigo);
            printf("\nDigite a quantidade de produtos a ser armazenada: ");
            scanf("%d", &quantidade);

            // Verifica se o produto já está armazenado em alguma gôndola
            encontrado = 0;
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 10; j++) {
                    // Compara os códigos de produto, caractere por caractere
                    for (k = 0; k < 6; k++) {
                        if (estoque[i][j][k] != codigo[k]) {
                            break;
                        }
                        if (codigo[k] == '\0') { // Se encontrou o código igual
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
                //Se o produto não foi encontrado, solicita a rua e a gôndola
                do {
                    printf("\nDigite a Rua (A, B ou C): ");
                    scanf(" %c", &rua);
                    if (rua < 'A' || rua > 'C') {
                        printf("\nErro! Rua invalida. Digite A, B ou C.\n");
                    }
                } while (rua < 'A' || rua > 'C');
                i = rua - 'A'; //Converte a letra da rua para um índice (0, 1, 2)

                do {
                    printf("\nDigite a Gondola (0 a 9): ");
                    scanf("%d", &j);
                    if (j < 0 || j > 9) {
                        printf("\nErro! Gondola invalida. Digite um numero entre 0 e 9.\n");
                    }
                } while (j < 0 || j > 9);

                // Armazena a quantidade de produtos na posição especificada
                for (int count = 0; count < quantidade; count++) {
                    // Preenche a posição na gôndola para cada unidade do produto
                    for (k = 0; k < 6; k++) {
                        estoque[i][j][k] = codigo[k];
                    }
                }
                printf("\nProduto %s armazenado na Rua %c, Gondola %d. Quantidade: %d.\n", codigo, rua, j, quantidade);
            }
        } 
        else if (menu == 2) {
            //Busca um produto no estoque
            printf("\nDigite o codigo do produto para busca: ");
            scanf("%s", codigo);
            encontrado = 0;

            for (i = 0; i < 3; i++) {
                for (j = 0; j < 10; j++) {
                    //Compara os códigos de produto, caractere por caractere
                    for (k = 0; k < 6; k++) {
                        if (estoque[i][j][k] != codigo[k]) {
                            break;
                        }
                        if (codigo[k] == '\0') { //Se encontrou o código igual
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
        else if (menu == 3) {
            //Remove um produto do estoque
            printf("\nDigite o codigo do produto para remover: ");
            scanf("%s", codigo);
            encontrado = 0;

            for (i = 0; i < 3; i++) {
                for (j = 0; j < 10; j++) {
                    //Compara os códigos de produto, caractere por caractere
                    for (k = 0; k < 6; k++) {
                        if (estoque[i][j][k] != codigo[k]) {
                            break;
                        }
                        if (codigo[k] == '\0') { //Se encontrou o código igual
                            estoque[i][j][0] = '\0'; //Remove o produto (tira o código da posição)
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
        else if (menu == 4) {
            // Encerra o programa
            printf("\nSaindo do programa...\n");
        }
        else {
            // Caso a opção digitada seja inválida
            printf("\nOpcao invalida! Tente novamente.\n");
        }
    }

    return 0;
}
