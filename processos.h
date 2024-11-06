#ifndef PROCESSO_H
#define PROCESSO_H

// Estrutura para representar um processo
typedef struct {
    long long int id;
    char numero[25];
    char data_ajuizamento[20];
    char id_classe[10];
    char id_assunto[10];
    int ano_eleicao;
    char situacao[20];
} Processo;

// Função para carregar processos de um arquivo CSV
int carregar_processos(const char *nome_arquivo, Processo **processos);

// Função para remover colchetes de uma string
void remover_colchetes(char *str);

#endif // PROCESSO_H
