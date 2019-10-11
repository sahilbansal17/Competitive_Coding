#include <stdio.h>


int main(){
	int i = 0;
	int valor = 0;
	int par = 0;
	int impar = 0;
	int positivo = 0;
	int negativo = 0;
	
	for(i = 0; i < 5; i++){
		scanf("%d", &valor);
		
			if(valor > 0)
				positivo+= 1;
			if(valor < 0)
				negativo+= 1;
			
			if(valor % 2 != 0)
				impar+= 1;
			else
				par+= 1;
	}
	
	printf("%d valor(es) par(es)\n", par);
	printf("%d valor(es) impar(es)\n", impar);
	printf("%d valor(es) positivo(s)\n", positivo);
	printf("%d valor(es) negativo(s)\n", negativo);
	
	
	
	
	
}
