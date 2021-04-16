#include<stdio.h>

void quickSort(int vet[], int began, int tam){

    int i, j, k, pivo, aux;

    i = began;
    j = tam - 1;
    pivo = vet[(began + tam) / 2];

    printf("< ");
    for(k=0; k<10; k++){
        if(vet[k] == pivo) printf("*%d*, ", vet[k]);
        else printf("%d, ", vet[k]);
    }
    printf(">\n");

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

int main(void){

    int vet[10] = {5, 13, 7, 20, 12, 9, 1, 4, 18, 3};

    quickSort(vet, 0, 10);

    return 0;
}

/*
**Os asterísticos envolvem o pivô.**

Saída que obtive:

< 5, 13, 7, 20, 12, *9*, 1, 4, 18, 3, >
< 5, 3, *7*, 4, 1, 9, 12, 20, 18, 13, >
< 5, 3, *1*, 4, 7, 9, 12, 20, 18, 13, >
< 1, 3, *5*, 4, 7, 9, 12, 20, 18, 13, >
< 1, 3, *4*, 5, 7, 9, 12, 20, 18, 13, >
< 1, 3, 4, *5*, 7, 9, 12, 20, 18, 13, >
< 1, 3, 4, 5, *7*, 9, 12, 20, 18, 13, >
< 1, 3, 4, 5, 7, 9, 12, 20, *18*, 13, >
< 1, 3, 4, 5, 7, 9, 12, *13*, 18, 20, >
< 1, 3, 4, 5, 7, 9, 12, 13, 18, *20*, >

*/