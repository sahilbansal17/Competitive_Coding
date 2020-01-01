
#include <bits/stdc++.h> 
using namespace std;

                void solve(){   

                        long long n;
                        cin>>n;
                        vector<pair<long long>> vec(n);
                        for(int i=0;i<n;i++)
                                cin>>vec[i].first>>vec[i].second;

                        sort(vec.begin(),vec.end());
                        long long  wl=vec[n-1].ff;
                        long long  cnt=1;
                        for(int i=n-2;i>=0;i--){
                                if(vec[i].ss>wl)
                                        continue;
                                ++cnt;
                                wl=vec[i].ff;
                        }
                        cout<<cnt<<'\n';
                }

                int main(){ 
                        ll t;
                        cin>>t;
                        for (int i=1; i<=t; i++){
                                solve();
                         }
        return 0; 
}         
