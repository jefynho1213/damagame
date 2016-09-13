#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "fundama.h"




int main(){
	char **table, jogador;
	table = incializa();
	organiza(table);
	printa_table(table);
	

	int i=1, l_a, c_a, l_p, c_p;
	

	for(;;){
	   
	    if(i%2==0){
	    	jogador = 1;
	    	printf("E a vez do jogar: %c\n", jogador );
	    }	 else {
	    		jogador = 2;
	    	
	    		printf("E a vez do jogar: %c\n", jogador );
				
				}
			   
			    do{
					
					printf("Digite a linha referente a peca:"); scanf("%d", &l_a);
					
					printf("Digite a coluna referente a peca:"); scanf("%d", &c_a);
					
					printf("Digite a linha onde deseja jogar:"); scanf("%d", &l_p);
					
					printf("Digite a coluna onde deseja jogar:"); scanf("%d", &c_p);
					
					

				}while(l_p > 8 || c_p > 8 || l_a > 8 || c_a > 8);		
				
				int status;
				
					status =  verificacasa(table, l_p, c_p, l_a, c_a, jogador);

				 	system("cls");

				 	printa_table(table);

				 	printf("%d\n", status );
				
				 if(status < 1 ){
				
				 	printf(" voce nao pode fazer essa jogada\n");
				
				 } else {
				
				 	printf("jogada ok\n");
				 }

			 i++;

		}
	return 0;
}


