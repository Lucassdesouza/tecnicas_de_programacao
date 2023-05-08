// Atividade feita em dupla: Lucas Santana e Tiago Chehab

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hash com 3 cadeias de encadeamento

#define HASH_SIZE 3

typedef struct node {
    char key;
    struct node *next;
} Node;

// Função de hash que atribui valores de 0 a 2 para as letras
int hash(char key) {
    if (key == 'B' || key == 'Q' || key == 'H') {
        return 0;
    } else if (key == 'I' || key == 'U' || key == 'C' || key == 'R') {
        return 1;
    } else {
        return 2;
    }
}

// Função para inserir uma chave na tabela hash
void insert(Node *hashTable[], char key) {
    // Cria um novo nó com a chave a ser inserida
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;

    // Insere o novo nó no final da lista encadeada correspondente ao valor da função de hash
    int index = hash(key);
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        Node *current = hashTable[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Função para imprimir a tabela
void printHashTable(Node *hashTable[]) {
    printf("Tabela Hash:\n");
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("Hash %d: ", i);
        Node *current = hashTable[i];
        while (current != NULL) {
            printf("%c ", current->key);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    // Cria a tabela hash como um array de ponteiros para nós
    Node *hashTable[HASH_SIZE];
    memset(hashTable, 0, sizeof(hashTable));
    insert(hashTable, 'D');
    insert(hashTable, 'Q');
    insert(hashTable, 'B');
    insert(hashTable, 'I');
    insert(hashTable, 'M');
    insert(hashTable, 'H');
    insert(hashTable, 'G');
    insert(hashTable, 'U');
    insert(hashTable, 'A');
    insert(hashTable, 'C');
    insert(hashTable, 'R');
    insert(hashTable, 'S');
    insert(hashTable, 'J');
    printHashTable(hashTable);

    return 0;
}