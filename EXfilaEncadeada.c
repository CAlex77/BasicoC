#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Carlos Alexandre Fernandes Façanha TADS 2 Periodo 16/10/2022
Exercicio de Fila Encadeada
*/
typedef struct cliente{
    int cpf;
    struct tm *data_entrega;
    struct cliente *proximo;
}TCliente;

typedef struct {
    TCliente *inicio;
    int tam;
}Lista;

void inserirCliente(Lista *lista, int cpf, struct tm *data_entrega);
void imprimir(Lista lista);
void removerCliente(Lista *lista, int dia_atual);

void inserirCliente(Lista *lista, int cpf, struct tm *data_entrega){
    TCliente *aux, *novo = (TCliente*)malloc(sizeof(TCliente));

    novo -> cpf = cpf;
    novo -> data_entrega = data_entrega;
    novo -> proximo = NULL;

    if(lista -> inicio == NULL){
        lista -> inicio = novo;
    }
    else{
        aux = lista -> inicio;

        while(aux -> proximo != NULL){
            aux = aux -> proximo;
        }
        aux -> proximo = novo;
    }
    lista ->tam++;
}
void removerCliente(Lista *lista, int dia_atual){
	TCliente *inicio = lista -> inicio;

	if(inicio != NULL && inicio -> data_entrega -> tm_yday < dia_atual){
		lista -> inicio = inicio -> proximo;
		free(inicio);
		lista -> tam--;
	}
}
TCliente* removerManualmente(Lista *lista, int num){
    TCliente *aux,*remover = NULL;
    if(lista->inicio){
        if(lista->inicio->cpf == num){
            remover = lista ->inicio;
            lista->inicio = remover->proximo;
            lista->tam--;
        }else{
            aux = lista->inicio;
            while(aux->proximo && aux->proximo->cpf != num)
                aux = aux->proximo;
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo=remover->proximo;
                lista->tam--;
            }
        }
    }
    return remover;
}

void imprimir(Lista lista){
   TCliente *novo = lista.inicio;

    printf("\n** CLIENTES **\n");
    printf("\nQuantidade de clientes registrados: %d\n", lista.tam);

    while(novo != NULL){
        printf("\nCPF: %ld", novo -> cpf);
        printf("\nData prevista de entrega: %d/%d/%d", novo -> data_entrega -> tm_mday,
            novo -> data_entrega -> tm_mon + 1,
            novo -> data_entrega -> tm_year + 1900);

        novo = novo -> proximo;

        printf("\n");
    }

}

int main(){
    TCliente *remover;
    Lista lista;
    lista.inicio = NULL;
    lista.tam = 0;
    int opcao, cpf;
    struct tm *data;
    time_t segundos;
    do{
        time(&segundos);
        printf("\n1 - Inserir cliente\n2 - Imprimir\n3 - Remover registro manualmente\n5 - Sair\n");
        scanf("%i",&opcao);
        switch(opcao){
        case 1:
        printf("\nInforme o CPF do cliente: ");
                scanf("%ld", &cpf);
                segundos += 172800;
                data = localtime(&segundos);
                inserirCliente(&lista, cpf, data);
                removerCliente(&lista, (data -> tm_yday) - 2);//essa funcao removeria o cliente apos passar 2 dias reais

                break;
        case 2:
            imprimir(lista);
            break;
        case 3:
             printf("Insira o CPF a ser removido:");
            scanf("%i",&cpf);
            remover = removerManualmente(&lista,cpf);
            if(remover){
                printf("Elemento removido : %i",remover->cpf);
                free(remover);
            }
            else{
                printf("Elemento inexistente");
                }
            break;
        case 5:
            printf("Finalizando...........\n");
            break;
        default:
            printf("Opção inválida\n");
        }
    }
    while(opcao!=5);

}
