#include <stdio.h>

int main(){
	int senha;
	
	while(scanf("%d", &senha) != EOF){
		printf("%d\n", senha - 1);
		
	}
	
	return 0;
}
