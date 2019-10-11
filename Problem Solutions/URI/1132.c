#include <stdio.h>

int main(){
	int i, x, y, a, b, soma = 0;
	scanf("%d %d", &x, &y);
	
	if(x > y){
		a = y;
		b = x;
	}else{
		a = x;
		b = y;
	}
	
	for(i = a; i <= b; i++){
		if(i % 13 != 0)
			soma += i;
	}
	printf("%d\n", soma);
	
}
