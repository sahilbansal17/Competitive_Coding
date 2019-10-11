#include <stdio.h>

int main(){
	unsigned long long int n;
	
	while(scanf("%llu", &n)){
		if(n == -1ll) break;
		if(n == 0ll) printf("0\n");
		else(printf("%llu\n", n - 1ll));
		
	}
	
	return 0;
	
}
