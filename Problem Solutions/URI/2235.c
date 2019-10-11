#include <stdio.h>

int main(){
	int a, b, c;
	
	scanf("%d %d %d", &a , &b, &c);
	
	if(a - b == 0) printf("S\n");
	else if( a - c == 0) printf("S\n");
	else if( b - c == 0) printf("S\n");
	else if((a + b) - c == 0) printf("S\n");
	else if((b + c) - a == 0) printf("S\n");
	else if((a + c) - b == 0) printf("S\n");
	else printf("N\n");
	
	return 0;	
}
