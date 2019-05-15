#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// name: Anne Livia da F. Macedo
// email: annelivia16@gmail.com

vector<vector<int>>g;
vector<int>vi, ans;

void dfs(int v) {
    vi[v] = true;
    ans.push_back(v + 'a');
    for (int i = 0; i < (int)g[v].size(); i++) {
        if(!vi[g[v][i]])
            dfs(g[v][i]);
    }
}

ostream& operator << (ostream& stream, vector<int>&v){
    for(auto i : v) {
        stream << (char)i << ",";
    }
    return stream;
}

int main()
{
    int t, v, e, c = 1, components;
    char u, w;

    cin >> t;
    while(t--) {
        components = 0;
        cin >> v >> e;
        g.assign(v, vector<int>());
        vi.assign(v,0);
        while(e--) {
            cin >> u >> w;
            g[u - 'a'].push_back(w - 'a');
            g[w - 'a'].push_back(u - 'a');
        }

        cout << "Case #" << c++ << ":" << endl;
        for (int i = 0; i < v; i++) {
            if(!vi[i]) {
                dfs(i);
                sort(ans.begin(), ans.end());
                cout << ans << endl;
                ans.clear();
                components++;
            }
        }
        cout << components << " connected components\n\n";
    }
    return 0;
}
