#include<stdlib.h>
#include<stdio.h>
#include<math.h>

double y=1;

int main(int argc, char *argv[]){

    int x;
    unsigned int fatorial=2;
    int i; //contadores

    printf("Informe um valor natural para x: \n");

    scanf("%d", &x);

    for(i=1; i<=x; i++)
    {
        y += (i*pow(x,(i+1)))/fatorial;
        fatorial *= (i+2);
    }

    printf("Y: %.3lf\n", y);

    return 0;
}