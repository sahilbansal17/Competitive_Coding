#include <iostream>
#include <vector>
#include <algorithm>

// name: Anne Livia da F. Macedo
// email: annelivia16@gmail.com

using namespace std;

vector<vector<int>>v;
vector<int>vi, outDegree;

void space(int n) {
    while(n--)
        cout << " ";
}

void dfs(int ve, int b = 2) {
    vi[ve] = true;
    for (int i = 0; i < (int)v.size(); i++) {
        if(v[ve][i] == 1) {
            if(!vi[i]) {
                space(b);
                cout << ve << "-" << i << " pathR(G," << i << ")\n";
                dfs(i, b + 2);
            } else {
                space(b);
                cout << ve << "-" << i << endl;
            }
        }
    }
}

int main()
{
    int t, ve, e, u1, u2, c = 1;
    cin >> t;
    while(t--) {
        cin >> ve >> e;
        v.assign(ve, vector<int>(ve, 0));
        vi.assign(ve, 0);
        outDegree.assign(ve, 0);
        while(e--) {
            cin >> u1 >> u2;
            v[u1][u2] = 1;
            outDegree[u1]++;
        }

        cout << "Caso " << c++ << ":" << endl;
        for (int i = 0; i < ve; i++) {
            if(!vi[i]) {
                dfs(i);
                if(outDegree[i])
                    cout << "\n";
            }
        }
    }
    return 0;
}
