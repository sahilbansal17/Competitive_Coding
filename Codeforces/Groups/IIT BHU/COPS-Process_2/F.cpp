/*
    1 1
    0

The above test case gave a runtime error in earlier submissions
since the vpii surroundZero had a size of zero and it was accessed.
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;
typedef pair <int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define fl(i,a,b) for(int i(a);i<(b);i++)
#define rep(i,n) fl(i,0,n)
#define rfl(i,a,b) for(int i(a);i>=(b);i--)
#define srt(v) sort((v).begin(),(v).end())
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define slen(s) s.length()
#define F first
#define S second
#define MAX 1005
typedef vector < pii > vpii;

bool visited[MAX][MAX];
char lib[MAX][MAX];
bool graph[MAX][MAX];
int xdir[4] = {-1, 1, 0, 0};
int ydir[4] = {0, 0, -1, 1};
vpii comp; // connected component
int size[MAX][MAX]; // component size of each true entry
int comp_no[MAX][MAX]; // component id
int current_comp = 1;
vpii surroundZero;
int n, m;

void dfs_helper(int i, int j){
    visited[i][j] = true;
    rep(k, 4){
        int xnext = i + xdir[k];
        int ynext = j + ydir[k];
        if(!visited[xnext][ynext] && graph[xnext][ynext] != 0 && (xnext > 0 && xnext <= n) && (ynext > 0 && ynext <= m)){
            dfs_helper(xnext, ynext);
        }
    }
    // cout << i << " " << j << "\n";
    comp.pb(mp(i, j));
}

void dfs(){
    fl(i, 1, n + 1){
        fl(j, 1, m + 1){
            if(!visited[i][j] && graph[i][j] == 1){
                dfs_helper(i, j);
                // cout << comp.size() << "\n";
                int sz = comp.size();
                rep(k, comp.size()){
                    int x = comp[k].F;
                    int y = comp[k].S;
                    size[x][y] = sz;
                    comp_no[x][y] = current_comp;
                }
                comp.erase(comp.begin(), comp.end());
                current_comp ++ ;
            }
        }
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    #endif

    cin >> n >> m;

    char c;
    rep(i, n){
        rep(j, m){
            cin >> c;
            lib[i][j] = c;
        }
    }
    rep(i, n){
        rep(j, m){
            if(lib[i][j] == '1'){
                graph[i + 1][j + 1] = 1;
            }
            else{
                graph[i + 1][j + 1] = 0;
            } 
            visited[i + 1][j + 1] = false;
            size[i + 1][j + 1] = 0;
            comp_no[i + 1][j + 1] = 0;
        }
    }

/*
    fl(i, 1, n + 1){
        fl(j, 1, m + 1){
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
*/  
    dfs();

/*
    fl(i, 1, n + 1){
        fl(j, 1, m + 1){
            cout << size[i][j] << " ";
        }
        cout << "\n";
    }
*/

    fl(i, 1, n + 1){
        fl(j, 1, m +1){
            if(graph[i][j] == 1){
                cout << ".";
            }
            else{
                int sz = 1;
                rep(k, 4){
                    int xnext = i + xdir[k];
                    int ynext = j + ydir[k];
                    if((xnext > 0 && xnext <= n) && (ynext > 0 && ynext <= m)){
                        surroundZero.pb(mp(comp_no[xnext][ynext], size[xnext][ynext]));    
                    }
                }
                if(surroundZero.size() > 0){
                    srt(surroundZero);
                    int prev = surroundZero[0].F; // first comp id
                    sz += surroundZero[0].S; // size
                    fl(k, 1, surroundZero.size()){
                        int next = surroundZero[k].F;
                        if(next > prev){
                            sz += surroundZero[k].S;
                            prev = next;
                        }
                    }
                    surroundZero.erase(surroundZero.begin(), surroundZero.end());
                }
                cout << sz % 9;
            }
        }
        cout << "\n";
    }
	return 0;
}