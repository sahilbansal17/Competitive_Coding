#include <stdio.h>

int main(){
	int c1, c2;
	
	while(scanf("%d %d", &c1, &c2) != EOF){
		if( c1 == c2){
			printf("%d\n", c1);			
		}else if(c1 > c2)
			printf("%d\n", c1);
		else if( c1 < c2) 
			printf("%d\n", c2);
		
	}
	
	return 0;
	
	
}
