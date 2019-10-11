#include <stdio.h>

int main(){
	int n;
	
	scanf("%d", &n);
	
	while(n--){
		int ano, dif;
		scanf("%d", &dif);
		
		if(dif < 2015){
			ano = 2015 - dif;
			printf("%d D.C.\n", ano);
		}else{
			ano = dif - 2014;
			printf("%d A.C.\n", ano);
		}
		
	}
	
	
	return 0;
	
	
}
