#include <stdio.h>

int main(){
	int opc = 0, alcool = 0, gasolina = 0, diesel = 0;
	
	while(1){
		scanf("%d", &opc);
		if(opc == 4) break;
		
		switch(opc){
			case(1):
				alcool++;
				break;
			case(2):
				gasolina++;
				break;
			case(3):
				diesel++;
				break;
		}
		
	}
	
	printf("MUITO OBRIGADO\n");
	printf("Alcool: %d\n", alcool);
	printf("Gasolina: %d\n", gasolina);
	printf("Diesel: %d\n", diesel);
	
	
	return 0;
	
}
