#include<stdio.h>

#define VEC 5

int main(void){

    int i, j;//contadores

    int v[VEC] = {4,3,5,2,1},
        temp;

    printf("Antes do sort:\n");
    for(i=0; i<VEC; i++) printf("%d, ", v[i]);
    printf("\n\n");

    for(i=VEC-1; i>=1; i--){
        for(j=i-1; j>=0; j--){
            if(v[j] > v[i]){

                temp = v[j];
                v[j] = v[i];
                v[i] = temp;
            }
        }
    } 

    printf("Depois do sort:\n");
    for(i=0; i<VEC; i++) printf("%d, ", v[i]);
    printf("\n");

    return 0;
}

/*  A complexidade não muda pois ele continua com 2 loops: (n-1)*(n-1);
Saída:

Antes do sort:
4, 3, 5, 2, 1, 

Depois do sort:
1, 2, 3, 4, 5,
*/