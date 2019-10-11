#include <stdio.h>

int main(){
	int n, count;
	
	while(scanf("%d", &n) != EOF){
		count = 0;
		while(n > 1){
			n >>= 1;
			count++;
		}
		printf("%d\n", count);
	}
	
	return 0;
}
