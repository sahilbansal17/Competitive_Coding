#include <stdio.h>

int main(){
	int x, y, i, soma, a , b;
	
	scanf("%d %d", &x, &y);
	
	if(x <= y){
		a = x;
		b = y;
	}else{
		a = y;
		b = x;
	}
	
	for(i = a + 1; i < b; i++){
		if(i % 2 == 1 || i % 2 == -1){
			soma += i;

		}
	}
	
	printf("%d\n", soma);
	
}
