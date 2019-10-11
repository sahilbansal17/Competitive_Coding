#include <stdio.h>

int main(){
	int n, i, curr, prev, count;
	
	while(scanf("%d", &n) != EOF){
		scanf("%d", &n);
		
		count = 1;
		
		for(i = 1; i< n; i++){
			scanf("%d", &curr);
			if(prev < curr) count += 1;
			
			prev = curr;
		}
		
		printf("%d\n", count);
		
	}
	return 0;	
}
