#include <stdio.h>

int main(){
	int n, i;
	scanf("%d", &n);
	
	for(i = 1; i < n; i++){
		if( n % i == 0){
			printf("%d\n", i);
		}
		
	}printf("%d\n", i);
	
	return 0;
	
}
