#include <stdio.h>

int main(){
	int n, numero, i, count = 0;
	scanf("%d", &n);
	
	for(i = 0; i < 5; i++){
		scanf("%d", &numero);
		if( numero == n)
			count++;
	}
	printf("%d\n", count);
	
	return 0;
}
