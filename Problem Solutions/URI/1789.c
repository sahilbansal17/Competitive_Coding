#include <stdio.h>

int main(){
	int a , i, n, max = 0;
	
	while( scanf("%d", &a ) != EOF){
		for(i = 1, max = 0; i <= a; i++){
			scanf("%d", &n);
			if(n > max)
				max = n;
			
		}
		if(max < 10)
			printf("1\n");
		else if(max < 20)
			printf("2\n");
		else
			printf("3\n");
		
	}
	
	return 0;
	
}
