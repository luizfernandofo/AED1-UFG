#include<stdlib.h>
#include<stdio.h>
#include<math.h>

double my_pow(int b, int e);

int main(int argc, char *argv[]){

    int b, e;

    printf("Informe a base e o expoente para obter a potencia: \n");

    scanf("%d %d", &b, &e);

    printf("%d^%d = %.3lf\n", b, e, my_pow(b,e));

    return 0;
}

//implementação das funções

double my_pow(int b, int e){

    if(e>1) b *= my_pow(b, --e);

    return b;
}