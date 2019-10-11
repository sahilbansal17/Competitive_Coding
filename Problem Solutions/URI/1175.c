#include <stdio.h>

int main(){
	
	int i , n, vetor[20];
	
	for(i = 19; i >= 0; i--){
		scanf("%d", &n);
		vetor[i] = n;
	}
	
	for(i = 0; i < 20; i++){
		printf("N[%d] = %d\n", i, vetor[i]);
	}
	
	return 0;
		
}
