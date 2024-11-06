#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processos.h"

// Função para carregar processos do arquivo CSV
int carregar_processos(const char *nome_arquivo, Processo **processos) {
    FILE *file = fopen(nome_arquivo, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    char linha[256];
    int count = 0;
    // Ler o cabeçalho e ignorar
    fgets(linha, sizeof(linha), file);

    // Contar quantos processos há no arquivo
    while (fgets(linha, sizeof(linha), file)) {
        count++;
    }
    rewind(file);

    // Alocar memória para os processos
    *processos = (Processo *)malloc(count * sizeof(Processo));
    if (!*processos) {
        perror("Erro ao alocar memória");
        fclose(file);
        return 0;
    }

    // Ignorar o cabeçalho novamente
    fgets(linha, sizeof(linha), file);

    // Ler os dados do arquivo CSV
    int i = 0;
    while (fgets(linha, sizeof(linha), file)) {
        // Corrigindo o formato do sscanf para garantir a leitura correta
        sscanf(linha, "%lld,%24[^,],%29[^,],%d,%d,%d",  // Usando um formato mais simples
       &(*processos)[i].id,
       (*processos)[i].numero,
       (*processos)[i].data_ajuizamento,
       &(*processos)[i].id_classe,
       &(*processos)[i].id_assunto,
       &(*processos)[i].ano_eleicao);

        // Gerar a situação aleatória para o processo
        gerar_situacao((*processos)[i].situacao);

        i++;
    }

    fclose(file);
    return count;
}

void gerar_situacao(char *situacao) {
    // Situações possíveis
    const char *situacoes[] = {
        "Em julgamento",
        "Aprovado",
        "Culpado",
        "Encerrado"
    };

    // Gerar um número aleatório entre 0 e 3
    int index = rand() % 4;  // Isso gera um valor entre 0 e 3

    // Atribuir a situação aleatória ao campo "situacao"
    strcpy(situacao, situacoes[index]);
}

// Função para remover colchetes de uma string
void remover_colchetes(char *str) {
    int i = 0, j = 0;
    while (str[i]) {
        if (str[i] != '[' && str[i] != ']') {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}
