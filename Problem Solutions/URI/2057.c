#include <stdio.h>

int main(){
	int x, y, z, soma;
	
	scanf("%d %d %d", &x, &y, &z);
	soma = x + y + z;
	
	if(soma < 0)
		soma = 24 + soma;
	
	printf("%d\n", soma % 24);
	
	
	return 0;	
}
