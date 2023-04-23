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

void inserir(ListaAlunos *lista, Aluno *novo) {
    if (lista == NULL || novo == NULL) {
        return;
    }
    
    novo->prox = lista->inicio;
    
    if (lista->inicio != NULL) {
        lista->inicio->ant = novo;
    }
    
    lista->inicio = novo;
    lista->tamanho++;
}

void imprimir(ListaAlunos *lista) {
    Aluno *atual = lista->inicio;
    
    while (atual != NULL) {
        printf("Matricula: %d, Nome: %s, Media: %.2f\n", atual->matricula, atual->nome, atual->media);
        atual = atual->prox;
    }
}

void insertionSort(ListaAlunos *lista) {
    if (lista == NULL || lista->inicio == NULL) {
        return;
    }
    
    Aluno *atual = lista->inicio->prox;
    
    while (atual != NULL) {
        Aluno *anterior = atual->ant;
        Aluno *aux = atual;
        
        while (anterior != NULL && anterior->matricula > aux->matricula) {
            anterior->prox = aux->prox;
            aux->ant = anterior->ant;
            aux->prox = anterior;
            anterior->ant = aux;
            
            if (aux->ant == NULL) {
                lista->inicio = aux;
            } else {
                aux->ant->prox = aux;
            }
            
            anterior = anterior->ant;
        }
        
        atual = atual->prox;
    }
}

int main() {
    ListaAlunos lista;
    lista.inicio = NULL;
    lista.tamanho = 0;
    
    Aluno *aluno1 = (Aluno *) malloc(sizeof(Aluno));
    aluno1->matricula = 12345;
    strcpy(aluno1->nome, "Joao");
    aluno1->media = 8.5;
    aluno1->prox = NULL;
    aluno1->ant = NULL;
    
    Aluno *aluno2 = (Aluno *) malloc(sizeof(Aluno));
    aluno2->matricula = 67890;
    strcpy(aluno2->nome, "Maria");
    aluno2->media = 9.0;
    aluno2->prox = NULL;
    aluno2->ant = NULL;
    
    Aluno *aluno3 = (Aluno *) malloc(sizeof(Aluno));
    aluno3->matricula = 23456;
    strcpy(aluno3->nome, "Pedro");
    aluno3->media = 7.0;
    aluno3->prox = NULL;
    aluno3->ant = NULL;
    
    inserir(&lista, aluno1);
    inserir(&lista, aluno2);
    inserir(&lista, aluno3);
    
    printf("Antes da ordenacao:\n");
    imprimir(&lista);
    
    insertionSort(&lista);
    
    printf("\nDepois da ordenacao:\n");
    imprimir(&lista);
    
    return 0;
}
