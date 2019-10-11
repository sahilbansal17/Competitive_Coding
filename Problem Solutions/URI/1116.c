#include <stdio.h>

int main(){
	int n, x, y, i;
	float result, a, b;
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		scanf("%d %d", &x, &y);
		
		if(y == 0){
			printf("divisao impossivel\n");
		}
		else{
			a = x;
			b = y;
			result = a/b;
			printf("%.1f\n", result);
		}
		
	}
	
	return 0;
}
