/*-------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Ordenação de dados com o método  *
* insertion.                                             *
* Data - 16/05/2025                                      * 
* Autor: Larissa Vale                                    *
*--------------------------------------------------------*/

#include <stdio.h>

void preencherArray(int *ptrN, int numeros[]) {
    for(int i=0; i<*ptrN; i++) {
        printf("\nDigite o numeros inteiro %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }
}

void ordenarNumeros(int *ptrN, int *numeros) {
    int aux;
    for (int i = 0; i < *ptrN - 1; i++) {
        for (int j = 0; j < *ptrN - i - 1; j++) {
            if (*(numeros + j) > *(numeros + j + 1)) {
                aux = *(numeros + j);
                *(numeros + j) = *(numeros + j + 1);
                *(numeros + j + 1) = aux;
            }
        }
    }
}

int main () {

    int T;
    int *ptrN = &T;
    
    printf("\nDigite a quantidade de numeros escolhida (max 100): ");
    scanf("%d", &T);

    if(T > 100 || T < 1) {
        printf("Erro! Numero invalido.");
        return 1;
    }

    int numeros[T];
    int i;

    preencherArray(ptrN, numeros);

    ordenarNumeros(ptrN, numeros);

    printf("\nElementos do array ordenados (Bubble Sort):\n");

    for(i=0; i<T; i++) {
        printf("%4d", numeros[i]);
    }

    printf("\n");

    return 0;
}