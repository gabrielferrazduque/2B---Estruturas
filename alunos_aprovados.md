#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição do tipo Aluno
typedef struct {
    char matricula[8];    // 7 caracteres + '\0'
    char nome[81];        // 80 caracteres + '\0'
    char turma;           // caractere único
    float notas[3];       // 3 notas reais
} Aluno;

// Função para imprimir alunos aprovados
void imprime_aprovados(int n, Aluno **turmas) {
    printf("\n--- Lista de Alunos Aprovados ---\n");
    for (int i = 0; i < n; i++) {
        float media = (turmas[i]->notas[0] + turmas[i]->notas[1] + turmas[i]->notas[2]) / 3.0;
        if (media >= 7.0) {
            printf("Matrícula: %s\n", turmas[i]->matricula);
            printf("Nome: %s\n", turmas[i]->nome);
            printf("Turma: %c\n", turmas[i]->turma);
            printf("Média: %.2f\n", media);
            printf("-----------------------------\n");
        }
    }
}

int main() {
    Aluno *alunos[5]; // vetor de ponteiros para Aluno
    int i, j;

    // Leitura dos dados
    for (i = 0; i < 5; i++) {
        alunos[i] = (Aluno *)malloc(sizeof(Aluno));
        if (alunos[i] == NULL) {
            printf("Erro ao alocar memória para o aluno %d.\n", i + 1);
            return 1;
        }

        printf("\nCadastro do aluno %d:\n", i + 1);

        printf("Matrícula (até 7 caracteres): ");
        scanf(" %7s", alunos[i]->matricula);

        getchar(); // limpar buffer antes do fgets
        printf("Nome (até 80 caracteres): ");
        fgets(alunos[i]->nome, 81, stdin);
        alunos[i]->nome[strcspn(alunos[i]->nome, "\n")] = '\0'; // remover '\n'

        printf("Turma (ex: A, B...): ");
        scanf(" %c", &alunos[i]->turma);

        for (j = 0; j < 3; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &alunos[i]->notas[j]);
        }
    }

    // Chamada da função para imprimir os aprovados
    imprime_aprovados(5, alunos);

    // Liberação de memória
    for (i = 0; i < 5; i++) {
        free(alunos[i]);
    }

    return 0;
}
