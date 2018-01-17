#include <bits/stdc++.h>

using namespace std;

int main(){

	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int t,a,b,c,d;
	cin >> t;

	while(t--){

		cin >> a >> b >> c >> d;

		if((a ^ b ^ c ^ d) == 0){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}

	}

	return 0;
}