#include <stdio.h>

int main(){
	int n, i, x, j, count;
	
	while(scanf("%d %d", &n, &i) != EOF){
		count = 0;
		while(n--){
			scanf("%d %d", &x, &j);
			if( x == i && j == 0) count++;
		}
		printf("%d\n", count);
	}
	
	return 0;

}
