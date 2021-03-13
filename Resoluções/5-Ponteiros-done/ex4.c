#include <stdio.h>
#include <stdlib.h>

#define Y 2
#define X 2

int main(int argc, char *argv[]){

    int **A;
    int i, j;


    A = (int **)malloc(Y * sizeof(int *));

    for (i = 0; i < Y; i++) A[i] = (int *)malloc(X * sizeof(int));
    

    for (i = 0; i < Y; i++)
        for (j = 0; j < X; j++) A[i][j] = i + j;


    for (i = 0; i < Y; i++)
        for (j = 0; j < X; j++) printf("%d \t", A[i][j]);

    for (i = 0; i < Y; i++) free(A[i]);
    
    
    free(A);

    return 0;

}

/*Explicação pedida no exercício:

    Resultado: 0   1   1   2

    O programa fez uma alocação dinâmica de uma matriz quadrada 2x2.
    Preencheu ela com "A[i][j] = i + j;" dentro de 2 loops.
    E por fim imprimiu em uma linha só os elementos com tabulação entre eles.

*/