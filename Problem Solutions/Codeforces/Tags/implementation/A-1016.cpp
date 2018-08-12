#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, sum = 0;
	cin>>n>>m;
	for(int i = 0; i < n; i ++){
		int a;
		cin>>a;
		sum += a;
		cout<<sum/m;
		cout<<" ";
		if(sum >= m){
			sum = sum % m;
		}
	}
	return 0;
}