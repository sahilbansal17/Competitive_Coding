#include <stdio.h>

int main(){
	int i, valor,posicao, maior = -100000;
	
	for(i = 1; i <= 4; i++){
		scanf("%d", &valor);
		
		if(valor >= maior){
			maior = valor;
			posicao = i;
		}
		
	} 
	
	printf("%d\n", maior);
	printf("%d\n", posicao);
	
}
