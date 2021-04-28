#include<stdio.h>
#include<stdlib.h>

void quickSort(int vet[], int began, int tam){

    int i, j, pivo, aux;

    i = began;
    j = tam - 1;
    pivo = vet[(began + tam) / 2];

    while (i <= j){
        while (vet[i] < pivo && i < tam) i++;

        while (vet[j] > pivo && j > began) j--;
        
        if (i <= j){

            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;

            i++;
            j--;
            
        }
        
    }
    if (j > began) quickSort(vet, began, j + 1);
    
    if (i < tam) quickSort(vet, i, tam);
    
}

void sequencial(int vet[], int tam, int v){
    int i;
    int comp=0;
    char achou = 0;

    for(i=0; i<tam; i++){
        comp++;
        if(v == vet[i]){
            achou = 1;
            break;
        }
    }
    if(achou == 1) printf("Valor %d encontrado no indice %d.\nComparacoes: %d.\n", v, comp-1, comp);
    else if(achou == 0) printf("Valor nao encontrado no vetor.\nComparacoes: %d.\n", comp);

    return;
}

void binario(int vet[], int tam, int v){

    int begin = 0;
    int end = tam - 1;
    int i;
    int comp = 0;
    char achou = 0;

    while (begin < end){
        i = (begin + end) / 2;

        comp++;
        if(vet[i] == v){
            achou = 1;
            break;
        }
        
        if(vet[i] < v) begin = i + 1;
        else end = i;
        
    }
    if(achou == 1) printf("Valor %d encontrado no indice %d.\nComparacoes: %d.\n", v, i, comp);
    else if(achou == 0) printf("Valor nao encontrado no vetor.\nComparacoes: %d.\n", comp);

    return;
}

int main(void){

    int *vet = NULL, tam;
    int i;
    int v;

    printf("Qual o tamanho do vetor a ser lido?: ");
    scanf("%d", &tam);

    vet = malloc(sizeof(int)*tam);
    if(vet == NULL){
        printf("Falha na alocacao do vetor.\n");
        return 0;
    }

    for(i=0; i<tam; i++){
        printf("Elemento %d/%d: ", i+1, tam);
        scanf("%d", &vet[i]);
    }
    
    printf("\n");
    quickSort(vet, 0, tam);
    printf("Ordenando vetor...\n");
    printf("\n");

    printf("Valor a ser procurado no vetor: ");
    scanf("%d", &v);

    printf("\nSequencial:\n");
    sequencial(vet, tam, v);
    printf("\n");

    printf("Binario:\n");
    binario(vet, tam, v);
    printf("\n");

    /*for(i=0; i<tam; i++){
        printf("%d, ", vet[i]);
    }
    printf("\n");*/

    free(vet);

    return 0;
}
