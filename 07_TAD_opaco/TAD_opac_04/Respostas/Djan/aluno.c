
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct Aluno {
    char *nome;
    int matricula;
    float n1;
    float n2;
    float n3;
};

/* Cria um aluno */
tAluno* CriaAluno() {
    tAluno* aluno = malloc(sizeof(tAluno));

    if (aluno == NULL) {
        exit(1);
    }

    aluno->nome = NULL;
    aluno->matricula = -1;
    aluno->n1 = -1;
    aluno->n2 = -1;
    aluno->n3 = -1;

    return aluno;
}

/* Libera a memória do aluno */
void ApagaAluno(tAluno* aluno) {
    if (aluno != NULL) {
        free(aluno->nome);
        free(aluno);
    }
}

/* Lê os dados de um aluno */
void LeAluno(tAluno* aluno) {
    char nomeTemporario[100];

    /* Lê o nome */
    scanf(" %99[^\n]", nomeTemporario);

    /* Aloca memória para o nome */
    aluno->nome = malloc((strlen(nomeTemporario) + 1) * sizeof(char));

    if (aluno->nome == NULL) {
        exit(1);
    }

    /* Copia o nome */
    strcpy(aluno->nome, nomeTemporario);

    /* Lê matrícula e notas */
    scanf("%d", &aluno->matricula);
    scanf("%f %f %f", &aluno->n1, &aluno->n2, &aluno->n3);
}

/* Compara as matrículas */
int ComparaMatricula(tAluno* aluno1, tAluno* aluno2) {
    if (aluno1->matricula > aluno2->matricula) {
        return 1;
    }

    if (aluno1->matricula < aluno2->matricula) {
        return -1;
    }

    return 0;
}

/* Calcula a média */
int CalculaMediaAluno(tAluno* aluno) {
    return (int)((aluno->n1 + aluno->n2 + aluno->n3) / 3);
}

/* Verifica aprovação */
int VerificaAprovacao(tAluno* aluno) {
    return CalculaMediaAluno(aluno) >= 7;
}

/* Imprime os dados do aluno */
void ImprimeAluno(tAluno* aluno) {
    printf("%s\n", aluno->nome);
}
