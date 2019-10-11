#include <stdio.h>

int main(){
	int x, i, j, num = 1;
	scanf("%d", &x);
	
	for(i = 1; i <= x; i++){
		for(j = 0; j < 3; j++){
			printf("%d ", num);
			num += 1;
		}
		printf("PUM\n");
		num += 1;
	}
	
	
	return 0;
}
