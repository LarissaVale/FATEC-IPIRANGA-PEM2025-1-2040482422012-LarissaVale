/*-------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: registrar, calcular e classificar   
o desempenho de candidatos de um processo seletivo baseado      
em vários critérios de avaliação                         *
* Data - 27/02/2025                                      * 
* Autor: Larissa Vale                                    *
*--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define T 50
#define CLASSIFICADOS 15

int main () {

    // Declarando variáveis
    char nome[T][100], tempNome[100];
    float notasPE[T][4], notasAC[T][5],  notasPP[T][10], notasEB[T][3];  
    float nf[T], tempNota;
    int i = 0, totalcandidatos = 0;

    while (i < T) {
        // Recebe o nome do candidato
        printf("Insira o nome do candidato: ");
        scanf("%s", nome[i]);

        // Recebe as notas da Prova Escrita 
        printf("\nDigite as notas da PE (4 notas):\n");
        for(int j = 0; j < 4; j++) {
            scanf("%f", &notasPE[i][j]);
        }   

        // Recebe as notas da Análise Curricular 
        printf("\nDigite as notas da AC (5 notas):\n");
        for(int j = 0; j < 5; j++) {
            scanf("%f", &notasAC[i][j]);
        }

        // Recebe as notas da Prova Prática
        printf("\nDigite as notas da PP (10 notas):\n");
        for(int j = 0; j < 10; j++) {
            scanf("%f", &notasPP[i][j]);
        }

        // Recebe as notas da Entrevista em Banca Avaliadora 
        printf("\nDigite as notas da EB (3 notas):\n");
        for(int j = 0; j < 3; j++) {
            scanf("%f", &notasEB[i][j]);
        }

        // Cálculo da média central (excluindo maior e menor nota)
        float soma, maior, menor;

        // Prova Escrita (PE)
        soma = 0.0, maior = notasPE[i][0], menor = notasPE[i][0];
        for (int j = 0; j < 4; j++) {
            soma += notasPE[i][j];
            if (notasPE[i][j] > maior) maior = notasPE[i][j];
            if (notasPE[i][j] < menor) menor = notasPE[i][j];
        }
        float mediaPE = (soma - maior - menor) / 2;

         // Análise Curricular (AC)
         soma = 0.0, maior = notasAC[i][0], menor = notasAC[i][0];
         for (int j = 0; j < 5; j++) {
             soma += notasAC[i][j];
             if (notasAC[i][j] > maior) maior = notasAC[i][j];
             if (notasAC[i][j] < menor) menor = notasAC[i][j];
         }
         float mediaAC = (soma - maior - menor) / 3;

        // Prova Prática (PP)
        soma = 0.0, maior = notasPP[i][0], menor = notasPP[i][0];
        for (int j = 0; j < 10; j++) {
            soma += notasPP[i][j];
            if (notasPP[i][j] > maior) maior = notasPP[i][j];
            if (notasPP[i][j] < menor) menor = notasPP[i][j];
        }
        float mediaPP = (soma - maior - menor) / 8;

        // Entrevista em Banca Avaliadora (EB)
        soma = 0.0, maior = notasEB[i][0], menor = notasEB[i][0];
        for (int j = 0; j < 3; j++) {
            soma += notasEB[i][j];
            if (notasEB[i][j] > maior) maior = notasEB[i][j];
            if (notasEB[i][j] < menor) menor = notasEB[i][j];
        }
        float mediaEB = (soma - maior - menor) / 1;

        // Cálculo da nota final
        nf[i] = (mediaPE * 0.3) + (mediaAC * 0.1) + (mediaPP * 0.4) + (mediaEB * 0.2);

        totalcandidatos++;

        //verifica se deseja cadastrar outro candidato
        int yes;
        printf("\nDeseja inserir mais um candidato? Digite 1 para Sim e 0 para nao: ");
        scanf("%d", &yes);

        if(yes == 1) {
            i++;
        } else {
            break;  
        }
    }
 
     // Ordenação de candidatos pela nota final
     for (int k = 0; k < totalcandidatos; k++) {
        for (int j = k + 1; j < totalcandidatos; j++) {
            if (nf[j] > nf[k]) {
                // Troca notas
                tempNota = nf[k];
                nf[k] = nf[j];
                nf[j] = tempNota;

                // Troca nomes
                strcpy(tempNome, nome[i]);
                strcpy(nome[i], nome[j]);
                strcpy(nome[j], tempNome);
            }
        }
    }

     // Exibe os 15 melhores candidatos
     printf("\n=== Classificacao Final ===\n");
     int top = (totalcandidatos < CLASSIFICADOS) ? totalcandidatos : CLASSIFICADOS;
 
     for (int i = 0; i < top; i++) {
         printf("%do Lugar: %s - Nota Final: %.2f\n", i + 1, nome[i], nf[i]);
     }

    return 0;
}