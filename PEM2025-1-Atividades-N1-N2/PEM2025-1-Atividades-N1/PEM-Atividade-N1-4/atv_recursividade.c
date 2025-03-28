/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Árvore de diretório              *
*                                                        *
* Data - 27/03/2025                                      * 
* Autor: Larissa Vitória Nogueira do Vale                *
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_ARQUIVOS 100

// Estrutura para armazenar caminhos dos diretórios principais
char caminhos[MAX_ARQUIVOS][1024];
int totalCaminhos = 0;

// Função para listar diretórios no caminho fornecido
void listarDiretorios(const char *caminho, int nivel) {
    DIR *dir;
    struct dirent *entrada;
    
    // Tenta abrir o diretório
    dir = opendir(caminho);
    if (dir == NULL) {
        perror("Erro ao abrir diretorio");
        return;
    }
    
    // Percorre os arquivos e diretórios dentro do caminho fornecido
    while ((entrada = readdir(dir)) != NULL) {
        // Ignorar os diretórios "." e ".."
        if (strcmp(entrada->d_name, ".") == 0 || strcmp(entrada->d_name, "..") == 0) {
            continue;
        }
        
        // Imprime com recuo proporcional ao nível de profundidade
        for (int i = 0; i < nivel; i++) {
            printf("  "); // Espaço para representar hierarquia
        }
        
        // Exibe o número da pasta e o nome
        printf("%d - %s\n", totalCaminhos, entrada->d_name);
        
        // Se for um diretório, armazenar o caminho e explorar recursivamente
        if (entrada->d_type == DT_DIR) {
            snprintf(caminhos[totalCaminhos], sizeof(caminhos[totalCaminhos]), "%s/%s", caminho, entrada->d_name);
            totalCaminhos++;
        }
    }
    
    // Fecha o diretório
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <caminho do diretorio>\n", argv[0]);
        return 1;
    }
    
    printf("Explorando diretorios em: %s\n", argv[1]);
    listarDiretorios(argv[1], 0);
    
    while (1) {
        // Pergunta ao usuário qual pasta deseja abrir
        int escolha;
        printf("\nDigite o numero da pasta que deseja explorar (-1 para sair): ");
        scanf("%d", &escolha);
        
        if (escolha >= 0 && escolha < totalCaminhos) {
            printf("Explorando: %s\n", caminhos[escolha]);
            listarDiretorios(caminhos[escolha], 1);
        } else if (escolha == -1) {
            printf("Saindo...\n");
            break;
        } else {
            printf("Escolha invalida. Tente novamente.\n");
        }
    }
    
    return 0;
}