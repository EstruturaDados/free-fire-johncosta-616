//     BIBLIOTECAS     //
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//     DEFINIÇÕES      //
#define LIMITE_ITENS 10

//     STRUCT     //
typedef struct {
    char nome[30];
    char tipo[30];
    int quantidade;
    //struct Item* proximo;
}Item;

//     FUNÇÕES VOID DO SISTEMA      //

void inserirItem(Item mochila[], int* total_itens){

    if (*total_itens >= LIMITE_ITENS) {
        printf("\n*Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    printf("Digite o nome do item: ");
    scanf("%s", mochila[*total_itens].nome);

    printf("Digite o tipo do item: ");
    scanf("%s", mochila[*total_itens].tipo);

    printf("Digite a quantidade: ");
    scanf("%d", &mochila[*total_itens].quantidade);

    (*total_itens)++;
    printf("Item cadastrado com sucesso!\n\n");
}

void removerItem(Item mochila[], int* total_itens){

    if(*total_itens == 0){
        printf("Não há itens a serem removidos da mochila.\n\n");
        return;
    }

    //variáveis importantes
    char nome_item_a_ser_removido[30];
    int encontrado = 0;

    printf("Escreva o nome do item que será removido: ");
    scanf("%s", nome_item_a_ser_removido);

    for(int i = 0; i < *total_itens; i++){

        if(strcmp(mochila[i].nome, nome_item_a_ser_removido) == 0){

            for (int j = i; j < *total_itens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }

            (*total_itens)--;  // Reduz o total de itens
            encontrado = 1;
            break;
        }
    }

    if(encontrado == 1){
        printf("O item '%s' foi removido com sucesso!\n\n", nome_item_a_ser_removido);
    }
     else {
        printf("O Item '%s' não foi encontrado na mochila.\n\n", nome_item_a_ser_removido);
    }
}

void listarItens(Item mochila[], int* total_itens){

    for(int i = 0; i < *total_itens; i++){
        printf("Item %d : %s\n", i + 1, mochila[i].nome);
        printf("------------------------\n");
    }

}
void buscarItem(Item mochila[], int* total_itens){
    char item_a_ser_buscado[40];
    int encontrado = 0;
    int indice = -1;

    printf("Digite o nome do item que você deseja procurar: ");
    scanf("%s", item_a_ser_buscado);

    for(int i = 0; i < *total_itens; i++){

        if(strcmp(item_a_ser_buscado, mochila[i].nome) == 0){
            encontrado = 1;
            indice = i;
            break;
        }
    }

    if(encontrado){
        printf("------------------------\n");
        printf("Item encontrado!\n");
        printf("Nome do item: %s\n", item_a_ser_buscado);
        printf("O tipo de item: %s\n", mochila[indice].tipo);
        printf("Quantidade: %d\n", mochila[indice].quantidade);
        printf("------------------------\n");
    } else {
        printf("Item '%s' não encontrado na mochila.\n", item_a_ser_buscado);
    }
}

//MAIN
int main(){
    // VARIÁVEIS IMPORTATNES
    int opcao_do_usuario;
    Item mochila[LIMITE_ITENS];
    int total_itens = 0;

    do{
        // INTERFACE GRÁFICA DO PROGRAMA:
        printf("\n======= SEJA BEM-VINDO AO FREE FIRE ======= \n");
        printf("\nMENU:\n");
        printf("1 - Cadastar item\n");
        printf("2 - Listar itens\n");
        printf("3 - Buscar item\n");
        printf("4 - Remover item\n");
        printf("5 - Sair do programa\n");
        printf("Escolha a sua opção:");
        scanf("%d", &opcao_do_usuario);

        switch (opcao_do_usuario){
            case 1:
                printf("\n*Cadastro de itens: \n");
                inserirItem(mochila, &total_itens);
                break;
            case 2:
                printf("\n*Itens da sua lista:\n");
                listarItens(mochila, &total_itens);
                break;
            case 3:
                printf("\n*Busca de itens: \n");
                buscarItem(mochila, &total_itens);
                break;
            case 4:
                printf("\n*Remoção de itens: \n");
                removerItem(mochila, &total_itens);
                break;
            case 5:
                printf("\n*Você escolheu sair do programa\n");
                break;
            default:
                printf("*Opção inválida! tente uma das opções acima.\n");
                break;
        }
    }while (opcao_do_usuario != 5);
    
    return 0;
}
