#include <bits/stdc++.h>
using namespace std;
vector<vector<long int>> a(100001);
vector<vector<int>> node(100001);

long int x[100001],y[100001];

void create(int root,int n,int r,int k)
{
    for(int i=0;i<n;i++){
        if(x[i]==root && y[i]!=r){
            a[root].push_back(y[i]);
            node[k].push_back(y[i]);
            create(y[i],n,root,k+1);
        }
        if(y[i]==root && x[i]!=r){
            a[root].push_back(x[i]);
            node[k].push_back(x[i]);
            create(x[i],n,root,k+1);
        }
    }
    return;
}
    
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int n,q,g,h;
    long int d,k,o=0,s[100001];
    char c;
    long long int b[100001];

    cin>>n>>q;
    for(int i=0;i<n-1;i++){
        cin>>x[i]>>y[i];
//        a[min(x,y)].push_back(max(x,y));
    }  
    node[0].push_back(1);
    create(1,n-1,0,1);
    for(int i=n;i>=0;i--){
        for(int j=0;j<node[i].size();j++){
            s[o]=node[i][j];
            o++;
        }
    }
//    for(int i=1;i<=n;i++){for(int j=0;j<a[i].size();j++) cout<<a[i][j]<<" ";cout<<"\n";}
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int k=0;k<q;k++)
    {
        cin>>c;
        if(c=='+')
            cin>>g>>h;
        else if(c=='?')
            cin>>g;
        for(int i=0;i<o;i++){
            for(int j=0;j<a[s[i]].size();j++){
                b[a[s[i]][j]]+=b[s[i]];
            }
            if(a[s[i]].size()!=0)
                b[s[i]]=0;
        }
        if(c=='+')
            b[g]+=h;
        if(c=='?')
            cout<<b[g]<<"\n";
//        for(int i=1;i<=n;i++)
//            cout<<b[i]<<" ";
//       cout<<"\n";
    }

        
    return 0;    
}
