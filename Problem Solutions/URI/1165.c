#include <stdio.h>

int main(){
	int n , x, count = 0, i, j;
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		scanf("%d", &x);
		
		for(j = 1; j <= x; j++){
			if(x % j == 0){
				count++;
			}
		}
		
		if(count > 2)
			printf("%d nao eh primo\n", x);
		else
			printf("%d eh primo\n", x);
			
		count = 0;
	}
	
	
	return 0;
	
	
}
