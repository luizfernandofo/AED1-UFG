#include<stdio.h>

//Professor permitiu escrever o código em c em vez de fazer um pseudocódigo 08/04/2021

#define N 10

void bubbleSort(int vetor[], int tam){
    int j, aux;

    if(tam == 1) return;

    for (j = 0; j < tam-1; j++){
        if (vetor[j] > vetor[j + 1]){
            aux = vetor[j];
            vetor[j] = vetor[j + 1];
            vetor[j + 1] = aux;
        }
    }
    
    bubbleSort(vetor, tam-1);

    return;
}


int main(void){

    int i; //contadores
    int v[N] = {12,42,1,6,56,23,52,9,5,24};

    printf("\nVetor antes de ser ordenado por bubble sort recursivo:\n<");
    for(i=0; i<N; i++) printf("%d, ", v[i]);
    printf(">");   

    bubbleSort(v, N);

    printf("\n\nVetor depois de ser ordenado por bubble sort recursivo:\n<");
    for(i=0; i<N; i++) printf("%d, ", v[i]);
    printf(">\n\n");

    return 0;
}