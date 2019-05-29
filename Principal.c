#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <strings.h>
#include "Lista.h"
#include <locale.h>
Lista * somaLista(Lista * l1, Lista * l2) {
	Lista * l3 = criar();
	int i, auxD = 0, auxSoma, t1 = 0, t2 = 0;
    
	while(tamanho(l1) > tamanho(l2)){
		inserir_primeiro(l2, 0);
		t1++;
	}
	while(tamanho(l2) > tamanho(l1)){
		inserir_primeiro(l1, 0);
		t2++;
	}
	for (i = tamanho(l1) - 1; i >= 0; i--) {
		auxSoma = ler_pos(l1, i) + ler_pos(l2, i);
		if((auxSoma + auxD) >= 10){
			inserir_primeiro(l3, (auxSoma + auxD) - 10);
			auxD = 1;
		}else{
			inserir_primeiro(l3, auxSoma + auxD);
			auxD = 0;
		}
	}
	if(auxD == 1) {
		inserir_primeiro(l3, 1);
	}
	while(t1 > 0) {
		remover_primeiro(l2);
		t1--;
	}
	while(t2 > 0) {
		remover_primeiro(l1);
		t2--;
	}
	return l3;
}
Lista * soma(char n1[], char n2[]) {
	Lista * l1 = criar();
	Lista * l2 = criar();
	Lista * l3 = criar();
	int i, auxD = 0, auxSoma;
    for (i = 0; i < strlen(n1); i++){
    	inserir_ultimo(l1, n1[i] - '0');
	}
	for (i = 0; i < strlen(n2); i++){
    	inserir_ultimo(l2, n2[i] - '0');
	}
	while(tamanho(l1) > tamanho(l2)){
		inserir_primeiro(l2, 0);
	}
	while(tamanho(l2) > tamanho(l1)){
		inserir_primeiro(l1, 0);
	}
	for (i = tamanho(l1) - 1; i >= 0; i--) {
		auxSoma = ler_pos(l1, i) + ler_pos(l2, i);
		if((auxSoma + auxD) >= 10){
			inserir_primeiro(l3, (auxSoma + auxD) - 10);
			auxD = 1;
		}else{
			inserir_primeiro(l3, auxSoma + auxD);
			auxD = 0;
		}
	}
	if(auxD == 1) {
		inserir_primeiro(l3, 1);
	}
	return l3;
}
Lista * multiplicacaoLista(Lista * l1, Lista * l2) {
	Lista * l3 = criar();
	Lista * auxL = criar();
	int i, j, n, auxMult, k, tam1 = (tamanho(l1) - 1), tam2 = (tamanho(l2) - 1), b;
	int auxD[tam1+1], auxU[tam1];
	for (i = 0; i < (tam1+2); i++) {
		auxD[i] = 0;
	}
	for (i = tam2; i >= 0; i--, b = 0) {
		for (j = tam1, k = 0; j >= 0; j--, k++) {
			auxMult = ler_pos(l2, i) * ler_pos(l1, j);
			auxU[k] = auxMult + auxD[k];
			while (auxU[k] >= 10) {
				auxU[k] -= 10;
				auxD[k+1]++;
				b = 1;
			}
			inserir_primeiro(auxL, auxU[k]);
		}
		if(b == 1) {
			inserir_primeiro(auxL, auxD[k]);
		}
		for (n = 0; n < (tam1+2); n++) {
			auxD[n] = 0;
		}
		n = tam2;
		while(n > i) {
			inserir_ultimo(auxL, 0);
			n--;
		}
		l3 = somaLista(l3, auxL);
		limpar(auxL);
		n = tam2;
	}
	return l3;
}
int main() {
	setlocale(LC_ALL, "Portuguese");
    char * n1, * n2;
    n1 = malloc(sizeof(char));
    n2 = malloc(sizeof(char));
    int op = 0;
    Lista * l1 = criar();
    Lista * l2 = criar();
    Lista * l3 = criar();
    int i, j, l;
    do {
    	while(op == 0){
	    	printf("1. Definir o valor do operando 1.\n");
			printf("2. Definir o valor do operando 2.\n");
			printf("3. Mostrar o resultado da soma.\n");
			printf("4. Mostrar o resultado do produto.\n");
			printf("5. Sair do programa. \n");
			printf("\nSelecione uma opção: ");
			scanf("%d", &op);
			fflush(stdin);
__fpurge(stdin);
		}
		while(op != 0 && op != 1 && op != 2 && op != 3 && op != 4 && op != 5){
			printf("\nOpção inválida!\n");
			scanf("%d", &op);
			fflush(stdin);
__fpurge(stdin);
		}
    	while(op == 1){
		    printf("Digite o primeiro número: ");
		    gets(n1);
			fflush(stdin);
__fpurge(stdin);
		    if(tamanho(l1) > 0){
			    limpar(l1);
			}
			for (i = 0; i < strlen(n1); i++){
		    	inserir_ultimo(l1, n1[i] - '0');
			}
		    op = 2;
		}
		while(op == 2) {
		    printf("Digite o segundo número: ");
		    gets(n2);
			fflush(stdin);
__fpurge(stdin);
		    if(tamanho(l2) > 0){
			    limpar(l2);
			}
			for (i = 0; i < strlen(n2); i++){
		    	inserir_ultimo(l2, n2[i] - '0');
			}
		    op = 0;
		}
		while(op == 3) {
			imprimir(l1);
			printf("+\n");
			imprimir(l2);
			printf("--------------------------------------\n");
			l3 = somaLista(l1, l2);
			imprimir(l3);
			op = 0;
		}
		while(op == 4) {
			imprimir(l1);
			printf("*\n");
			imprimir(l2);
			printf("--------------------------------------\n");
			l3 = multiplicacaoLista(l1, l2);
			imprimir(l3);
			op = 0;
		}
	}while(op != 5);
    return 0;
}
