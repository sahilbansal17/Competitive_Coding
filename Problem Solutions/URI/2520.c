#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, M, i, j, p, x1, y1, x2, y2;
	while(scanf("%d %d", &N, &M) != EOF){
		for(i = 0; i < N; i++){
			for(j = 0; j < M; j++){
				scanf("%d", &p);
				if(p == 1){ x1 = i; y1 = j; }
				if(p == 2){ x2 = i; y2 = j; }
			}
		}
		printf("%d\n", abs(x1-x2) + abs(y1-y2));
	}
	return 0;
}
