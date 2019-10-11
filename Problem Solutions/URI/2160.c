#include <stdio.h>
#include <string.h>
int main(){
	char nome[600];
	
	gets(nome);
	if(strlen(nome) > 80)
		printf("NO\n");
	else
		printf("YES\n");
		
	return 0;	
}
