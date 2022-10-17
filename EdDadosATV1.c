#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <math.h>

struct Comanda {
    int n_comanda;
    int n_item_comanda;
    int qtd_produtos;
    float valor_unitario;
};

struct Data {
    int dia;
    int mes;
    int ano;

};

typedef struct Cliente{
    char nome_cliente[40];
    struct Comanda comanda;
    struct Data data_comanda;
    struct Cliente *PROX;
}cad_cliente;

int main(void){
    setlocale(LC_ALL, "Portuguese");
    cad_cliente *a;
    a = malloc(sizeof(cad_cliente));
    a -> PROX = NULL;
    cad_cliente *inicio = a;
    cad_cliente *mant = a;
    int i = 0;
    int b;
    int d = 1;
    printf("\n\n------- Cadastro dos clientes -------\n\n");
    while(d == 1){
            printf("\n\nO que deseja fazer?\n[1]Registrar uma comanda\n[2]Exibir as comandas\n[3]Fechar programa\n----->");
            scanf("%i",&b);
            while(b == 1){
        printf("\n\nNome do cliente ----->");
        scanf("%s",&a->nome_cliente);

        printf("\nDigite o dia de hoje ----->");
        scanf("%i",&a->data_comanda.dia);

        printf("\nDigite o mês atual ----->");
        scanf("%i",&a->data_comanda.mes);

        printf("\nDigite o ano atual ----->");
        scanf("%i",&a->data_comanda.ano);

        printf("\nDigite o número da comanda ----->");
        scanf("%i",&a->comanda.n_comanda);

        printf("\nDigite o número de item da comanda ----->");
        scanf("%i",&a->comanda.n_item_comanda);

        printf("\nDigite a quantidade de produtos ----->");
        scanf("%i",&a->comanda.qtd_produtos);

        printf("\nDigite o valor unitario ----->");
        scanf("%f",&a->comanda.valor_unitario);


        printf("\n\nDeseja continuar registrando?\n[1]Continuar registro\n[2]Exibir Informações armazenadas\n[3]Voltar ao menu inicial\n----->");
        scanf("%i",&b);

            a->PROX = malloc(sizeof(cad_cliente));
            a = a->PROX;

    }
    if(b == 2){
        inicio = mant;
        while(inicio->PROX!=NULL){

        printf("\n\n------- Dados dos clientes -------\n\n");

        printf("\nNome --- %s",inicio->nome_cliente);
        printf("\nData %i/%i/%i",inicio->data_comanda.dia,a->data_comanda.mes,a->data_comanda.ano);
        printf("\nNúmero da comanda --- %i",inicio->comanda.n_comanda);
        printf("\nNúmero de item da comanda --- %i",inicio->comanda.n_item_comanda);
        printf("\nQuantidade de produtos --- %i",inicio->comanda.qtd_produtos);
        printf("\nValor Unitario --- %.2f",inicio->comanda.valor_unitario);

        inicio = inicio -> PROX;

    }
    }
    if(b == 3){
        printf("\nSaindo.........");
        return 0;
    }

    }
    return 0;


}
