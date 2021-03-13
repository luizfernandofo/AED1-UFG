#include<stdio.h>
#include<string.h>

#define SIZE 300

int acha_inicio(char *str1, char *str2);

int main(int argc, char const *argv[]){
    
    char str1[SIZE], str2[SIZE];  
    char *resp=NULL;
    int ret;

    memset(str1, 0, SIZE);
    memset(str2, 0, SIZE);

    printf("Escreva a string1:\n");
    scanf("%299[^\n]", str1);
    setbuf(stdin, NULL);
    printf("Escreva a string2:\n");
    scanf("%299[^\n]", str2);

    ret = acha_inicio(str1, str2);

    if (ret != -1)
    {
        resp = &str1[ret];
        printf("\nO inicio da string2 na string1 e:\nIndice: %d\nEndereco: %p\n", ret, (*resp));
    }else printf("A string2 nao esta na string1.\n");
    

    return 0;
}

//Implementação das Funções

int acha_inicio(char *str1, char *str2){

    int i,j,c=0; //contadores

    for(i=0; str1[i]!=0; i++)
    {
        c=0;
        for(j=0; str2[j]!=0; j++)
        {
            if(str1[i+j]!=0 && str2[j]==str1[i+j]) c++;
        }
        if(strlen(str2) == c) return i;
    }
     
    return -1;
}