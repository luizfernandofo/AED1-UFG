#include<stdlib.h>
#include<stdio.h>
#include<math.h>

float my_sqrt(float n, float x);

float modulo(float x);

int main(int argc, char *argv[]){

    float n, resp;

    printf("Qual numero voce deseja calcular a raiz quadrada?\n");

    scanf("%f", &n);

    resp = my_sqrt(n, 1);

    printf("Raiz quadrada de %.3f = %f\n", n, resp);

    return 0; 
}

//implementação das funções

float my_sqrt(float n, float x){

    float error = 0.0001;

    printf("%.15f\n", x);
    if(modulo(n - (x*x)) <= error) return x; //condição de parada

    x = (x/2.0) + (n/(2.0*x));
    
    //system("pause");
    my_sqrt(n, x);
    
    printf("pos: %.15f\n", x);
}

float modulo(float x){

    if(x > 0) return x;
    else return -x;

}