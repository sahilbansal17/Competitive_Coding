
#include <bits/stdc++.h> 
using namespace std;
 
                void solve(){   
                	long long n;
                	cin>>n;
                	if(n==0)
                		exit(0);
                	vector<long long> vec(n);
                	for(int i=0;i<n;i++)
                		cin>>vec[i];
                	ll cnt=vec[0],ans=0;
                	for (int i=1; i<n; i++){
                		ans+=abs(cnt);
                		cnt+=vec[i];
                	}
                	cout<<ans<<'\n';
                }

                int main(){ 
                	while(1){
                		solve();
                	}
        return 0; 
}         
