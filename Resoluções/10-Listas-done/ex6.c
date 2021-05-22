#include<stdio.h>
#include<stdlib.h>

#ifdef _WIN32 // Includes both 32 bit and 64 bit
    #define CLS "cls"
    	    
#elif __linux__
    #define CLS "clear"

#endif

typedef struct Node{

    struct Node *next;
    int value;

}node;


typedef struct{

    node *headList;
    node *tailList;
    int size;

}lista;

lista makeList();

void addNode(lista *list, int value);

void printList(lista *list);

void freeList(lista *list);

void remove_position(lista *list, int val);

void remove_value(lista *list, int val);

void pause();

void addNodePosition(lista *list, int pos);

//=======================================================================

int main(void){

    int val;

    int op=0;

    lista list;

    list = makeList();

    while(op != 5){

        system(CLS);
        printf("----------- LISTA DINAMICA ENCADEADA CIRCULAR -----------\n\n");
        printf("Lista:\n\n");
        printList(&list);
        printf("End. cabeca: %p\nEnd. cauda: %p\n\n",list.headList, list.tailList);
        printf("------------------------------------------------\n");
        printf("1 - Adicionar nodo.\n");
        printf("2 - Adicionar nodo por posicao.\n");
        printf("3 - Excluir nodo por valor.\n");
        printf("4 - Excluir nodo por posicao.\n");
        printf("5 - Sair.\n");

        scanf("%d", &op);

        switch(op){

            case 1:
                system(CLS);
                printf("Valor do nodo a ser adicionado: ");
                scanf("%d", &val);
                addNode(&list, val);
                pause();
                break;
            
            case 2:
                system(CLS);
                printf("Posicao do nodo a ser adicionado: ");
                scanf("%d", &val);
                addNodePosition(&list, val);
                pause();
                break;

            case 3:
                system(CLS);
                printf("Valor do nodo a ser excluido: ");
                scanf("%d", &val);
                remove_value(&list, val);
                pause();
                break;

            case 4:
                system(CLS);
                printf("Posicao do nodo a ser excluido: ");
                scanf("%d", &val);
                remove_position(&list, val);
                pause();
                break;
            
            case 5:
                system(CLS);
                printf("Limpando lista...\n");
                op = 5;
                freeList(&list); 
                pause();
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

lista makeList(){

    lista l;

    l.headList = NULL;
    l.tailList = NULL;
    l.size = 0;

    return l;
}

void addNode(lista *list, int value){

    node *tempNode=NULL;

    if(list->size == 0){

        tempNode = (node *) malloc(sizeof(node));

        if(tempNode != NULL){
            tempNode->next = tempNode;
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
            
            list->tailList->next = tempNode;

            list->tailList = tempNode;

            tempNode->next = list->headList;

            tempNode->value = value;

        }else{
            printf("Falha na alocacao de um nodo.\n");
            exit(1);
        } 

        list->size++;

    }

    printf("Node %d adicionado.\n", list->size);

    return ;
}

void printList(lista *list){

    node *tempNode=NULL;

    int i;

    i = list->size;

    tempNode = list->headList;

    printf("%d elemento(s) na lista: <", list->size);
    while(i > 0){
        printf("%d, ", tempNode->value);

        tempNode = tempNode->next;

        i--;
    }
    printf(">\n\n");
    return ;
}

void freeList(lista *list){

    node *tempNode=NULL;

    
    while(list->size != 0){
        
        tempNode = list->headList;
        
        list->headList = list->headList->next;
        
        free(tempNode);

        list->size--;
    }


}

void remove_position(lista *list, int val){

    node *tempNode=NULL, *nodeAnterior=NULL;

    char removed = 0;

    tempNode = list->headList;

    if(list->size > 0){ //executa caso a lista possuir nós

        if(val == 1){

            if(list->headList->next != list->headList){ //verifica se o próximo elemento é a cabeça da lista
                list->headList = list->headList->next;

                list->tailList->next = list->headList;

                list->size--;

                val = tempNode->value;

                free(tempNode); //libera o elemento

                removed = 1;
                
            }
            else{ //caso não haja ele irá remover a cabeça que também era a cauda e setar a lista.

                list->headList = NULL;
                list->tailList = NULL;
                list->size=0;

                val = tempNode->value;

                free(tempNode); //libera o elemento

                removed = 1;

            }

        }else if(val <= list->size){

            while(tempNode->next != list->headList){
                
                nodeAnterior = tempNode;
                tempNode = tempNode->next;

                val--;

                if(val == 1){

                    if(tempNode->next == list->headList){ //verifica se o elemento possui outro na frente ou se é o último
                        nodeAnterior->next = list->headList;
                        list->tailList = nodeAnterior;

                    }else nodeAnterior->next = tempNode->next;

                    list->size--;

                    val = tempNode->value;

                    free(tempNode); //libera o elemento

                    removed = 1; //sinaliza que o valor foi removido

                    break;
                    
                }

            }

        }
    }

    if(removed == 1) printf("Valor %d removido da lista.\n\n", val);
    else printf("Posicao informada e invalida.\n\n");

    return ;
}

void remove_value(lista *list, int val){

    node *tempNode=NULL, *nodeAnterior=NULL; //nodeAnterior servirá para armazenar o endereço do nó anterior ao que estiver sendo avaliado para o caso dele ser removido.
    
    char removed = 0;

    tempNode = list->headList; //endereço temporário recebe o endereço da cabeça da lista

    do{
        
        if(tempNode->value == val){ 
            
            if(tempNode == list->headList){ //verifica se o elemento que será removido é a cabeça da lista

                if(list->headList->next != list->headList){ //verifica se o próximo elemento é a cabeça da lista

                list->headList = list->headList->next;

                list->tailList->next = list->headList;

                list->size--;

                val = tempNode->value;

                free(tempNode); //libera o elemento

                removed = 1;

                tempNode = list->headList; //re-seta a temporária para continuar procurando na lista por mais elementos repetidos

                continue;
                
                }else{ //caso não haja ele irá remover a cabeça que também era a cauda e setar a lista.

                    list->headList = NULL;
                    list->tailList = NULL;
                    list->size=0;

                    val = tempNode->value;

                    free(tempNode); //libera o elemento

                    removed = 1;

                    break;
                }

            }else{ //caso o elemento não seja a cabeça
                
                if(tempNode->next == list->headList){ //verifica se o elemento possui outro na frente ou se é o último
                    nodeAnterior->next = list->headList;
                    list->tailList = nodeAnterior;

                }else nodeAnterior->next = tempNode->next; 

                removed = 1;
            
                list->size--;

                free(tempNode); //libera o elemento

                tempNode = nodeAnterior; //re-seta a temporária para continuar procurando na lista por mais elementos repetidos

            }
        }

        if(tempNode->next == list->headList) break;

        nodeAnterior = tempNode;
        tempNode = tempNode->next;

    }while(1);

    if(removed == 1) printf("Valor %d removido da lista.\n\n", val);
    else printf("Valor nao encontrado na lista.\n\n");

    return;
}

void pause(){

    setbuf(stdin, NULL);
    printf("\nPressione ENTER para continuar..."); //não pode ter "lixo" no stdin para ela funcionar
    getchar();

    return;
}

void addNodePosition(lista *list, int pos){

    node *tempNode=NULL, *tempNodeWhile=NULL, *anterior=NULL;

    int i; //contadores

    int value;

    i=pos;

    system(CLS);

    if(list->size == 0 && pos == 1){ //verifica se a lista está vazia e a posição desejada é a primeira. Neste caso o nodo será adicionado como primeiro elemento

        printf("Qual o valor que deseja adicionar na posicao %d: ", pos);

        scanf("%d", &value);

        tempNode = (node *) malloc(sizeof(node));

        if(tempNode != NULL){
            tempNode->next = tempNode;
            tempNode->value = value;

            list->headList = list->tailList = tempNode;

        }else{
            printf("Falha na alocacao de um nodo.\n");
            exit(1);
        }

        list->size++;


    }else if(pos == list->size+1){ //verifica a posição desejada é a última. Neste caso o nodo será adicionado como último elemento

        printf("Qual o valor que deseja adicionar na posicao %d: ", pos);

        scanf("%d", &value);

        tempNode = (node *) malloc(sizeof(node));

        if(tempNode != NULL){

            tempNode->value = value;

            list->tailList->next = tempNode;

            tempNode->next = list->headList;

            list->tailList = tempNode;

        }else{
            printf("Falha na alocacao de um nodo.\n");
            exit(1);
        }

        list->size++;

    }else if(pos <= list->size && pos > 0){ //caso nenhuma condição acima for verdadeira será feito a busca até a posição do elemento e será incluído um no seu lugar, movendo o 
    // elemento em questão para frente. Ex: se a posição selecionada for 4, e existir um elemento nesta posição, um novo elemento será colocado no lugar do elemento anterior que será movido para frente.

        printf("Qual o valor que deseja adicionar na posicao %d: ", pos);

        scanf("%d", &value);

        tempNodeWhile = list->headList;

        do{

            if(i==1){

                tempNode = (node *) malloc(sizeof(node));
                
                if(tempNode != NULL){
                    
                    tempNode->value = value;

                    if(tempNodeWhile == list->headList){

                        list->headList = tempNode;
                        tempNode->next = tempNodeWhile;  

                    }else{

                        anterior->next = tempNode;
                        tempNode->next = tempNodeWhile;

                    }

                    list->size++;

                    break;

                }else{
                    printf("Falha na alocacao de um nodo.\n");
                    exit(1);
                }
            }

            i--;
            
            anterior = tempNodeWhile;
            tempNodeWhile = tempNodeWhile->next;

        }while(i!=0);

    }else printf("Posicao informada invalida!\n\n");

    return;
}