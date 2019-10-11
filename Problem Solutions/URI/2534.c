#include <stdio.h>
#include <algorithm>

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int N, Q, i, v[112];
	while(scanf("%d %d", &N, &Q) != EOF){
		for(i = 0; i < N; i++){
			scanf("%d", v+i);
		}
		std::sort(v, v+N, cmp);
		while(Q--){
			scanf("%d", &i);
			printf("%d\n", v[i-1]);
		}
	}
	return 0;
}
