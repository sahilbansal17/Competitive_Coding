#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'
const int MAX = 2e5 + 10;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {
private:
    vector <int> p, rank, setSize; 
    int numSets;
public:
    UnionFind(int N){
        setSize.assign(N, 1); 
        numSets = N; 
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i; 
    }
    int findSet(int i){ 
        return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
    }
    bool isSameSet(int i, int j){ 
        return findSet(i) == findSet(j); 
    }
    void unionSet(int i, int j){ 
        if (isSameSet(i, j)) {
            return ;
        }
        numSets--; 
        int x = findSet(i), y = findSet(j);
        // rank is used to keep the tree short
        if (rank[x] > rank[y]){
            p[y] = x; 
            setSize[x] += setSize[y];
        }
        else{ 
            p[x] = y; 
            setSize[y] += setSize[x];
            if(rank[x] == rank[y]) 
                rank[y]++; 
        } 
    }
    int numDisjointSets(){ 
        return numSets; 
    }
    int sizeOfSet(int i){ 
        return setSize[findSet(i)]; 
    }
}; // reference: CP3 by Steven Halim

int main() {
    FAST_IO;

    int n;
    cin >> n;

    vector<int> p(n);
    for (auto &x: p) {
        cin >> x;
    }

    UnionFind UF(n);
    for (int i = 0; i < n; ++i) {
        int cur = p[i] - 1;
        UF.unionSet(i, cur);
    }

    cout << UF.numDisjointSets() << endl;
    return 0;
}