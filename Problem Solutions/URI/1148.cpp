#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 250000001

// name: Anne Livia da F. Macedo
// email: annelivia16@gmail.com

using namespace std;

class Graph {
private:
    vector<vector<pair<int,int> > > gra;
    vector<vector<int> > AllDistTable;
    int nv;
public:
    Graph(int nv) {
        this->nv = nv;
        gra.assign(nv, vector<pair<int,int> >());
        AllDistTable.assign(nv, vector<int>(nv, -1));
    }

    void addEdge(int u, int v, int w) {
        auto it = find_if(gra[v].begin(), gra[v].end(), [&u](pair<int,int>& p) -> bool { return (u == p.first);});
        if(it != gra[v].end()) {
            w = 0;
            it->second = w;
        }
        gra[u].push_back({v,w});
    }

    int dijkstra(int o, int d) {
        if(AllDistTable[o][d] != -1)
            return AllDistTable[o][d];

        vector<int>dist(this->nv, INF);
        vector<int>vi(this->nv, 0);

        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

        pq.push({0, o});

        while(!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;

            if(!vi[u]) {
                dist[u] = d;
                vi[u] = 1;
            }

            pq.pop();

            for(int i = 0; i < (int) gra[u].size(); i++) {
                int v = gra[u][i].first;
                int w = gra[u][i].second;
                if(dist[u] + w < dist[v] && !vi[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        for (int i = 0; i < this->nv; i++) {
            AllDistTable[o][i] = dist[i] == INF ? -1 : dist[i];
        }

        return AllDistTable[o][d];
    }
};

int main()
{
    int n, m, x, y, w;
    while(cin >> n >> m && n != 0 || m != 0) {
        Graph g(n);
        while(m--) {
            cin >> x >> y >> w;
            --x, --y;
            g.addEdge(x,y,w);
        }

        cin >> w;
        while(w--) {
            cin >> x >> y;
            --x,--y;
            int res = g.dijkstra(x,y);
            if(res == -1)
                cout << "Nao e possivel entregar a carta\n";
            else
                cout << res << endl;
        }
        cout << endl;
    }
    return 0;
}
