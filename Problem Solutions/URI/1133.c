#include <stdio.h>

int main(){
	int i, x, y, a, b;
	scanf("%d %d", &x, &y);
	
	if(x > y){
		a = y;
		b = x;
	}else{
		a = x;
		b = y;
	}
	
	for(i = a + 1; i < b; i++){
		if(i % 5 == 2 || i % 5 == 3)
			printf("%d\n", i);
	}
	
}
