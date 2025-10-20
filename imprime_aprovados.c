#include <stdio.h> 


typedef struct {
    char matricula[10];
    char nome[50];
    char turma;
    float notas[3];
} Aluno;

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
imprime_aprovados(5, alunos);
 
return 0;
