// CodeChef October Challenge 2019 - Operations on a Matrix
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	ll t,n,m,q;
	cin>>t;
	while(t--){
		ll i,j;
		cin>>n>>m>>q;
		ll O[q][2],x[n] = {0}, y[m] = {0};
		for(i=0;i<q;i++){
			cin>>O[i][0]>>O[i][1];
			x[O[i][0] - 1]++;
			y[O[i][1] - 1]++;
		}
		// solution is based of observation of how many possible times a position can be incremented as per the question
		ll oddrow=0,oddcol=0,evenrow=0,evencol=0;
		for(i=0;i<n;i++){
			if(x[i] %2 == 0)
				evenrow++;
			else
				oddrow++;
		}
		for(i=0;i<m;i++){
			if(y[i] %2 == 0)
				evencol++;
			else
				oddcol++;
		}
		//below formula indicates every odd possibility (odd + even == even + odd == an odd number)
		cout<<(evenrow*oddcol + oddrow*evencol)<<endl;
		
	}
}
