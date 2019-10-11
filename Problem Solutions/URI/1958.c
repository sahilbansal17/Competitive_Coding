#include <stdio.h>

int main(){
	long double n;
	char array[120];
	
	scanf("%LE", &n);
	sprintf(array,"%LE", n);
	
	if(array[0] != '-')
		printf("+");
		
	printf("%.4LE\n", n);
	
	return 0;
	
}
