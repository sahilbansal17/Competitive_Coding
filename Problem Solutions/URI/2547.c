#include <stdio.h>

int main(){
	int n, min, max, alt, count;
	
	while(scanf("%d %d %d", &n, &min, &max) != EOF){
		count = 0;
		while(n--){
			scanf("%d", &alt);
			
			if( min <= alt && alt <= max) count++;
		}printf("%d\n", count);
	}
	
	return 0;
	
}
