#include <stdio.h>

int max(int a, int b){
	return ((a > b) ? a : b);
}

int min(int a, int b){
	return ((a < b) ? a : b);
}

int main(){
	long long int a ,b ,c ,x ,y ,z;
	
	scanf("%lld %lld %lld", &a, &b, &c);
	x = max(a , max(b, c));
	z = min( a, min(b, c));
	y = a + b + c - x - z;
	
	if(x >= y + z) printf("Invalido\n");
	else{
		if( x == y && y == z) printf("Valido-Equilatero\n");
		else if( x!= y && y!= z && x != z) printf("Valido-Escaleno\n");
		else printf("Valido-Isoceles\n");
		
		if(x * x == ( y * y + z * z)) printf("Retangulo: S\n");
		else printf("Retangulo: N\n");
		
	}
	
	return 0;
	
}
