#include<stdlib.h>
#include<stdio.h>

/*References:
    https://www.youtube.com/watch?v=rf6uf3jNjbo&ab_channel=Reducible
    
    https://sites.google.com/a/liesenberg.biz/cjogos/home/materiais-de-apoio/topicos-relativos-a-c/recursao/torre-de-hanoi
*/

void hanoi(int n, char a, char b, char c){

    if(n == 1) printf("Mova o disco %d de %c para %c\n", n, a, c);
    else{
        hanoi(n - 1, a, c, b);
        printf("Mova o disco %d de %c para %c\n", n, a, c);
        hanoi(n - 1, b, a, c);
    }    

}

//Torre de Hanoi
int main(void){

    int n;

    printf("Insira o numero de discos: ");
    scanf("%d", &n);

    hanoi(n, 'A', 'B', 'C');

    return 0;
}

//implementação das funções

