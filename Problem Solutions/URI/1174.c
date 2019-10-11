#include <stdio.h>

int main(){
	int i;
	float vetor[100], n;
	
	for(i = 0; i < 100; i++){
		scanf("%f", &n);
		vetor[i] = n;
	}
	
	for( i = 0; i < 100; i++){
		if(vetor[i] <= 10)
			printf("A[%d] = %.1f\n", i, vetor[i]);
	}
	
	
	return 0;
	
}
