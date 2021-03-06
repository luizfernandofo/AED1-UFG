#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main(int argc, char *argv[]){

    int i; //contadores

    unsigned int fatorial=1, n;

    double result=0;

    printf("Informe um valor natural para n: \n");

    scanf("%u", &n);

    for(i=1; i<=n; i++)
    {
        result += 1.0/fatorial;
        fatorial *= (i+1);
    }

    printf("Somatorio: %lf\n", result);

    return 0;
}