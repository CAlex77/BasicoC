#include <stdio.h>
#include <locale.h>
#include <math.h>
#include<conio.h>
#include<windows.h>


int aux;
int result;
int continuar;
void tabuada(int valor,char operador);

void tabuada(int valor,char operador){
    if((valor<=10) && (operador==1)){
        for(int i=0;i<=4;i++){
            printf("\n\t====================================================\n\tQuanto � %i + %i ? = \n\t----->",valor,i);
            scanf("%i",&result);
            if(result==(valor+i)){
                printf("\n\tCorreto!\n");
                Sleep(5000);
                system("cls");
            }else{
                printf("\n\t\aErrado, mas n�o se preocupe, tente novamente\n");
                i--;
                Sleep(3000);
                system("cls");

            }}}
        if((valor<=10) && (operador==2)){
        for(int i=valor;i<=4+valor;i++){
            printf("\n\t====================================================\n\tQuanto � %i - %i ? = \n\t----->",i,valor);
            scanf("%i",&result);
            if(result==(i-valor)){
                printf("\n\tCorreto!\n");
                Sleep(3000);
                system("cls");
            }else{
                printf("\n\t\aErrado, mas n�o se preocupe, tente novamente\n");
                i--;
                Sleep(3000);
                system("cls");

    }}}
    if((valor<=10) && (operador==3)){
        for(int i;i<=10;i++){
            printf("\tQuanto � %i x %i ? = \n\t----->",i,valor);
            scanf("%i",&result);
            if(result==(i*valor)){
                printf("\n\tCorreto!\n");
                Sleep(3000);
                system("cls");
            }else{
                printf("\n\t\aErrado, mas n�o se preocupe, tente novamente\n");
                i--;
                Sleep(3000);
                system("cls");
    }}}
     if((valor<=10) && (operador==4)){
        for(int i=1;i<=4+valor;i++){
                aux=i*valor;
            printf("\tQuanto � %i / %i ? = \n\t----->",aux,valor);
            scanf("%i",&result);
            if(result==(aux/valor)){
                printf("\n\tCorreto!\n");
                Sleep(3000);
                system("cls");
            }else{
                printf("\n\t\aErrado, mas n�o se preocupe, tente novamente\n");
                Sleep(3000);
                i--;
                system("cls");
    }}}


    }

int main(){
    SetConsoleTitle("Tabuada");
    int valor,i;
    int operador;
    system("color 1f");
    setlocale(LC_ALL, "Portuguese");
    printf("\n\t=====\n\tOl�!\n\t====================================================\n\tUma das ci�ncias mais importantes do mundo � a matem�tica, e atrav�s dela voc� pode explicar o universo.\n\tN�o acredita? Sabia que seu videogame e celular s� funcionam gra�as � matem�tica? \n\tAposto que agora voc� ficou mais interessado hein!\n\tVamos praticar um pouco de tabuada.\n\t====================================================\n\t");
    Sleep(4000);
    system("cls");
    while(operador!=5){
    system("color 1f");
    printf("\n\tQual n�mero voc� quer praticar? De 0 a 10\n\t----> ");
    scanf("%i",&valor);
    if(valor>10){
    while(valor>10){
        printf("\n\t\aVamos com calma, escolha um numero menor.");
        printf("\n\t\aQual numero voce quer praticar? De 0 a 10\n\t---->");
        scanf("%i",&valor);
    }}
    printf("\n\t====================================================\n\t[1]Soma\n\t[2]Subtracao\n\t[3]Multiplica��o\n\t[4]Divis�o\n\t[5]Sair\n\t---->");
    scanf("%i",&operador);
    if(operador==5){
        return 0;
    }
    tabuada(valor,operador);
    printf("\n\tMuito bem!\n\tQuer continuar praticando? Digite 1 se sim e 2 se nao.\n\t---->");
            scanf("%i",&continuar);
            if(continuar==2){
                printf("\t\aTchau!\n\t\aSaindo..........");
                operador=5;
            }


   }}
