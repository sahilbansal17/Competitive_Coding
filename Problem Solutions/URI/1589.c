#include <stdio.h>

int main(){
	int t, r1, r2, a, b;
	scanf("%d", &t);
	
	for(a = 1; a <= t; a++){
		scanf("%d %d", &r1, &r2);
		b = r1 + r2;
		printf("%d\n", b);
	}
	
	return 0;
	
}
