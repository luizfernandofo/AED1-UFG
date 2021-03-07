#include<stdlib.h>
#include<stdio.h>
#include<math.h>



/**
 * @brief Procura, através de recursão, o maior valor do vetor.
 * 
 * @param v endereço do vetor.
 * @param i Casa inicial do vetor.
 * @param j Casa inicial do vetor + 1.
 */
void highest(int *v, int i, int j);

int main(int argc, char *argv[]){

    int v[MAX];

    int i; //contadores

    for (i = 0; i < MAX; i++) v[i] = rand() % 100; //preenche o vetor com valores aleatórios
    
    printf("Vetor:\n[ ");
    for(i = 0; i < MAX; i++) printf("%d ", v[i]);
    printf("]\n\n");

    highest(v, 0, 1);

    printf("Maior valor do vetor: %d", v[0]);
    return 0;
}

//implementação das funções

void highest(int *v, int i, int j){

    int temp;

    if(j >= MAX)
    {
        j = i + 1 ;
        i++; 

        if(i >= MAX) return;

    }

    if(v[j]>v[i])
    {
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;

        highest(v, i, ++j);

    }else highest(v, i, ++j);

}
