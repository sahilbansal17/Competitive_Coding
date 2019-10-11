#include <stdio.h>

int main(){
	double raio;
	double area;
	scanf("%lf", &raio);
	area = (raio * raio) * 3.14159;
	printf("A=%.4lf\n",area);
	
	return 0;		
}
