#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main(int argc, char *argv[]){

    int size, *array=NULL;
    int i; //contadores

    printf("Informe um tamanho para o vetor: \n");

    scanf("%d", &size);

    array = (int *) malloc(sizeof(int)*size);
    if(array == NULL)
    {
        printf("Falha na malloc do vetor!\n");
        return 0;
    }

    for(i=0; i<size; i++) *(array+i) = rand() % 10; //preenche o vetor aleatoriamente;
    
    printf("Vetor de tamanho %d preenchido:\n[ ", size);

    for(i=0; i<size; i++) printf("%d ", *(array+i)); //preenche o vetor aleatoriamente;

    printf("]\n");

    free(array);

    return 0;
}