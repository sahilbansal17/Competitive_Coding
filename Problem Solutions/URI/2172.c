#include <stdio.h>

int main(){
	long long int x, y ;
	
	while(1){
		scanf("%lld %lld", &x, &y);
		if(x == 0 && y == 0)
			break;
		
		printf("%lld\n", x * y);
	}
	
	return 0;
}
