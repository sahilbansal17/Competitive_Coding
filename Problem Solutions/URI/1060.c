#include <stdio.h>


int main(){
	int positivos, i;
	double num;
	
	for(i = 1; i <= 6; i++){
		scanf("%lf", &num);
		
		if(num > 0){
			positivos += 1;
		}
	}
	
	
	printf("%d valores positivos\n", positivos);
	return 0;
	
}
