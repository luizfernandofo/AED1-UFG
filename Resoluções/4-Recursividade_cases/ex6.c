#include<stdlib.h>
#include<stdio.h>
#include<math.h>

//Retorna a radiciação do número n com precisão "error"
double my_sqrt(double n, double x);

//Retorna o módulo de x
double modulo(double x);

int main(int argc, char *argv[]){

    double n;

    printf("Qual numero voce deseja calcular a raiz quadrada?\n");

    scanf("%lf", &n);

    printf("Raiz quadrada de %.4lf = %.4lf\n", n, my_sqrt(n, 1)); 
    
    return 0; 
}

//implementação das funções

double my_sqrt(double n, double x){ 

    double error = 0.0001;

    if(modulo(n - (x*x)) <= error) return x; //condição de parada

    x = (x/2.0) + (n/(2.0*x));
    
    return my_sqrt(n, x);
    
}

double modulo(double x){

    if(x > 0) return x;
    else return -x;

}