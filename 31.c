//implemente uma versão não recursiva do algoritmo de busca em profundidade

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int topo;
    int itens[MAX];
} pilha;

void inicializaPilha(pilha *p) {
    p->topo = -1;
}

bool pilhaVazia(pilha *p) {
    if (p->topo == -1) {
        return true;
    } else {
        return false;
    }
}

bool pilhaCheia(pilha *p) {
    if (p->topo == MAX - 1) {
        return true;
    } else {
        return false;
    }
}

void empilha(pilha *p, int x) {
    if (pilhaCheia(p)) {
        printf("Pilha cheia!\n");
    } else {
        p->topo++;
        p->itens[p->topo] = x;
    }
}

int desempilha(pilha *p) {
    int aux;
    if (pilhaVazia(p)) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        aux = p->itens[p->topo];
        p->topo--;
        return aux;
    }
}

void imprimePilha(pilha *p) {
    int i;
    if (pilhaVazia(p)) {
        printf("Pilha vazia!\n");
    } else {
        for (i = p->topo; i >= 0; i--) {
            printf("%d\n", p->itens[i]);
        }
    }
}

typedef struct {
    int vertice;
    int peso;
    struct no *prox;
} no;

typedef struct {
    int numVertices;
    int *visitado;
    no **listaAdj;
} grafo;

void inicializaGrafo(grafo *g, int numVertices) {
    int i;
    g->numVertices = numVertices;
    g->listaAdj = (no **) malloc(numVertices * sizeof (no *));
    g->visitado = (int *) malloc(numVertices * sizeof (int));
    for (i = 0; i < numVertices; i++) {
        g->listaAdj[i] = NULL;
        g->visitado[i] = 0;
    }
}

void insereAresta(grafo *g, int v1, int v2, int peso) {
    no *aux = (no *) malloc(sizeof (no));
    aux->vertice = v2;
    aux->peso = peso;
    aux->prox = g->listaAdj[v1];
    g->listaAdj[v1] = aux;
}

void imprimeGrafo(grafo *g) {
    int i;
    no *aux;
    for (i = 0; i < g->numVertices; i++) {
        printf("%d: ", i);
        aux = g->listaAdj[i];
        while (aux != NULL) {
            printf("%d(%d) ", aux->vertice, aux->peso);
            aux = aux->prox;
        }
        printf("\n");
    }
}

void buscaProfundidade(grafo *g, int v) {
    no *aux;
    pilha p;
    inicializaPilha(&p);
    empilha(&p, v);
    while (!pilhaVazia(&p)) {
        v = desempilha(&p);
        if (!g->visitado[v]) {
            printf("%d\n", v);
            g->visitado[v] = 1;
            aux = g->listaAdj[v];
            while (aux != NULL) {
                if (!g->visitado[aux->vertice]) {
                    empilha(&p, aux->vertice);
                }
                aux = aux->prox;
            }
        }
    }
}

int main() {
    grafo g;
    inicializaGrafo(&g, 5);
    insereAresta(&g, 0, 1, 1);
    insereAresta(&g, 0, 2, 1);
    insereAresta(&g, 1, 3, 1);
    insereAresta(&g, 2, 3, 1);
    insereAresta(&g, 3, 4, 1);
    imprimeGrafo(&g);
    buscaProfundidade(&g, 0);
    return 0;
}
