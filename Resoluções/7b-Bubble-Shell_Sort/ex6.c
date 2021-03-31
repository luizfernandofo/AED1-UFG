#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 5000
#define GAP 3

void shell_sort(int *v, int tam){

    int i, j, h; //contadores
    int aux;

    for(h = 1; h < tam; h = GAP*h+1);

    while(h > 0) {

        h = (h-1)/3; //atualiza o valor de h.
        for(i = h; i < tam; i++) {

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

    return;
}

void bubbleSort(int vetor[], int tam){

    int k, j;
    int aux;

    for (k = tam - 1; k > 0; k--){
        for (j = 0; j < k; j++){
            if (vetor[j] > vetor[j + 1]){

                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
                

            }
        }
    }

    return;
}


int main(void){

    int i; //contadores
    time_t bbTimeInicial, bbTimeFinal, bbTimeResult; // tipo da biblioteca time.h
    time_t sTimeInicial, sTimeFinal, sTimeResult; 

    int v1[N], v2[N];

    printf("Preenchendo o vetor1 com valores aleatorios de 0 a 5000 e copiando para o vetor2...\n\n");
    for(i=0; i<N; i++){
        v1[i] = (rand() % N);
        v2[i] = v1[i];
    }

    //o bloco de código a seguir irá pegar o tempo antes da execução e depois da execução 
    //do bubble sort e calcular a variação
    time(&bbTimeInicial);
    bubbleSort(v1, N);
    time(&bbTimeFinal);
    bbTimeResult = bbTimeFinal - bbTimeInicial;

    //o bloco de código a seguir irá pegar o tempo antes da execução e depois da execução 
    //do shell sort e calcular a variação
    time(&sTimeInicial); //printf("1: %ld\n", sTimeInicial);
    shell_sort(v2, N);
    time(&sTimeFinal); //printf("2: %ld\n", sTimeFinal);
    sTimeResult = sTimeFinal - sTimeInicial;

    
    printf("Tempo demorado com Bubble Sort: %ld segundos\n\n", bbTimeResult);
    printf("Tempo demorado com Shell Sort: %ld segundos\n\n", sTimeResult);

    return 0;
}

/*
Output que obtive para 5000 numeros:

Preenchendo o vetor1 com valores aleatorios de 0 a 5000 e copiando para o vetor2...

Tempo demorado com Bubble Sort: 0 segundos

Tempo demorado com Shell Sort: 0 segundos

*/

/*
Output que obtive para 50000 numeros:

Preenchendo o vetor1 com valores aleatorios de 0 a 50000 e copiando para o vetor2...

Tempo demorado com Bubble Sort: 7 segundos

Tempo demorado com Shell Sort: 0 segundos

*/

/*
Output que obtive para 80000 numeros:

Preenchendo o vetor1 com valores aleatorios de 0 a 50000 e copiando para o vetor2...

Tempo demorado com Bubble Sort: 19 segundos

Tempo demorado com Shell Sort: 1 segundos

*/