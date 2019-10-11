#include <stdio.h>


int main(){
	int i, n, par = 2;
	
	scanf("%d", &n);
	
	if(n <= 5 || n >= 2000) return 0;
	for(i = 0; i < n; i++){
		if(i % 2 == 0){
			printf("%d^2 = %d\n", par, (par * par));
			par+= 2; 
		}
		
		
	}
	
	
	
	
	return 0;
}
