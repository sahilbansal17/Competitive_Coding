#include <stdio.h>

int main(){
	int contador, x;
	
	scanf("%d", &x);
	
	while(contador < 6){
		if(x % 2 != 0){
			printf("%d\n", x);
			contador += 1;
		}
		
		x += 1;
		
	}
	
}
