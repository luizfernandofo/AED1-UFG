#include<stdio.h>

#define VEC 6

void insertionSort(int vetor[], int tam){
    int i, j, k, tmp;

    printf("A antes = < ");
    for(k=0; k<tam-1; k++) printf("%d, ", vetor[k]);
    printf("%d >\n", vetor[tam-1]);

    for (i = 1; i < tam; i++){
        j = i;

        while (j > 0 && vetor[j - 1] < vetor[j]){

            tmp = vetor[j];
            vetor[j] = vetor[j - 1];
            vetor[j - 1] = tmp;
            j--;

        }
    }

    printf("A depois = < ");
    for(k=0; k<tam-1; k++) printf("%d, ", vetor[k]);
    printf("%d >\n", vetor[tam-1]);

    return;
}

int main(void){

    int i, j;//contadores

    int v[VEC] = {31, 41, 59, 26, 41, 58};

    insertionSort(v, VEC);

    return 0;
}

