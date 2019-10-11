#include <stdio.h>

int main(){
	double a, b, c, y, triangulo, circulo, trapezio, quadrado, retangulo;
	double pi = 3.14159;
	
	scanf("%lf %lf %lf", &a, &b, &c);
	y = a + b;
	
	triangulo = ((a * c)/ 2.0);
	circulo = pi*(c * c);
	trapezio = ((y * c )/2.0);
	quadrado = b * b;
	retangulo = a * b;
	
	printf("TRIANGULO: %.3lf\nCIRCULO: %.3lf\nTRAPEZIO: %.3lf\nQUADRADO: %.3lf\nRETANGULO: %.3lf\n",triangulo,circulo,trapezio,quadrado,retangulo);
	
	
	return 0;
}
