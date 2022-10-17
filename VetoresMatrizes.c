#include <stdio.h>
#include <locale.h>
#include <math.h>
#include<conio.h>
#include<windows.h>
#include <time.h>

#define maxlinha 10
#define maxcoluna 10
#define maxlinha2 5
#define maxcoluna2 5

//NOME:Carlos Alexandre Fernandes Facanha
//Data: 22/06/2022



int main(){
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");
    int opcao;
    printf("Escolha uma opção:\n[1]Vetor 200, números reais maiores que 800.\n[2]Vetor 50,números inteiros aleatórios.\n[3]Matriz 10x10\n[4]Matriz 5x5\n---->");
    scanf("%i",&opcao);

    switch(opcao){
    case 1:{
        int qtd=200,valorinicial=801,vetor[qtd],i;
        for(i=0;i<qtd;i++){
        vetor[i]=valorinicial+i;
    }
        for(i=0;i<qtd;i++){
        printf("%i- O valor do vetor da posicao[%i]=%i\n",i+1,i,vetor[i]);
    }
    break;
    }
    case 2:{
        int qtd2=50,vetor2[qtd2],i2;
        for(i2=0;i2<qtd2;i2++){
        vetor2[i2]=rand()%50;
    }
        for(i2=0;i2<qtd2;i2++){
        printf("%i- O valor do vetor da posicao[%i]=%i\n",i2+1,i2,vetor2[i2]);
    }
    break;
    }
    case 3:{
       srand(time(NULL));
       setlocale(LC_ALL, "Portuguese");
       int matriz[maxlinha][maxcoluna], linha, coluna,i;
       int matrizA[10][10], matrizB[10][10], somaAB[10][10];
       printf("\nPreenchendo a Matriz..................\n\n");
       printf("\nValores da Matriz A\n\n");
	  for( linha = 0; linha < maxlinha; linha++ ) {
		for(coluna = 0; coluna < maxcoluna; coluna++) {
         matrizA[linha][coluna]=rand()%100;
         printf("  %d\t  ",matrizA[linha][coluna]);
		}
		printf("\n");
	  }
        printf("\nValores da Matriz B\n\n");
      for( linha = 0; linha < maxlinha; linha++ ) {
		for(coluna = 0; coluna < maxcoluna; coluna++) {
         matrizB[linha][coluna]=rand()%100;
         printf("  %d\t  ",matrizB[linha][coluna]);
		}
		printf("\n");
	}
	printf("\n \nSOMA MATRIZ A E MATRIZ B: \n");
    for(linha=0; linha<maxlinha; linha++) {
        for (coluna=0; coluna<maxcoluna; coluna++) {
            somaAB[linha][coluna]= matrizA[linha][coluna] + matrizB[linha][coluna];

        printf("  %i\t  ", somaAB[linha][coluna]);
        }
    printf("\n");
    }
    break;
    }
    case 4:{
        int matriz2[maxlinha2][maxcoluna2], linha2, coluna2,resposta,num;
        printf("Digite o numero de elementos da matriz -----> ");
  scanf("%i",&resposta);

  if(resposta<=25){
  printf("\nPreenchendo a Matriz..................\n\n");
  printf("\nValores da Matriz \n\n");
	for( linha2 = 0; linha2 < maxlinha2; linha2++ ) {
		for(coluna2 = 0; coluna2 < maxcoluna2; coluna2++) {
         if (num < resposta) {
                num += 1;
                matriz2[maxlinha2][maxcoluna2] = num;
                printf("\t%d",matriz2[maxlinha2][maxcoluna2]);
                } else {
                 matriz2[maxlinha2][maxcoluna2] = 0;
                 printf("\t");
                }
	}
	 printf("\n");

}
}
  else{
    printf("Valor invalido");
  }

    break;
    }

}
}
