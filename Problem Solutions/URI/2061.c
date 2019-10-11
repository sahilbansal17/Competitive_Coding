#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
	 short abas, acoes;
	 char acao[7];
	 
	 scanf("%hd %hd", &abas, &acoes);
	 
	 while(acoes--){
		 scanf("%s", acao);
		 if(strcmp(acao, "clicou") == 0) abas--;
		 else abas++;
	 }
	 printf("%hd\n", abas);
	 
	 return 0;
}
