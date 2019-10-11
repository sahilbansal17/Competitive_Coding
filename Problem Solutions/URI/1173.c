#include <stdio.h>

int main(){
	int i, n, vetor[10];
	
	scanf("%d", &n );
	vetor[0] = n;
	
	for( i = 1; i < 10; i++){
		vetor[i] = vetor[i - 1] * 2;
	} 
	
	for( i = 0; i < 10; i++)
		printf("N[%d] = %d\n", i, vetor[i]);
	
	return 0;
}
