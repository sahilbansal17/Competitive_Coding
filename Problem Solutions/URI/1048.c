#include <stdio.h>

void calcula_salario(float s, float porcento);

int main(){
	float salario;
	
	scanf("%f", &salario);
	
	if( salario >= 0 && salario <= 400){
		calcula_salario(salario, 0.15);
		
	}else if( salario > 400 && salario <= 800){
		calcula_salario(salario, 0.12);
	
	}else if( salario > 800 && salario <= 1200){
		calcula_salario(salario, 0.10);
		
	}else if( salario > 1200 && salario <= 2000){
		calcula_salario(salario, 0.07);
		
	}else if( salario > 2000){
		calcula_salario(salario, 0.04);
	}
	
	return 0;
}



void calcula_salario(float s, float porcento){
	float salarioNovo;
	salarioNovo = s + (porcento * s);
	
	printf("Novo salario: %.2f\n", salarioNovo);
	printf("Reajuste ganho: %.2f\n", (s * porcento));
	printf("Em percentual: %.0f %%\n", porcento * 100); 
	return;
}
