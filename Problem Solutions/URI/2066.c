#include<stdio.h>

typedef long long ll;

ll pal(int x){
	int i;
	x /= 2LL;
	ll ret = 9LL;
	for(i = 1; i < x; i++)	
		ret *= 10LL;
	return ret;
}

int main(void){
	int k, i;
	ll ans[20];
	ans[1] = 0LL;
	ans[2] = 36LL;
	for(i = 3; i <= 18; i++){
		ans[i] = (i%2 == 1) ? 
			ans[i-1] * 10LL :
			ans[i-2] * 100LL + 45LL * pal(i-2);
	}
	while(scanf("%d", &k) != EOF){
		printf("%lld\n", ans[k]);
	}
	return 0;
}
