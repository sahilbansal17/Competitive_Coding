#include <stdio.h>

int main(){
	int x, n = 1, i;
	scanf("%d", &x);
	
	if(n < 0 || n > 13) return 0;
	
	for( i = x; i > 0; i--){
		n = n * i;

	}
	printf("%d\n", n);
	
	return 0;
}
