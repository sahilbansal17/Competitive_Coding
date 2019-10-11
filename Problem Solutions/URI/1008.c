#include <stdio.h>

int main(){
	float porHora, salario;
	int numero, horas;
	scanf("%d%d%f", &numero, &horas, &porHora);
	salario = porHora * horas;
	printf("NUMBER = %d\n", numero);
	printf("SALARY = U$ %.2f\n", salario);
	
	return 0;
}
