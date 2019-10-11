#include <stdio.h>

int main(){
	double salario, vendas, porcentagem;
	char nome;
	scanf("%s %lf %lf", &nome, &salario, &vendas);
	
	
	
	porcentagem = (0.15 * vendas);
	printf("TOTAL = R$ %.2f\n", porcentagem + salario);
	
	return 0;
}
