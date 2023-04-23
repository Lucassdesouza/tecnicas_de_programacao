#include <stdio.h>

int main() {
    int vetor[] = {1, 0, 1, 0, 1, 1, 0, 0};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int *ponteiro = vetor;

    for (int i = 1; i < tamanho; i++) {
        int chave = *(ponteiro + i);
        int j = i - 1;
        while (j >= 0 && *(ponteiro + j) > chave) {
            *(ponteiro + j + 1) = *(ponteiro + j);
            j--;
        }
        *(ponteiro + j + 1) = chave;
    }

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", *(ponteiro + i));
    }

    return 0;
}
