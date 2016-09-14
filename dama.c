#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fundama.h"




int main(){
	char **table, jogador;
	table = incializa();
	organiza(table);
	printa_table(table);
	

	int i=1, l_a, c_a, l_p, c_p;
	

	for(;;){
		printf("____Comandos MENU:____\n||| 100 para reiniar|||\n||| 200 para encerrar |||\n");
	   
	    if(i%2==0){
	    
	    	jogador = 'X';
	    
	    	printf("E a vez do jogar: %c\n", jogador );
	    
	    	
	    }	 else {
	    	
	    		jogador = 'O';
	    	
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
					

						
				
				int status;
				if(l_a==100){
					organiza(table);
					incializa();
					printa_table(table);

					continue;
					i=1;
				} else if(l_a==200){
					return 0;
				} else {
					if(l_p > 8 || c_p > 8 || l_a > 8 || c_a > 8){
						printf("As linhas e colunas vao ate 7, Digite um numero menor\n");
						continue;
					} else {
						status =  verificacasa(table, l_p, c_p, l_a, c_a, jogador);
					}
				}
				 	system("clear");

				 	printa_table(table);
				
				 if(status < 0 ){
				
				 	printf(" voce nao pode fazer essa jogada\n");
				
				 } else {
				 	i++;
				 	printf("jogada ok\n");
				 }

			 

		}
	return 0;
}


