#include<stdio.h>
#include<stdlib.h>

#define N 100
#define GAP 3

int main(void){

    int i, j, h; //contadores
    int aux;

    int v[N];

    printf("Preenchendo o vetor com valores aleatorios de 1 a 100...\n\n");
    for(i=0; i<N; i++) v[i]= (rand() % 99) + 1;


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
            while(v[j-h] < aux) {
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

Preenchendo o vetor com valores aleatorios de 1 a 100...


Vetor antes de ser ordenado por shell sort:
<42, 54, 98, 68, 63, 83, 94, 55, 35, 12, 63, 30, 17, 97, 62, 96, 26, 63, 76, 91, 19, 52, 42, 55, 95, 8, 97, 6, 18, 96, 3, 46, 21, 55, 88, 14, 27, 65, 8, 94, 93, 52, 39, 40, 52, 12, 94, 89, 39, 38, 6, 24, 92, 88, 40, 89, 12, 40, 8, 86, 41, 66, 15, 61, 91, 11, 32, 33, 59, 77, 24, 46, 51, 97, 17, 6, 58, 16, 40, 84, 28, 51, 28, 56, 46, 60, 17, 51, 72, 74, 16, 67, 75, 38, 93, 56, 81, 4, 61, 9, >

Vetor depois de ser ordenado por shell sort:
<98, 97, 97, 97, 96, 96, 95, 94, 94, 94, 93, 93, 92, 91, 91, 89, 89, 88, 88, 86, 84, 83, 81, 77, 76, 75, 74, 72, 68, 67, 
66, 65, 63, 63, 63, 62, 61, 61, 60, 59, 58, 56, 56, 55, 55, 55, 54, 52, 52, 52, 51, 51, 51, 46, 46, 46, 42, 42, 41, 40, 40, 40, 40, 39, 39, 38, 38, 35, 33, 32, 30, 28, 28, 27, 26, 24, 24, 21, 19, 18, 17, 17, 17, 16, 16, 15, 14, 12, 12, 12, 11, 9, 8, 8, 8, 6, 6, 6, 4, 3, >

*/