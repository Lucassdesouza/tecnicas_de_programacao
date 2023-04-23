#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    int matricula;
    char nome[50];
    float media;
    struct aluno *prox;
    struct aluno *ant;
} Aluno;

typedef struct lista {
    Aluno *inicio;
    int tamanho;
} ListaAlunos;

void bubbleSort(ListaAlunos *lista) {
    int trocado = 1;
    Aluno *atual, *anterior = NULL;
    while (trocado) {
        trocado = 0;
        atual = lista->inicio;
        while (atual->prox != NULL) {
            if (atual->matricula > atual->prox->matricula) {
                Aluno *prox = atual->prox;
                atual->prox = prox->prox;
                prox->prox = atual;
                if (anterior != NULL) {
                    anterior->prox = prox;
                } else {
                    lista->inicio = prox;
                }
                anterior = prox;
                trocado = 1;
            } else {
                anterior = atual;
                atual = atual->prox;
            }
        }
    }
}

int main() {
    ListaAlunos lista;
    lista.inicio = NULL;
    lista.tamanho = 0;

    // Adicionando alunos na lista
    Aluno *a1 = malloc(sizeof(Aluno));
    a1->matricula = 1001;
    strcpy(a1->nome, "Joao");
    a1->media = 8.5;
    a1->prox = NULL;
    a1->ant = NULL;

    Aluno *a2 = malloc(sizeof(Aluno));
    a2->matricula = 1002;
    strcpy(a2->nome, "Maria");
    a2->media = 9.0;
    a2->prox = NULL;
    a2->ant = a1;

    Aluno *a3 = malloc(sizeof(Aluno));
    a3->matricula = 1003;
    strcpy(a3->nome, "Jose");
    a3->media = 7.5;
    a3->prox = NULL;
    a3->ant = a2;

    a1->prox = a2;
    a2->prox = a3;
    lista.inicio = a1;
    lista.tamanho = 3;

    // Ordenando a lista com Bubble Sort
    bubbleSort(&lista);

    // Imprimindo a lista ordenada
    Aluno *atual = lista.inicio;
    while (atual != NULL) {
        printf("Matricula: %d\nNome: %s\nMedia: %.2f\n\n", atual->matricula, atual->nome, atual->media);
        atual = atual->prox;
    }

    // Liberando a memória alocada para os alunos
    atual = lista.inicio;
    while (atual != NULL) {
        Aluno *prox = atual->prox;
        free(atual);
        atual = prox;
    }

    return 0;
}
