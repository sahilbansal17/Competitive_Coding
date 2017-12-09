#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>

using namespace std;

#define MAXN 105
#define INF 1<<30

typedef struct node{
	int t, c;
	node(){}
	node(int T, int C) : t(T), c(C){}
	bool operator < (const node &x) const{
    return c < x.c;
  }
}No;

vector<No> adj[MAXN];
int mark[MAXN];
int d[MAXN];
priority_queue<No> pq;

int dijkstra(int s, int t){

  for(int i = 0; i < MAXN; i++) {
    mark[i] = 0;
    d[i] = INF;
  }

	printf("%d %d", s, t);

  pq.push(No(s,0));

  while(!pq.empty()){
    No top = pq.top(); pq.pop();

    if(top.t == t){
			return top.c;
    }

    if(mark[top.t] == 1) continue;
    mark[top.t] = 1;

    for(int i = 0; i < adj[top.t].size(); i++){
      int v = adj[top.t][i].t;
      int cost = adj[top.t][i].c;

      if (top.c + cost < d[v]){
        d[v] = top.c + cost;
        pq.push(No(v, top.c + cost));
      }
    }
	}

  return -1;
}

int main(){
  int T; // Number of edges
	scanf("%d", &T);
  //Nodes are numbered from 0 to MAXN-1
  while(T-- > 0){
      int a,b,c;
      scanf("%d %d %d", &a, &b, &c);
      adj[a].push_back(No(b,c)); //Unidirectional adj
  }

	int source, destination;

	scanf("%d %d", &source, &destination);

	int result = dijkstra(source, destination);

  if(result == -1){
    printf("There is no path to destination\n");
  }else{
    printf("The path from %d to %d has cost %d\n", source, destination, result);
  }
}
