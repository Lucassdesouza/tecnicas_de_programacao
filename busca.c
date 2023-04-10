#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int data;
  struct no *proximo;
} no;

no *busca_linear(no *head, int v) {
  no *primeiro = head;
  while (primeiro != NULL) {
    if (primeiro->data == v) {
      return primeiro;
    }
    primeiro = primeiro->proximo;
  }
  return NULL;
}

int main() {
  no *head = NULL;
  no *no1 = (no *)malloc(sizeof(no));
  no1->data = 2;
  no1->proximo = NULL;
  head = no1;
  no *no2 = (no *)malloc(sizeof(no));
  no2->data = 5;
  no2->proximo = NULL;
  no1->proximo = no2;
  no *no3 = (no *)malloc(sizeof(no));
  no3->data = 8;
  no3->proximo = NULL;
  no2->proximo = no3;
  no *no4 = (no *)malloc(sizeof(no));
  no4->data = 10;
  no4->proximo = NULL;
  no3->proximo = no4;
  no *result = busca_linear(head, 8);
  if (result != NULL) {
    printf("Valor encontrado: %d\n", result->data);
  } else {
    printf("Valor não encontrado.\n");
  }
  return 0;
}
