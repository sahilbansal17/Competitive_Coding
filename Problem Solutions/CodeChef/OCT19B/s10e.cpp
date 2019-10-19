// CodeChef October Challenge 2019 - Phone Prices
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		std::vector<int> v(n+1);
		v[0] = 0;
		for(int i=1;i<=n;i++)
			cin>>v[i];
		int count = 1;
		int valid[n+1];
		valid[1] = 1;
		int i,j;
		for(i=2;i<=n;i++){
			int k=0;
			for(j=i-1;j>=(i-5);j--){
				if(j<1) break;
				if(v[j] > v[i])
					k++;
			}	
			if(k == ((i-1) - j)){
				count++;
			}
		}
		cout<<count<<"\n";
	}
}
