#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int *vet;
    int tam;
}vetIndices;


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

vetIndices sequencial(int vet[], int tam, int v){
    int i;

    vetIndices v1;
    int *temp=NULL; 

    v1.vet = NULL;
    v1.tam = 0;

    for(i=0; i<tam; i++){

        if(v == vet[i]){
            v1.tam++;
            temp = (int *) realloc((void *) v1.vet, sizeof(int)*v1.tam);
            if(temp != NULL){
                v1.vet = temp;
                temp = NULL;
                v1.vet[v1.tam-1] = i;

            }else{
                printf("Falha na realocacao do vetor de indices sequencial.\n");
                exit(1);
            }
            
        }
    }

    return v1;
}

vetIndices binario(int vet[], int tam, int v){

    int begin = 0;
    int end = tam - 1;
    int i, left_i, right_i;
    vetIndices v1;
    int *temp=NULL; 

    v1.vet = NULL;
    v1.tam = 0;

    while (begin <= end){
        i = (begin + end) / 2;

        if(vet[i] == v){
            
            v1.tam++;
            temp = (int *) realloc((void *) v1.vet, sizeof(int)*v1.tam);
            if(temp != NULL){
                v1.vet = temp;
                temp = NULL;
                v1.vet[v1.tam-1] = i;

            }else{
                printf("Falha na realocacao do vetor de indices binario.\n");
                exit(1);
            }
            
            right_i = i + 1;
            left_i = i - 1;

            while (right_i < tam-1)
            {
                if(vet[right_i] == v){
                    v1.tam++;
                    temp = (int *) realloc((void *) v1.vet, sizeof(int)*v1.tam);
                    if(temp != NULL){
                        v1.vet = temp;
                        temp = NULL;
                        v1.vet[v1.tam-1] = right_i;

                    }else{
                        printf("Falha na realocacao do vetor de indices binario.\n");
                        exit(1);
                    }

                }else break;

                right_i++;
            }

            while (left_i >= 0)
            {
                if(vet[left_i] == v){
                    v1.tam++;
                    temp = (int *) realloc((void *) v1.vet, sizeof(int)*v1.tam);
                    if(temp != NULL){
                        v1.vet = temp;
                        temp = NULL;
                        v1.vet[v1.tam-1] = left_i;

                    }else{
                        printf("Falha na realocacao do vetor de indices binario.\n");
                        exit(1);
                    }

                }else break;

                left_i--;
            }
            
            return v1;

        }
        
        if(vet[i] < v) begin = i + 1;
        else end = i;
        
        if(begin==end && end==i) break;
    }

    return v1;
}

int main(void){

    int *vet = NULL, tam;
    int i;
    int v;
    vetIndices seq, bin;

    printf("Qual o tamanho do vetor a ser lido?: ");
    scanf("%d", &tam);

    vet = (int *) malloc(sizeof(int)*tam);
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

    printf("<");
    for(i=0; i<tam-1; i++) printf("%d, ", vet[i]);
    printf("%d>\n\n", vet[tam-1]);

    printf("Valor a ser procurado no vetor: ");
    scanf("%d", &v);

    printf("\nSequencial:\n");
    seq = sequencial(vet, tam, v);

    if(seq.vet != NULL){
        quickSort(seq.vet, 0, seq.tam);
        printf("Indices contendo o valor %d:\n<", v);
        for(i=0; i<seq.tam-1; i++) printf("%d, ", seq.vet[i]);
        printf("%d>\n\n", seq.vet[seq.tam-1]);
    }else printf("Valor nao encontrado no vetor.\n\n");

    printf("Binario:\n");
    bin = binario(vet, tam, v);

    if(bin.vet != NULL){
        quickSort(bin.vet, 0, bin.tam);
        printf("Indices contendo o valor %d:\n<", v);
        for(i=0; i<bin.tam-1; i++) printf("%d, ", bin.vet[i]);
        printf("%d>\n", bin.vet[bin.tam-1]);
    }else printf("Valor nao encontrado no vetor.\n\n");

    free(vet);
    free(seq.vet);
    free(bin.vet);

    return 0;
}
