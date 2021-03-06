#include<stdlib.h>
#include<stdio.h>
#include<math.h>

/**
 * @brief função que troca os valores de lugar.
 * 
 * @param a endereço da variavel do tipo inteiro, a.
 * @param b endereço da variavel do tipo inteiro, b.
 */
void swap(int *a, int *b);

int main(int argc, char *argv[]){

    int a, b;

    printf("Insira dos valores inteiros, a e b, que serao trocados de lugar:\n");

    scanf("%d %d", &a, &b);

    printf("A e B antes da troca:\na: %d, b: %d\n", a, b);

    swap(&a, &b);

    printf("A e B depois da troca:\na: %d, b: %d\n", a, b);

    return 0;
}

//implementação das funções

void swap(int *a, int *b){

    int temp;

    temp = (*a);
    (*a) = (*b);
    (*b) = temp;

}