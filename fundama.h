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
	char k=' ';

	table = (char **)calloc(8,sizeof(char *));

	for(i=0;i<8;i++)
	
		table[i]= (char *)calloc(8,sizeof(char));

	//inicializa todas as casas do tabuleiro como branco	

	for(i=0;i<8;i++)
	
		for(j=0;j<8;j++)
	
			table[i][j] = ' ';

				//faz com que os quadradinhos onde nao se pode jogar fiquem preenchidos

				for(i=0;i<8;i+=2)
				
					for(j=0;j<8;j+=2)
				
						table[i][j] = ' ';

				for(i=1;i<8;i+=2)
				
					for(j=1;j<8;j+=2)
				
						table[i][j] = ' ';


	return table;


}






void organiza(char **table){

	int i,j;
	char X='X', O='O';


		for(i=0;i<8;i++)
	
		for(j=0;j<8;j++)
	
			table[i][j] = ' ';

				//faz com que os quadradinhos onde nao se pode jogar fiquem preenchidos

				for(i=0;i<8;i+=2)
				
					for(j=0;j<8;j+=2)
				
						table[i][j] = ' ';

				for(i=1;i<8;i+=2)
				
					for(j=1;j<8;j+=2)
				
						table[i][j] = ' ';
	

	for(i=0;i<3;i++){
	       
	        if(i%2 == 0){
	       
	            j=1;
	       
	         }else{
	       
	            j=0;
	         }
	       
	        while(j<8){
	       
	            table[i][j] = X;
	       
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
	       
	            table[i][j] = O;
	       
	            j+=2;
	        }
	}

	
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
	
	char X='X', O='O';
	
	printf("cap jogador\n local ocupado por '%c' \n linha %d coluna %d\n", table[linha_a-1][coluna_a-1], linha_a-1, coluna_a-1);
	if(jogador == O){

		if(linha_a != linha_p+2){

			return -1;

		} 	else if(table[linha_a-1][coluna_a-1]== X ) { // verifica O a esquerda da peça para possibilitar movimento > que uma casa
					
					printf("detectou x na esquerda \n");
		
					if(table[linha_p][coluna_p]== ' '){
				
						table[linha_p][coluna_p] = jogador;
				
						table[linha_a][coluna_a] = ' ';
				
						table[linha_a-1][coluna_a-1]=' ';
						return 1;
					} else {
						return -1;
					}			
		} else if (table[linha_a-1][coluna_a+1]== X ){ 
						
					printf("detectou x na direita \n");


							if (table[linha_p][coluna_p]== ' '){
								
								table[linha_p][coluna_p] = O;
								
								table[linha_a][coluna_a] = ' ';
								
								table[linha_a-1][coluna_a+1]=' ';
								return 1;
							} else {
								return -1;
							}		
				} else {
					return -1;
				}
		} else {
			//jogador X

			if(linha_a != linha_p-2){

			return -1;

		} 	else if(table[linha_a+1][coluna_a+1]== O ) { // verifica x a esquerda da peça para possibilitar movimento > que uma casa
					
					printf("detectou x na esquerda \n");
		
					if(table[linha_p][coluna_p]== ' '){
				
						table[linha_p][coluna_p] = jogador;
				
						table[linha_a][coluna_a] = ' ';
				
						table[linha_a+1][coluna_a+1]=' ';
						return 1; 
					} else {
						return -1;
					}			
			} else if (table[linha_a+1][coluna_a-1]== O){ 
						
					printf("detectou x na direita \n");

					if (table[linha_p][coluna_p]== ' '){

						
						table[linha_p][coluna_p] = X;
						
						table[linha_a][coluna_a] = ' ';
						
						table[linha_a+1][coluna_a-1]=' ';
						return 1;
					} else {
						return -1;
					}		
			} else {
				return -1;
			}


			return -1;
		}
		return -1;
}

//recebe o endereco da tabela, linha e coluna que deseja jogar <linha_p>, linha e coluna atual <linha_a> e jogador que esta fazendo a jogada
//retorna 1 para jogada bem sussedida
//retorna -1 para jogadas invalidas
// -2 para local ocupado por outra peca
// -3 para a jogada nao foi feita para frente ou ele tentou andar mais de uma linha
//

int verificacasa(char **table, int linha_p, int coluna_p, int linha_a, int coluna_a, char jogador){
	char X='X', O='O';
	int status;

			// condiçoes para casa o jogador escolha a pedra referente a O
			
			if(jogador == O){
			
				if(table[linha_a][coluna_a] == jogador){
						
				
					if(table[linha_p][coluna_p] != ' '){
				
						printf("local ocupado\n");
				
						return -2;
						//verifica se a jogada foi feita para frente e apenas uma casa || chama a funcao captura para verificar se o jogador quer capturar alguma peca
					} else if(linha_a != linha_p+1) {
						if(linha_a < linha_p){
							return -1;
						} else {
							status = captura(table, linha_p, coluna_p, linha_a, coluna_a, jogador);
							printf("voce nao pode andar mais que duas casas ao nao ser capture alguma peca\n");
							return status;
						}
						//verifica se o jogador esta realizando uma jogada na diagonal e apenas uma casa
					} else if(coluna_a == coluna_p-1 || coluna_a == coluna_p+1){
				
						table[linha_a][coluna_a] = ' ';

						table[linha_p][coluna_p] = O;
				
						printf("ok\n");
						return 1;
						//verifica se o jogador este relizando
					} 
				} else {
					printf("Essa peca nao te pertence\n");
					return -5;
				} 

			} else {
				//jogador X
				if(table[linha_a][coluna_a] == jogador){
						
				
					if(table[linha_p][coluna_p] != ' '){
				
						printf("local ocupado\n");
				
						return -2;
						//verifica se a jogada foi feita para frente e apenas uma casa || chama a funcao captura para verificar se o jogador quer capturar alguma peca
					} else if(linha_a != linha_p-1) {

						if(linha_a > linha_p){
							return -1;
						} else {							
							status = captura(table, linha_p, coluna_p, linha_a, coluna_a, jogador);
							printf("voce nao pode andar mais que duas casas ao nao ser capture alguma peca\n");
							return status;
						}
						//verifica se o jogador esta realizando uma jogada na diagonal e apenas uma casa
					} else if(coluna_a == coluna_p-1 || coluna_a == coluna_p+1){
				
						table[linha_a][coluna_a] = ' ';

						table[linha_p][coluna_p] = X;
				
						printf("ok\n");
						return 1;
						//verifica se o jogador este relizando
					} 
				} else {
					printf("Essa peca nao te pertence\n");
					return -5;
				
				
				}
			}
			return -5;
						
}

#endif
