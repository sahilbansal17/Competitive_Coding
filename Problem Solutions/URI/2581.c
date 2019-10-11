#include <stdio.h>
#define LEN 1123

int main(){
	char s[LEN];
	int N;
	scanf(" %d ", &N);
	while(N--){
		fgets(s, LEN, stdin);
		printf("I am Toorg!\n");
	}	
	return 0;
}
