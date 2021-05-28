#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//=======================================================================
//=======================================================================

//Tamanho da string
#define BUFF 100

//=======================================================================
//=======================================================================

#ifdef _WIN32 // Includes both 32 bit and 64 bit
    #define CLS "cls"
    	    
#elif __linux__
    #define CLS "clear"

#endif

//=======================================================================
//=======================================================================

typedef struct Node{

    struct Node *next;
    double value;

}node;


typedef struct{

    node *headList;
    node *tailList;
    int size;

}Pilha;

void makeList(Pilha *l);

void push(Pilha *list, double value);

void pop(Pilha *list);

void freeList(Pilha *list);

void pause();

void operation(Pilha *list, Pilha *result, const char operator);

//=======================================================================
//=======================================================================

char string[BUFF];

//=======================================================================
//=======================================================================


int main(void){

    int i, j;

    int op=-1;
    
    char lastOp;

    Pilha list;

    Pilha result;

    makeList(&list);

    makeList(&result);

    while(op != 0){

        system(CLS);
        printf("----------- CALCULADORA POS-FIXADA -----------\n\n");

        if(list.headList != NULL) printf("Resultado: \t\t %.2lf\n\n", list.headList->value);
        /*else*/ if(result.headList != NULL) printf("Resultado: \t\t %.2lf\n\n", result.headList->value);
        else printf("Resultado:\n\n");
        printf("------------------------------------------------\n");
        printf("1 - Nova operacao.\n");
        printf("0 - Sair.\n");

        scanf("%d", &op);

        switch(op){
            case 1:

                //garante que as 2 pilhas estão vazias 
                if(list.size > 0) freeList(&list);
                if(result.size > 0) freeList(&result);
                
                //limpa a memoria da string 
                memset(string, 0, sizeof(char)*BUFF);

                printf("Informe uma operacao pos-fixada de inteiros: ");
                setbuf(stdin, NULL);
                fgets(string, BUFF, stdin); //lê a string
            
                string[strlen(string) - 1] = '\0'; //tira o caracter '\n'

                i=0;
                while(string[i] != '\0'){

                    //verifica se o caracter é um numero ou se é um sinal que precede um numero
                    if((string[i] >= 48 && string[i] <= 57) || ((string[i] == '+' || string[i] == '-') && (string[i+1] >= 48 && string[i+1] <= 57))){
                        
                        //empilhamento dos valores 
                        push(&list, atof(string));

                        //calcula quantos caracteres da string até o próximo espaço depois do número lido pela func atof() para que sejam convertidos em caracteres de espaço
                        //caso contrário o atof não funciona
                        j=i+1;
                        while(((string[j] >= 48 && string[j] <= 57) || string[j] == '.') && string[j] != '\0') j++;

                        //converte os caracteres necessários em espaços
                        memset(string, 32, sizeof(char)*j);
                        
                        //i recebe o valor de j para continuar a busca à partir do número lido
                        i = j;

                    //caso a condição acima nao for verdade e um sinal de operação for encontrado irá iniciar o desempila
                    }else if(string[i] == '*' || string[i] == '+' || string[i] == '-' || string[i] == '/'){
                        
                        //chamada da função que irá executar a operação dos números contidos na pilha até o primeiro operador ter sido encontrado na string
                        operation(&list, &result, string[i]);

                        //o operador é armazenado para quando ele for o último ele poder ser usado na útima chamada da operation();
                        lastOp = string[i];

                        string[i] = ' ';
                        
                    }else i++;

                }
                
                //última chamada para garantir que, caso um número for colocado sozinho, exemplo: 1 2 + 3 +
                //a conta funcione e não fique 3 em um pilha e 3 em outra
                operation(&result, &list, lastOp);

                break;

            case 0:
                system(CLS);
                printf("Limpando Pilha...\n");
                op = 0;
                freeList(&list);
                freeList(&result); 
                break;

            default: 
                system(CLS);
                printf("Opcao invalida!\n");
                pause();
                break;
        }
    }

    return 0;
}

//=======================================================================

void makeList(Pilha *l){

    l->headList = NULL;
    l->tailList = NULL;
    l->size = 0;

    return;
}

void push(Pilha *list, double value){

    node *tempNode=NULL;

    if(list->size == 0){

        tempNode = (node *) malloc(sizeof(node));

        if(tempNode != NULL){
            tempNode->next = NULL;
            tempNode->value = value;

            list->headList = list->tailList = tempNode;

        }else{
            printf("Falha na alocacao de um nodo.\n");
            exit(1);
        }

        list->size++;
        
    }else{

        tempNode = (node *) malloc(sizeof(node));

        if(tempNode != NULL){

            tempNode->next = NULL;

            tempNode->value = value;
            
            list->tailList->next = tempNode;

            list->tailList = tempNode;

        }else{
            printf("Falha na alocacao de um nodo.\n");
            exit(1);
        } 

        list->size++;

    }

    return ;
}

void pop(Pilha *list){

    node *tempNode=NULL;

    if(list->size == 0){

        list->headList = NULL;
        list->tailList = NULL;

        list->size = 0;

    }else if(list->size == 1){

        free(list->headList);

        list->headList = NULL;
        list->tailList = NULL;

        list->size = 0;

    }else if(list->size > 1){

        tempNode = list->headList;

        list->headList = list->headList->next;

        free(tempNode);

        list->size--;

    }

    return;
}

void freeList(Pilha *list){

    while(list->size != 0) pop(list);

    return;
}

void pause(){

    setbuf(stdin, NULL);
    printf("\nPressione ENTER para continuar..."); //não pode ter "lixo" no stdin para ela funcionar
    getchar();

    return;
}

void operation(Pilha *list, Pilha *result, const char operator){

    double res;

    if(list->size != 0){ //inicia caso a lista tenha no minimo 2 elementos 

        res = list->headList->value;

        pop(list);

        while(list->headList != NULL){

            if(operator == '+') res += list->headList->value;
            
                else if(operator == '-') res -= list->headList->value;

                    else if(operator == '*') res *= list->headList->value;

                        else if(operator == '/') res /= list->headList->value;

            pop(list);
        }

        push(result, res);

    }else operation(result, list, operator); //caso a função for chamada por que foi encontrado um operador final, 
    //ela chamará ela recursivamente, porém com o as pilhas trocadas e a operação irá se iniciar com os elementos que estavam na result
    
    return;

}