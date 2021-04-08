#include<stdio.h>

#define N 10

void bubbleSort(int vetor[], int tam){
    int k, j, aux, flag;

    for (k = tam - 1; k > 0; k--){

        flag=0;

        for (j = 0; j < k; j++){
            if (vetor[j] > vetor[j + 1]){
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
                flag += 1;
            }
        }

        if(flag==0){ //caso o vetor seja percorrido e não haja trocas, esta comparação irá interromper o laço
            printf("\n\nOrdenacao interrompida para evitar comparacoes desnecessarias\npois o vetor ja esta ordenado\n\n");
            break;
        }
    }

    return;
}


int main(void){

    int i; //contadores
    int v[N] = {12,42,1,6,56,23,52,9,5,24};

    printf("\nVetor antes de ser ordenado por bubble sort otimizado:\n<");
    for(i=0; i<N; i++) printf("%d, ", v[i]);
    printf(">");   

    bubbleSort(v, N);

    printf("Vetor depois de ser ordenado por bubble sort otimizado:\n<");
    for(i=0; i<N; i++) printf("%d, ", v[i]);
    printf(">\n\n");

    return 0;
}