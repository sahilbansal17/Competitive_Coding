/**
Being given an N*N chess board (N <= 20), determine a sequence of moves of a knight such that he visits every square only once.
This sequence is named a 'Knight's Tour'.

Given that N <= 20, a backtracking algorithm fails to provide an answer in a reasonable amount of time.
However, there is an heuristic approach which works quite well:
    At each step, move the knight to the position which leads to the minimum number of possible onward moves.
    We need to ignore the already visited tiles.

More naturally speaking, this approach tries to first visit remote positions that are harder to access.
This problem can also be translated to a graph problem: a knight's tour can be considered a Hamiltonian Path.

Although this problem is NP-Hard, this heuristic can solve the problem for various configurations in linear time.
**/

#include <bits/stdc++.h>

using namespace std;

int N;

int v[100][100],
    lin[] = {0, -2, -1, 1, 2, 2, 1, -1, -2},
    col[] = {0, 1, 2, 2, 1, -1, -2, -2, -1},
    n;

int possibleMoveCount(int l, int c)
{
    int nr = 0;
    for(int k = 1; k <= 8; k++)
    {
        int nL = l + lin[k],
            nC = c + col[k];

        if(nL >= 1 && nL <= n && nC >= 1 && nC <= n)
            if(v[nL][nC] == 0)
                nr++;
    }
    return nr;
}

int main()
{
    cout << "Board size: ";
    cin >> n;

    int l = 1,
        c = 1;
    v[1][1] = 1;

    for(int i = 2; i <= n*n-1; i++) {
        int minMut = 10, dir = 0;
        for(int k = 1; k <= 8; k++) {
            int nL = l + lin[k],
                nC = c + col[k];

            if(nL >= 1 && nL <= n && nC >= 1 && nC <= n)
                if(v[nL][nC] == 0) {
                    int nr = possibleMovecount(nL, nC);
                    if(nr != 0 && nr < minMut) {
                       minMut = nr;
                       dir = k;
                    }

                }
        }

        l += lin[dir];
        c += col[dir];
        v[l][c] = i;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << setw(4) << (v[i][j] == 0 ? n*n : v[i][j]);
        cout << endl;
    }

    return 0;
}
