
#include <bits/stdc++.h> 
using namespace std; 
#define rep(i, a, b) for (int i=a; i<(b); i++)

                void solve(){   

                        long long n;
                        cin>>n;
                        vector<pair<long long>> vec(n);
                        rep(i,0,n)
                                cin>>vec[i].first>>vec[i].second;
                        long long dist,fl;
                        cin>>dist>>fl;
                        rep(i,0,n)
                                vec[i].ff=dist-vec[i].ff;
                        vec.push_back(make_pair(dist,0));
                        sort(vec.begin(),vec.end());
                        priority_queue<ll> q;

                        long long cnt=0;
                        rep(i,0,n+1){
                                while(!q.empty()&&fl<vec[i].ff){
                                        fl+=q.top();
                                        q.pop();
                                        ++cnt;
                                        // cout<<q.top()<<" ";
                                }
                                if(fl<vec[i].ff){
                                        cout<<"-1\n";
                                        return ;
                                }
                                q.push(vec[i].ss);
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
