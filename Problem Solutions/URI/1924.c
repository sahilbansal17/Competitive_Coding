#include <stdio.h>

int main(){
	
	int i, n;
	char curso[100];
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		gets(curso);
		getchar();
	}
	
	printf("Ciencia da Computacao\n");
	return 0;	
}
