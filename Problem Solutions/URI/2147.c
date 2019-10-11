#include <stdio.h>
#include <string.h>

int main(){
	int n, length;
	char galopeira[10100];
	scanf("%d", &n);
	
	while(n--){
		scanf("%s", galopeira);
		length = strlen(galopeira);
		printf("%.2lf\n", length *.01); 
		
	}
	return 0;
}
