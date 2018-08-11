#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int a[n], b[n];
	for(int i = 0; i < n; i ++)
		cin>>a[i]>>b[i];
	int max = 0;
	int inside = 0;
	for(int i = 0; i < n; i ++){
		inside -= a[i];
		inside += b[i];
		if(max < inside)
			max = inside;
	}
	cout<<max;
	return 0;
}