#include <stdio.h>

int main(){
	int qtdPositivo, i;
	double valores, soma;
	
	for(i = 0; i < 6; i++){
		scanf("%lf", &valores);
		if(valores > 0){
			qtdPositivo += 1;
			soma += valores;
		}
	}
	
	printf("%d valores positivos\n", qtdPositivo);
	printf("%.1f\n", (soma / qtdPositivo));
	return 0;
	
}
