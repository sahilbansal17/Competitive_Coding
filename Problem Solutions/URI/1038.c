#include <stdio.h>


int main(){
	int codigo, quantidade;
	float valor = 0;
	
	scanf("%d %d", &codigo, &quantidade);
	
	if(codigo == 1)
		valor = quantidade * (4.00);
	else if(codigo == 2)
		valor = quantidade * (4.50);
	else if(codigo == 3)
		valor = quantidade * (5.00);
	else if(codigo == 4)
		valor = quantidade * (2.00);
	else if(codigo == 5)
		valor = quantidade * (1.50);
	
	printf("Total: R$ %.2f\n", valor);
	
	
	return 0;
}
