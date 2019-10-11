#include <stdio.h>


int main(){
	int i = 0, j = 0, n = 0 , soma = 0, x = 0;
	
	scanf("%d", &x);
	if( x > 0 && x <= 20){
		for(i = 0; i < x; i++){
			scanf("%d", &n);
			
			for(j = 1; j < n; j++){
				if(n % j == 0){
					soma += j;
				}
			} 
			if(soma == n)
				printf("%d eh perfeito\n", n);
			else
				printf("%d nao eh perfeito\n", n);
			
			soma = 0;
			
		}
}
	return 0;
	
}
