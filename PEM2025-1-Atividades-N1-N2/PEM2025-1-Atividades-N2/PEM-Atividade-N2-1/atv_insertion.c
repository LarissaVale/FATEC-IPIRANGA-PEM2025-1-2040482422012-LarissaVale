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

void ordenarNumeros(int *numeros, int *ptrN) {
    int chave, j;

    for (int i = 1; i < *ptrN; i++) {
        chave = *(numeros + i);
        j = i - 1;

        while (j >= 0 && *(numeros + j) > chave) {
            *(numeros + j + 1) = *(numeros + j);
            j--;
        }
        *(numeros + j + 1) = chave;
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

    ordenarNumeros(numeros, ptrN);

    printf("\nElementos do array ordenados (Insertion):\n");

    for(i=0; i<T; i++) {
        printf("%4d", numeros[i]);
    }

    printf("\n");

    return 0;
}