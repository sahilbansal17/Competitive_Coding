#include <stdio.h>

int main(){
	
	int idade = 0, qtd = 0;
	double soma = 0, media = 0;
	
	while(1){
		scanf("%d", &idade);
		
		if(idade < 0) break;
		else{
			soma += idade;
			qtd++;
		}		
	}
	
	media = soma /qtd;
	printf("%.2lf\n", media);
	
	
}
