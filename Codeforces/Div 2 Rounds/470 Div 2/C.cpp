/* 	
 	author		: 	sahilbansal17
	date		:	15th March, 2018	
*/
#include <stdio.h>

using namespace std;

int N;
long long V[100005]; // volume
long long T[100005]; // temperature
long long S[100005]; // prefix sum for temp
int D[100005]; // helping array to calculate count for each day i.e. X[k]
long long E[100005];	// extra amount for each day
int X[100005];	// count for each day 
// result is simply T[k]*X[k] + E[k]

long long sum(int s, int e) {
	return S[e] - S[s - 1];
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%lld", &V[i]);
	for(int i = 1; i <= N; i++) scanf("%lld", &T[i]);
	for(int i = 1; i <= N; i++) S[i] = S[i - 1] + T[i];

	for(int i = 1; i <= N; i++) {
		int l = i, r = N;
		while(l <= r) {
			int m = (l + r) >> 1;
			if(V[i] < sum(i, m)) r = m - 1;
			else l = m + 1;
		}
		D[i]++; D[l]--;
		E[l] += V[i] - sum(i, r);
	}
	for(int i = 1; i <= N; i++) X[i] = X[i - 1] + D[i];
	for(int i = 1; i <= N; i++) {
		printf("%lld ", X[i] * T[i] + E[i]);
	}

	return 0;
}

