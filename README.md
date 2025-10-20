# 2B---Estruturas
2B - Estruturas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Aluno
typedef struct {
    char matricula[8];  // até 7 caracteres + '\0'
    char nome[81];      // até 80 caracteres + '\0'
    char turma;         // ex: 'A', 'B', ...
    float notas[3];     // três notas reais
} Aluno;

// Função que imprime os alunos aprovados
void imprime_aprovados(int n, Aluno **turmas) {
    printf("\n--- Alunos Aprovados ---\n");
    for (int i = 0; i < n; i++) {
        float media = (turmas[i]->notas[0] + turmas[i]->notas[1] + turmas[i]->notas[2]) / 3.0;
        if (media >= 7.0) {
            printf("Matrícula: %s\n", turmas[i]->matricula);
            printf("Nome: %s\n", turmas[i]->nome);
            printf("Turma: %c\n", turmas[i]->turma);
            printf("Média: %.2f\n", media);
            printf("------------------------\n");
        }
    }
}

int main() {
    int n = 5;
    Aluno *turmas[5];

    // Alocação e leitura dos dados
    for (int i = 0; i < n; i++) {
        turmas[i] = (Aluno*) malloc(sizeof(Aluno));
        if (turmas[i] == NULL) {
            printf("Erro ao alocar memória.\n");
            return 1;
        }

        printf("\n--- Cadastro do Aluno %d ---\n", i + 1);
        printf("Matrícula: ");
        scanf(" %7s", turmas[i]->matricula);

        printf("Nome: ");
        getchar(); // limpa buffer antes do fgets
        fgets(turmas[i]->nome, 81, stdin);
        turmas[i]->nome[strcspn(turmas[i]->nome, "\n")] = '\0'; // remove \n

        printf("Turma: ");
        scanf(" %c", &turmas[i]->turma);

        for (int j = 0; j < 3; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &turmas[i]->notas[j]);
        }
    }

    // Chamada da função que imprime os aprovados
    imprime_aprovados(n, turmas);

    // Libera memória
    for (int i = 0; i < n; i++) {
        free(turmas[i]);
    }

    return 0;
}
