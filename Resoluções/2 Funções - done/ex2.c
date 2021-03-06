#include<stdlib.h>
#include<stdio.h>
#include<math.h>

double my_sqrt(double n);

int main(int argc, char *argv[]){

    double n;

    printf("Qual numero voce deseja calcular a raiz quadrada?\n");

    scanf("%lf", &n);

    printf("Raiz quadrada de %.3lf = %.3lf\n", n, my_sqrt(n));

    return 0;
}

//implementação das funções

double my_sqrt(double n){

    double x=1;
    int i;

    for(i=0; i<10; i++)
    {
        x = (x/2.0) + (n/(2*x));
    }

    return x;
}