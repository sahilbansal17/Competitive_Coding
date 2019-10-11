#include <stdio.h>

int main(){
	int s = -1 ,i , n, soma = 0, c , j;
	scanf("%d", &c);
	
	for( j = 0; j < c; j++){
		scanf("%d", &n);
		
		for(i = 0; i < n; i++){
			s = s * (-1);
			soma += s;
		}
		
		printf("%d\n", soma);
		soma = 0;
		s = -1;
	}
		
	
	return 0;
	
}
