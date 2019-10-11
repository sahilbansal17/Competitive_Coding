#include <stdio.h>

int main(){
	int i, k;
	
	for(i = 1; i <= 9; i = i + 2){
		for(k = 7; k >= 5; k--)
			printf("I=%d J=%d\n", i, k);
		
	}
	return 0;
	
}
