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
}; // source: CP3 by Steven Halim

class Solution {
public:
    int earliestAcq(vector<vector<int>>& l, int N) {
        vector <pair <int, pair <int, int>>> logs;
        for (int i = 0; i < l.size(); i ++) {
            logs.push_back({l[i][0], {l[i][1], l[i][2]}});
        }
        sort(logs.begin(), logs.end());
        
        UnionFind UF(N);
        if (N == 1) {
            return 0;
        }
        for (int i = 0; i < logs.size(); i ++) {
            int x = logs[i].second.first;
            int y = logs[i].second.second;
            if (!UF.isSameSet(x, y)) {
                UF.unionSet(x, y);
            }
            if (UF.numDisjointSets() == 1) {
                return logs[i].first;
            }
        }
        return -1;
    }
};