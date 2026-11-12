
#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int main() {
    int quantidade;
    int i, j;

    tAluno** alunos;
    tAluno* auxiliar;

    /* Lê a quantidade de alunos */
    scanf("%d", &quantidade);

    /* Aloca o vetor dinamicamente */
    alunos = malloc(quantidade * sizeof(tAluno*));

    if (alunos == NULL && quantidade > 0) {
        exit(1);
    }

    /* Cria e lê cada aluno */
    for (i = 0; i < quantidade; i++) {
        alunos[i] = CriaAluno();
        LeAluno(alunos[i]);
    }

    /* Ordena os alunos por matrícula */
    for (i = 0; i < quantidade - 1; i++) {
        for (j = 0; j < quantidade - 1 - i; j++) {

            if (ComparaMatricula(alunos[j], alunos[j + 1]) > 0) {
                auxiliar = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = auxiliar;
            }
        }
    }

    /* Imprime somente os aprovados */
    for (i = 0; i < quantidade; i++) {
        if (VerificaAprovacao(alunos[i])) {
            ImprimeAluno(alunos[i]);
        }
    }

    /* Libera os alunos */
    for (i = 0; i < quantidade; i++) {
        ApagaAluno(alunos[i]);
    }

    /* Libera o vetor */
    free(alunos);

    return 0;
}
