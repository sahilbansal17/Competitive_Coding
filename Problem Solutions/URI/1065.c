#include <stdio.h>

int main(){
	int valor, count, i;
	
	for(i = 0; i < 5; i++){
		scanf("%d", &valor);
		if(valor % 2 == 0){
			count += 1;
		}
	}
	
	printf("%d valores pares\n", count);
	
	
	
}
