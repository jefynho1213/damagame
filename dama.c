#include <stdio.h>
#include <stdlib.h>

//caso ele nao possua nenhuma peca para capturar, verifica se o movimento solicitado e valido
int verificacasa();
//loog do jogo
void game();
//verifica se o jogador pode capturar alguma peca
void capturar();
//verifica se a peca movimentada possui previlegios de dama
int dama();
//cria a matriz
char incializa();



int main(){

}


char incializa(){
	char **table;
	int i;
	table = (char**)calloc(8,sizeof(char*));

	for(i=0;i<8;i++){
		table[i]= (char*)calloc(8,sizeof(char));
	}

	return table;

}

//recebe o endereco da tabela, linha e coluna que deseja jogar <linha_p>, linha e coluna atual <linha_a> e jogador que esta fazendo a jogada
//retorna -1 para jogadas invalidas
//retorna 1 para realizar a jogada
//jogar 1 é o jogador da area inferior
int verificacasa(char **table, int linha_p, int coluna_p, char jogador, int linha_a, int coluna_a){
	if(jogador ==  '<jogador1>'){
		if(table[linha_p][coluna_p] = '<jogador1>'){
			return -1;
			//verifica se o jogador esta realizando uma jogada na diagonal 
		} else if(linha_a != linha_p-1 || coluna_a != coluna_p-1){
			return -1;
			//verifica se o jogador esta realizando uma jogada na diagonal
		} else if(coluna_a != coluna_p+1){
			return -1;
			//verifica se o jogador este relizando 
		} else if(linha_a > linha_p-1){
			return -1;
		}
	}
}