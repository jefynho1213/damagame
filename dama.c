#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fundama.h"

//caso ele nao possua nenhuma peca para capturar, verifica se o movimento solicitado e valido
int verificacasa(char **, int , int, char, int, int);
//  loog do jogo
//void game();
//  verifica se o jogador pode capturar alguma peca
//void capturar();
//  verifica se a peca movimentada possui previlegios de dama
//int dama();
//  cria a matriz
char **incializa();
//  organiza pecas
void organiza(char **);

void printa_table(char **);


int main(){
	char **table;
	table = incializa();
	organiza(table);
	printa_table(table);


	return 0;
}


