#include <stdio.h>
#define LEN 28
#define MAX 11234

int main(){
	char s[LEN], m[MAX];
	int N, i, x;
	while(scanf("%s ", s) != EOF){
		scanf("%d ", &N);
		for(i = 0; i < N; i++){
			scanf("%d ", &x);
			m[i] = s[x-1];
		}
		m[N] = 0;
		printf("%s\n", m);
	}
	return 0;
}
