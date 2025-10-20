// Nome: Gabriel Ferraz Duque
// Atividade: 2B - Estruturas
// Data: 20/10/2025

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura do Aluno com typedef
typedef struct {
    char matricula[8];   // 7 caracteres + '\0'
    char nome[81];       // 80 caracteres + '\0'
    char turma;          // ex: 'A', 'B', etc.
    float notas[3];      // 3 notas reais
} Aluno;

// Função que imprime os alunos aprovados (média >= 7.0)
void imprime_aprovados(int n, Aluno **turmas) {
    printf("\n=== Alunos Aprovados ===\n");
    for (int i = 0; i < n; i++) {
        float media = (turmas[i]->notas[0] + turmas[i]->notas[1] + turmas[i]->notas[2]) / 3.0;
        if (media >= 7.0) {
            printf("Matrícula: %s\n", turmas[i]->matricula);
            printf("Nome: %s\n", turmas[i]->nome);
            printf("Turma: %c\n", turmas[i]->turma);
            printf("Média: %.2f\n", media);
            printf("-----------------------\n");
        }
    }
}

int main() {
    Aluno *alunos[5];  // Vetor de 5 ponteiros para Aluno

    for (int i = 0; i < 5; i++) {
        alunos[i] = (Aluno *) malloc(sizeof(Aluno));
        if (alunos[i] == NULL) {
            printf("Erro ao alocar memória.\n");
            return 1;
        }

        printf("\nCadastro do aluno %d:\n", i + 1);

        printf("Matrícula (até 7 caracteres): ");
        scanf(" %7s", alunos[i]->matricula);

        getchar(); // Limpar o buffer antes de fgets
        printf("Nome (até 80 caracteres): ");
        fgets(alunos[i]->nome, 81, stdin);
        alunos[i]->nome[strcspn(alunos[i]->nome, "\n")] = '\0'; // Remove \n

        printf("Turma: ");
        scanf(" %c", &alunos[i]->turma);

        for (int j = 0; j < 3; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &alunos[i]->notas[j]);
        }
    }

    // Chamada da função para imprimir os aprovados
    imprime_aprovados(5, alunos);

    // Libera a memória
    for (int i = 0; i < 5; i++) {
        free(alunos[i]);
    }

    return 0;
}
