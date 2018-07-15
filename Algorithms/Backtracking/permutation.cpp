/* The idea in this program is to first form a graph
 * The graph will have adjacent edges such that their sum is equal to
 * a perfect square.
 * Next, we find a Hamiltonian path through the graph. The path is
 * in turn the permutation required.
 * The program prints nothing if a path is not present.
 *
 * To find a path, we first check for each node as the starting point.
 * We check place the next, and check whether or not we can add them by
 * verifying if they are already adjacent to some other vertex or not.
 *
 * If we end up finding one vertex that doesn't fit, we simply backtrack
 * and continue the solution.
 *
 */


#include <iostream>
#include <vector>

#define n 17
//Define your number here for simplicity of the program

using namespace std;

bool canAdd(int i, int graph[n+1][n+1], int* path, int p){

    if(graph[ path[p-1] ] [i] == 0 )
        return false;

    for(int j = 0; j < p; j ++)
        if( path[j] == i )
            return false;

    return true;
}

bool findPath(int graph[n+1][n+1], int *path, int p){

    if( p == n + 1  )
        return true;

    int i;
    for(i = 1; i <= n; i ++){
        if ( canAdd (i, graph, path, p) ){
            path[p] = i;
            if(findPath(graph, path, p + 1))
                return true;
            path[p] = -1; //backtrack
        }
    }
    return false;
}

int main(){

    int i, j;

    int graph[n + 1][n + 1];
    //Storing graph as an adjacency matrix

    for(i = 0; i <= n; i ++){
        for(j = 0; j <= n; j ++){
            graph[i][j] = 0;
        }
    }

    vector <int> squares;
    //Store all perfect squares less than n + (n-1), that is 2n-1

    for(i = 2; i*i < 2*n - 1; i ++){
        squares.push_back(i*i);
    }

    int sqno = squares.size();
    int sq, ps;

    for(i = 1; i <= n; i ++){
        for(j = 0; j < sqno; j ++){
            sq = squares[j];
            ps = sq - i;

            if( ps <= n && ps > 0 && 2*i!=sq ){
                graph[i][ps] = 1;
                graph[ps][i] = 1;
            }
        }
    }

    //Here, indexing starts from 1 in the graph, because natural numbers

    int path[n+1];

    for(i = 1; i <= n; i ++)
        path[i] = -1;

    for(i = 1; i <= n; i ++){
        path[1] = i;
        if(findPath(graph, path, 2)){
            for(int j = 1; j <= n; j ++){
                cout<<path[j]<<" ";
            }
            break;
        }
    }

    return 0;
}

/*
 * The time complexity of this program is O(n^3)
 * The first n for checking first element, then recurring for another n nodes,
 * and finally checking till worst case n loops for in canAdd function.
 * 
 * Auxiliary space used is O(n), n to store the Hamilton Path and a vector
 * of less than n elements to store the squares.
 */
