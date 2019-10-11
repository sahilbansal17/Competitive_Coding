#include <stdio.h>

int main(){
	int M, N, C, i, x, y;
	while(scanf("%d", &M) != EOF){
		x = y = 0;
		for(i = 0; i < M; i++){
			scanf("%d %d", &N, &C);
			x += N * C;
			y += C;
		}
		y *= 100;
		printf("%.4lf\n", (double)x / (double)y);
	}
	return 0;
}
