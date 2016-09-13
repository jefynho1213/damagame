#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fundama.h"




int main(){
	char **table;
	table = incializa();
	organiza(table);
	printa_table(table);
	

	int l_a, c_a, l_p, c_p;
	for(;;){
		scanf("%d", &l_a);
		scanf("%d", &c_a);
		scanf("%d", &l_p);
		scanf("%d", &c_p);
		char jogador = 'O';
		int status;
		
			status =  verificacasa(table, l_p, c_p, l_a, c_a, jogador);

		 	printa_table(table);
		
		 if(status < 1 ){
		 	printf(" voce nao pode fazer essa jogada\n");
		 } else {
		 	printf("jogada ok\n");
		 }
	}
	return 0;
}


