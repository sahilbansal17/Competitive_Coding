#include <stdio.h>

int main(){
	int i, j, a = 7, b;
	
	for(i = 1; i <= 9; i = i + 2){
		for(b = 1, j = a; b <= 3; j-- ,b++)
			printf("I=%d J=%d\n", i, j);
		
		a = a + 2;
		
	}
	
	
	return 0;
}
