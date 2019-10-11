#include <stdio.h>

int main(){
	long long int n, i, valor, in = 0, out = 0;
	
	scanf("%lld", &n);
	
	
	for(i = 1; i <= n; i++){
		scanf("%lld", &valor);
		
		if(valor >= 10 && valor <= 20)
			in += 1;
		else
			out += 1;
		
	}
	printf("%lld in\n", in);
	printf("%lld out\n", out);
	
	return 0;
	
}
