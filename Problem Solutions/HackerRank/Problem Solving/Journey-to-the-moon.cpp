#include <bits/stdc++.h>
using namespace std;
vector<list<long long> > G;
vector<bool> visited;
long long vertices=0;
void DFS(long long u){
    if(visited[u]) return ;
    visited[u]=true;
    vertices++;
    for(auto i: G[u])
        if(!visited[i])
            DFS(i);
}
int main(){
    long long n,e,u,v;
    cin>>n>>e;
    long long ans=n*(n-1)/2;
    G.resize(n);
    visited.resize(n,false);
    vector<int> M;
    while(e--){
        cin>>u>>v;
        G[u].push_front(v); G[v].push_front(u);
    }
    for(long long i=0;i<n;i++){
        vertices=0;
        DFS(i);
        ans=ans-vertices*(vertices-1)/2;
    }
    cout<<ans;
    return 0;
}
