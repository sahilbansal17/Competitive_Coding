#include <stdio.h>

int main(){
	int N, v, i, c;
	while(scanf("%d", &N) != EOF){
		c = 0;
		for(i = 0; i < N; i++){
			scanf("%d", &v);
			if(v) c++;
		}
		if(c >= (N - c) * 2)
			printf("impeachment\n");
		else 
			printf("acusacao arquivada\n");
	}
	return 0;
}
