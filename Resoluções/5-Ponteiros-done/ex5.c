#include<stdio.h>

void swap(int *a, int *b);

int main(int argc, char const *argv[])
{
    
    int a, b;

    printf("Entre com dois valores inteiros para serem trocados de lugar na memoria:");

    scanf("%d %d", &a, &b);

    printf("\nAntes da troca:\nA: %d  B: %d\n\n", a, b);

    swap(&a, &b);

    printf("Depois da troca:\nA: %d  B: %d\n\n", a, b);

    return 0;
}

//implementação das funções

void swap(int *a, int *b){
    int temp;

    temp = (*a);
    (*a) = (*b);
    (*b) = temp;

    return;

}