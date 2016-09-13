#ifndef fundama


//caso ele nao possua nenhuma peca para capturar, verifica se o movimento solicitado e valido
//int verificacasa(char **, int , int, char, int, int);
//  loog do jogo
//void game();
//  verifica se o jogador pode capturar alguma peca
//void capturar();
//  verifica se a peca movimentada possui previlegios de dama
//int dama();
//  cria a matriz
//char **incializa();
//  organiza pecas
//void organiza(char **);
//void printa_table(char **);


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

	for(i=0;i<3;i++){
	        if(i%2 == 0){
	            j=1;
	         }else{
	            j=0;
	         }
	        while(j<8){
	            table[i][j] = 'X';
	            j+=2;
	        }

    	}

	for(i=5;i<8;i++){
	        if(i%2 == 0){
	            j=1;
	         }else{
	            j=0;
	         }
	        while(j<8){
	            table[i][j] = 'O';
	            j+=2;
	        }
	}

	table[4][3] = 'X';
}


void printa_table(char **table){
	int i,j;
	printf(" 0  1  2  3  4  5  6  7 \n");
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			printf("[%c]", table[i][j]);
		}
		printf(" %d\n", i);
	}
}

int captura(char **table, int linha_p, int coluna_p, int linha_a, int coluna_a, char jogador){
	printf("cap jogador\n local ocupado por '%c' \n linha %d coluna %d\n", table[linha_a-1][coluna_a-1], linha_a-1, coluna_a-1);
	if(linha_a != linha_p+2){
		return -1;
	} else if(table[linha_a-1][coluna_a-1]== 'X') {
		printf("detectou x\n");
		if(table[linha_p][coluna_p]== ' '){
			table[linha_p][coluna_p] = 'O';
			table[linha_a][coluna_a] = ' ';
			if(coluna_p-2 == coluna_a){
				table[linha_a+1][coluna_a-1]=' ';
				return 1;
				
			} else {
				table[linha_a+1][coluna_a+1]=' ';
				return 1;
			}
		} else {
			return -1;
		} 
	} else {
		return -1;
	}
}

//recebe o endereco da tabela, linha e coluna que deseja jogar <linha_p>, linha e coluna atual <linha_a> e jogador que esta fazendo a jogada
//retorna -1 para jogadas invalidas
//retorna 1 para realizar a jogada
//jogar 1 é o jogador da area inferior

int verificacasa(char **table, int linha_p, int coluna_p, int linha_a, int coluna_a, char jogador){

	if(jogador == 'O'){
		if(table[linha_p][coluna_p] != ' '){
			printf("local ocupado\n");
			return -1;
			//verifica se o jogador esta realizando uma jogada na diagonal
		} else if(linha_a != linha_p+1) {
			captura(table, linha_p, coluna_p, linha_a, coluna_a, jogador);
			
			printf("linha compara\n");
			return -1;
			//verifica se o jogador esta realizando uma jogada na diagonal
		} else if(coluna_a == coluna_p-1 || coluna_a == coluna_p+1){
			table[linha_a][coluna_a] = ' ';

			table[linha_p][coluna_p] = 'O';
			printf("ok\n");
			return 1;
			//verifica se o jogador este relizando
		} else {
			printf("coluna compara\n");
			return -1;			
		}
	} else {
		printf("jogador\n");
		return 1;
	}

}

#endif
