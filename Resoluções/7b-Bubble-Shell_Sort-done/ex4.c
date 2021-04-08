#include<stdio.h>

#define N 10
#define GAP 3

int main(void){

    int i, j, h; //contadores
    int aux;

    int v[N] = {12,42,1,6,56,23,52,9,5,24};

    printf("\nVetor antes de ser ordenado por shell sort:\n<");
    for(i=0; i<N; i++) printf("%d, ", v[i]);
    printf(">\n\n");

    for(h = 1; h < N; h = GAP*h+1);

    while(h > 0) {

        h = (h-1)/3; //atualiza o valor de h.
        for(i = h; i < N; i++) {

            aux = v[i];
            j = i;

            //efetua comparações entre elementos com distância h:
            while(v[j-h] > aux) {
                v[j] = v[j-h];
                j -= h;

                if(j < h) break;

            }
            v[j] = aux;
        }
    }

    printf("Vetor depois de ser ordenado por shell sort:\n<");
    for(i=0; i<N; i++) printf("%d, ", v[i]);
    printf(">\n\n");


    return 0;
}

/*
Output que obtive:


Vetor antes de ser ordenado por shell sort:
<12, 42, 1, 6, 56, 23, 52, 9, 5, 24, >

Vetor depois de ser ordenado por shell sort:
<1, 5, 6, 9, 12, 23, 24, 42, 52, 56, >


*/