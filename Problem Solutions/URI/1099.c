#include <stdio.h>

int main(){
	int n, x, y, a, b, i, j, soma;
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		scanf("%d %d", &x, &y);
		soma = 0;
		if( x == y){
			printf("0");
		}
		if( x < y ){
			a = x;
			b = y;
		}else{
			a = y;
			b = x;
		}
		
		for(j = a; j < b; j++){
			if( j % 2 != 0)
				soma += j;
		}
		printf("%d\n", soma);
		
	}
	
	return 0;
}
