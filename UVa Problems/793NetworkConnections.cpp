#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

typedef vector<int> vi;

class UnionFind {

private:
    vi p, rank, setSize; //p for parent, rank is denoting height of the tree formed
    int numSets; //number of disjoint sets

public:
    UnionFind(int N) {
        setSize.assign(N, 1);
        numSets = N;
        rank.assign(N, 0);
        p.assign(N, 0);//should have taken N+1 size and started from index 0
        //caused seg fault as program tried to access p[1] when it has size 1 in
        //2nd sample case
        for (int i = 0; i < N; i++) {
            p[i] = i;
        }
    }

    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void UnionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            numSets--;
            int x = findSet(i);
            int y = findSet(j);
            if (rank[x] > rank[y]) {
                p[y] = x;
                setSize[x] += setSize[y];
            } else {
                p[x] = y;
                setSize[y] += setSize[x];
                if (rank[x] == rank[y]) {
                    rank[y]++;
                }
            }
        }
    }
};

int main() {

#ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/CP_Oct/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/CP_Oct/output.txt", "w", stdout);
#endif

    int t, n, x, y;
    cin >> t;
    char ch;
    while (t--) {
        int success = 0, failure = 0;
        cin >> n;
        UnionFind UF(n);
        cin >> ch;
        while (ch == 'c' || ch == 'q') {
            cin >> x >> y;
            if (ch == 'c') {//to resolve the error mentioned above
                //x-1 and y-1 are taken to start from 0 and not 1
                UF.UnionSet(x - 1, y - 1);
            } else if (UF.isSameSet(x - 1, y - 1)) success++;
            else failure++;
            if (!cin.eof()) {
                cin >> ch;
                if (cin.eof()) {
                    break;
                }
            }
        }
        cin.putback(ch);
        cout << success << "," << failure << endl;
        if (t != 0) cout << endl;
    }

    return 0;
}