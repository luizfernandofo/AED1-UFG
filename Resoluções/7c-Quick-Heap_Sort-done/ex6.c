#include<stdio.h>

void swap(char *a, char *b){

    char tmp = *a;
    *a = *b;
    *b = tmp;

}

void heapify(char arr[], int n, int i){

    int max = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    //if(arr[max] > 64 && arr[max] < 91) arr[max] += 32;
        
    //if(arr[leftChild] > 64 && arr[leftChild] < 91) arr[leftChild] += 32;    
    
    if (leftChild < n && arr[leftChild] < arr[max]) max = leftChild;

    //if(arr[rightChild] > 64 && arr[rightChild] < 91) arr[rightChild] += 32;
      
    if (rightChild < n && arr[rightChild] < arr[max]) max = rightChild;

    if (max != i){
        swap(&arr[i], &arr[max]);
        heapify(arr, n, max);
    }
}

void heapSort(char arr[], int n){

    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

//===============================================================

int main(void){

    char s[23+1] = "Ordenando com Heap Sort";

    printf("\nFrase ANTES da ordenacao decrescente com Heap Sort:\n");

    printf("\n%s.\n", s);

    heapSort(s, 23);

    printf("\nFrase DEPOIS da ordenacao decrescente com Heap Sort:\n");

    printf("\n%s.\n\n", s);    

    return 0;
}

/*
O espaço contido na frase foi incluido na ordenação.
Valor do espaço na tabela ascii = 32;
*/