#include <stdio.h>

int main(){
	int x, i, n;
	
	while(scanf("%d", &x) && x){
		
		for(i = 1; i <= x; i++){
			scanf("%d", &n);
			if(n % 2)
				printf("%d\n", n * 2 - 1);
			else
				printf("%d\n", n * 2 - 2);
			
		}
		
	}


}
