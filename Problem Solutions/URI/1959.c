#include <stdio.h>

int main(){
	long long int numero , lado , poligono;
	
	scanf("%lld %lld", &numero, &lado);
	poligono = numero * lado;
	
	printf("%lld\n", poligono);
	
	return 0;
}
