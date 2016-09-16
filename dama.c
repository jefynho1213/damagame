#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fundama.h"




int main(){
	char **table, jogador;
	table = incializa();
	organiza(table);
	printa_table(table);
	

	int i=1,
		l_a/*linha da peca a ser movida*/, 
		c_a/*coluna da peca a ser movida*/, 
		l_p/*linha para aonde a peca sera movida*/, 
		c_p/*coluna para onde a peca sera movida*/,
		status/*recebe o status da jogada*/;
	
	//loop do jogo
	for(;;){

		//menu de jogo
		printf("____Comandos MENU:____\n||| 100 para reiniar|||\n||| 200 para encerrar |||\n");
	   
	    if(i%2==0){ // verifica de qual jogador tem q jogar
	    
	    	jogador = 'x';
	    
	    	printf("E a vez do jogar: %c\n", jogador );
	    
	    	
	    }	 else {
	    	
	    		jogador = 'o';
	    	
	    		printf("E a vez do jogar: %c\n", jogador );
				
			}
			   
					
					printf("Digite algum comando de MENU ou\nDigite a linha referente a peca:"); 
					scanf("%d", &l_a);
					if(l_a < 100){
							printf("Digite a coluna referente a peca:");
							scanf("%d", &c_a);
							printf("Digite a linha onde deseja jogar:");
							scanf("%d", &l_p);
							printf("Digite a coluna onde deseja jogar:");
							scanf("%d", &c_p);
					}
					

						
				
				
				if(l_a==100){
					organiza(table);
					printa_table(table);

					continue;
					i=1;
				} else if(l_a==200){
					return 0;
				} else {
					if(l_p > 8 || c_p > 8 || l_a > 9 || c_a > 8){ // verifica se o jogador esta escolhendo uma posicao valida
						printf("As linhas e colunas vao ate 8, Digite um numero menor\n");
						continue;
					} else {
						status =  verificacasa(table, l_p, c_p, l_a, c_a, jogador);
					}
				}
				 	system("clear");// limpa a tela depois de cada jogada

				 	printa_table(table); // printa a tabela atualizada
				
				 if(status < 0 ){ // verifica o status da jogada
				
				 	printf(" voce nao pode fazer essa jogada\n");
				
				 } else {
				 	i++;
				 	printf("jogada ok\n");
				 }

			 

		}
	return 0;
}


