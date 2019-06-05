#include <iostream>
#include <stack>
#include <vector>

// name: Anne Livia da F. Macedo
// email: annelivia16@gmail.com

using namespace std;

class Intersection {
private:
    vector<vector<int>> adj;
    int nv;
public:
    Intersection(int nv) : nv (nv) {
        this->adj.assign(nv, vector<int>());
    }

    void createStreet(int u, int v) {
        this->adj[u].push_back(v);
    }

    Intersection transpose() {
        Intersection in(this->nv);
        for (int i = 0; i < this->nv; i++) {
            for(int j = 0; j < (int)this->adj[i].size(); j++) {
                in.createStreet(adj[i][j],i);
            }
        }
        return in;
    }

    void dfs(vector<int>&vi, int v) {
        vi[v] = true;
        for (int i = 0; i < (int)adj[v].size(); i++) {
            if(!vi[adj[v][i]])
                dfs(vi, adj[v][i]);
        }
    }

    void allDFS(vector<int>&vi, stack<int>&s, int v) {
        vi[v] = true;
        for (int i = 0; i < (int)adj[v].size(); i++) {
            if(!vi[adj[v][i]])
                allDFS(vi, s, adj[v][i]);
        }
        s.push(v);
    }

    bool kosaraju() {
        int scc = 0;
        vector<int>vi(this->nv, 0);
        stack<int>s;
        for (int i = 0; i < this->nv; i++) {
            if(!vi[i]) {
                allDFS(vi, s, i);
            }
        }

        Intersection tI = this->transpose();

        vi.assign(this->nv, 0);

        while(!s.empty()) {
            int v = s.top();
            s.pop();
            if(!vi[v]) {
                tI.dfs(vi, v);
                scc++;
            }
        }

        if(scc == 1)
            return true;
        return false;
    }
};

int main()
{
    int nIntersections, mStreets, v, w, p;
    while(cin >> nIntersections >> mStreets && nIntersections) {
        Intersection in(nIntersections);
        while(mStreets--){
            cin >> v >> w >> p;
            in.createStreet(--v, --w);
            if(p == 2) {
                in.createStreet(w, v);
            }
        }
        cout << in.kosaraju() << endl;
    }
    return 0;
}
