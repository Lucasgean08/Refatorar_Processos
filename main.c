#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processos.h"

int main() {
    srand(time(NULL)); 

    Processo *processos = NULL;
    int num_processos = carregar_processos("processos_modificado.csv", &processos);

    if (num_processos == 0) {
        printf("Nenhum processo foi carregado. Verifique o arquivo CSV.\n");
        return 1;
    }

    printf("Numero de processos carregados: %d\n", num_processos);

    // Solicitar o ID do processo
    long long id_processo;
    printf("Qual o ID do processo que deseja consultar? ");
    scanf("%lld", &id_processo);

    // Buscar e exibir o processo correspondente ao ID
    int encontrado = 0;
    for (int i = 0; i < num_processos; i++) {
        if (processos[i].id == id_processo) {
            printf("\nProcesso encontrado:\n");
            printf("ID: %lld\n", processos[i].id);
            printf("Numero: %s\n", processos[i].numero);
            printf("Data de ajuizamento: %s\n", processos[i].data_ajuizamento);
            printf("Classe: %d\n", processos[i].id_classe);  // Mudando para %d
            printf("Assunto: %d\n", processos[i].id_assunto);  // Mudando para %d
            printf("Ano de eleicao: %d\n", processos[i].ano_eleicao);
            printf("Situacao: %s\n", processos[i].situacao);  // Aqui vai a situação aleatória
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Processo com ID %lld não encontrado.\n", id_processo);
    }

    // Liberar memória
    free(processos);
    return 0;
}
