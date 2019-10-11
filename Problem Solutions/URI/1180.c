#include <stdio.h>

int main(){
	int n, i, x, menor = 11111, pos;
	
	scanf("%d", &n);
	int vetor[n];
	
	for(i = 0; i < n; i++){
		scanf("%d", &x);
		vetor[i] = x;
	} 
	
	for (i = 0; i < n; i++){
		if(vetor[i] <= menor){
			menor = vetor[i];
			pos = i;
		}
	}
	
	printf("Menor valor: %d\n", menor);
	printf("Posicao: %d\n", pos);
	
	
	
	
}
