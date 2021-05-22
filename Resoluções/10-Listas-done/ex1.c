#include<stdio.h>
#include<stdlib.h>

#ifdef _WIN32 // Includes both 32 bit and 64 bit
    #define CLS "cls"
    	    
#elif __linux__
    #define CLS "clear"

#endif

//============================================================================================

#define ELEMENTOS 10

int lista[2][ELEMENTOS]; //lista estática

//============================================================================================
//  FUNÇÕES
//============================================================================================

void pause(){

    setbuf(stdin, NULL);
    printf("\nPressione ENTER para continuar..."); //não pode ter "lixo" no stdin para ela funcionar
    getchar();

    return;
}

void addValor(int pos){

    int i; //contadores
    int val;

    system(CLS);

    printf("Informe o valor que deseja inserir na posicao %d: ", pos);
    scanf("%d", &val);

    for(i=pos-1; i>=0; i--){ //procura se há algum valor antes do novo valor para que ele tenha seu "próximo valor" setado para o novo valor.
        if(lista[0][i] != 0){
            lista[1][i] = pos;
            break;
        }
    }

    for(i=pos+1; i<ELEMENTOS; i++){ //acha o proximo valor da lista, a partir do novo valor, para o novo valor receber como "próximo valor".
        if(lista[0][i] != 0){
            lista[1][pos] = i;
            break;
        }
    }

    lista[0][pos] = val;

    printf("Valor %d adicionado com sucesso na posicao %d!\n", val, pos);

    return;
}

void removeValor(int pos){

    int i; //contadores

    for(i=pos-1; i>=0; i--){ 
        if(lista[0][i] != 0){
            lista[1][i] = lista[1][pos];
            break;
        }
    }

    printf("Valor %d deletado da posicao %d.\n", lista[0][pos], pos);

    lista[0][pos] = 0;
    lista[1][pos] = 0;

    return;
}

//============================================================================================
//  MAIN
//============================================================================================

int main(void){

    int i;
    int op=0;
    int pos, val;

    for(i=0; i<ELEMENTOS; i++) lista[0][i] = lista[1][i] = 0;

    while(op != 4){

        system(CLS);
        printf("----------- LISTA ENCADEADA DINAMICA -----------\n\n");
        printf("Lista:\n\n");

        printf("Posicoes:      |  ");
        for(i=0; i<ELEMENTOS; i++) printf("%d  ", i);

        printf("\n               |===================================");

        printf("\nValores:       |  ");
        for(i=0; i<ELEMENTOS; i++)printf("%d  ", lista[0][i]);

        printf("\n               |===================================");

        printf("\nProx elemento: |  ");
        for(i=0; i<ELEMENTOS; i++)printf("%d  ", lista[1][i]);

        printf("\n\n");
        printf("------------------------------------------------\n");
        printf("1 - Iniciar (limpar) lista.\n");
        printf("2 - Incluir elemento.\n");
        printf("3 - Excluir elemento.\n");
        printf("4 - Sair.\n");

        scanf("%d", &op);

        switch(op){
        case 1:
            system(CLS);
            printf("Inicializando/limpando lista...\n\n");
            for(i=0; i<ELEMENTOS; i++) lista[0][i] = lista[1][i] = 0;
            pause();
            break;
        
        case 2:
            system(CLS);
            printf("Posicao do elemento (0...9): ");
            scanf("%d", &pos);
            system(CLS);
            if(pos < ELEMENTOS && pos >= 0){

                if(lista[0][pos] != 0){
                    printf("Posicao ja contem um valor. Deseja sobrescrever?\n0 para cancelar ou 1 para continuar: ");
                    scanf("%d", &val);

                    if(val != 0) addValor(pos);

                }else addValor(pos);

            }else{

                printf("Posicao invalida!\n");
                
            }

            pause();
            break;

        case 3:
            system(CLS);
            printf("Posicao do elemento (0...9): ");
            scanf("%d", &pos);
            system(CLS);
            if(pos < ELEMENTOS && pos >= 0){

                if(lista[0][pos] == 0) printf("Posicao nao contem nenhum valor.\n");
                else removeValor(pos);
                    
            }else{

                printf("Posicao invalida!\n");
                
            }

            pause();
            break;
        
        case 4:
            system(CLS);
            printf("Encerrando programa...\n");
            op = 4; 
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