#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


char **incializa(){
	char **table;
	int i,j;

	table = (char **)calloc(8,sizeof(char *));

	for(i=0;i<8;i++)
		table[i]= (char *)calloc(8,sizeof(char));
	
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			table[i][j] = ' ';

	return table;

}
void organiza(char **table){
	
	int i,j;

	for(i=0;i<2;i++)
		for(j=0;j<8;j++)
			table[i][j] = 'X';
		
	for(i=6;i<8;i++)
		for(j=0;j<8;j++)
			table[i][j] = 'O';
	
}


void printa_table(char **table){
	int i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			printf("[%c]", table[i][j]);
		}
		printf("\n");
	}
}

//void jogada(char **table, int ){

//}

//recebe o endereco da tabela, linha e coluna que deseja jogar <linha_p>, linha e coluna atual <linha_a> e jogador que esta fazendo a jogada
//retorna -1 para jogadas invalidas
//retorna 1 para realizar a jogada
//jogar 1 é o jogador da area inferior
int verificacasa(char **table, int linha_p, int coluna_p, char jogador, int linha_a, int coluna_a){
	
	
		if(table[linha_p][coluna_p] == 'O'){
			return -1;
			//verifica se o jogador esta realizando uma jogada na diagonal 
		} else if(linha_a != linha_p-1 || coluna_a != coluna_p-1){
			return -1;
			//verifica se o jogador esta realizando uma jogada na diagonal
		} else if(coluna_a != coluna_p+1){
			return -1;
			//verifica se o jogador este relizando 
		} else if(linha_a < linha_p || linha_a == linha_p ){
			return -1;
		} else {
			return 1;
		}
	
}



