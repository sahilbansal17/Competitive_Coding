#include <stdio.h>
#include <string.h>

int main(){
	char n[25], t = 0;
	scanf("%s", n);
	
	int tmn = strlen(n);
	int i, j;
	
	for(i = 0; j = tmn - 1; i < tmn / 2; i++, j--){
		t = n[i];
		n[i] = n[j];
		n[j] = temp;
	}
	printf("%s\n", n);
	return 0;
	
	
	
	
}
