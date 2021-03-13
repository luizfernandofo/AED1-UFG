#include<stdio.h>

#define PI 3.14159

void circle(double r, double *p, double *a);

int main(int argc, char const *argv[]){

    double r, perimetro, area;

    printf("Digite o raio de uma circunferencia: ");
    scanf("%lf", &r);

    circle(r, &perimetro, &area);

    printf("\nRaio: %lf\nPerimetro: %lf\nArea: %lf\n", r, perimetro, area);

    return 0;
}

//Implementação das funções

void circle(double r, double *p, double *a){

    (*a) = (PI*r*r)/2.0;
    (*p) = 2*PI*r;

    return;

}

