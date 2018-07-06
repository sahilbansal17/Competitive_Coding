#include <bits/stdc++.h>

using namespace std;

/* Template file for Online Algorithmic Competitions */
/* Typedefs */
    /* Basic types */
    typedef long long           ll;
    typedef unsigned long long ull;
    /* STL containers */
    typedef vector <int>    vi;
    typedef vector <ll>     vll;
    typedef pair <int, int> pii;
    typedef pair <ll, ll>   pll;
    typedef vector < pii >  vpii;
    typedef vector < pll >  vpll;
    typedef vector <string> vs;
    typedef vector < vi >   vvi;
/* Macros */
    /* Loops */
    #define fl(i, a, b)     for(int i(a); i<(b); i++)
    #define rep(i, n)       fl(i, 0, n)
    #define rep1(i, n)      fl(i, 1, n)
    #define rfl(i, a, b)    for(int i(a);i>=(b);i--)
    /* Algorithmic functions */
    #define srt(v)          sort((v).begin(),(v).end())
    /* STL container methods */
    #define pb              push_back
    #define mp              make_pair
    /* String methods */
    #define slen(s)         s.length()
    /* Shorthand notations */
    #define F               first
    #define S               second
    #define MOD             1000000007
    #define MAX             100010
    #define re              return 
    #define sz(x)           ((int) (x).size())
    #define all(x)          (x).begin(), (x).end()
    #define sqr(x)          ((x) * (x))
    #define fill(x, y)      memset(x, y, sizeof(x))
/* Templates */
template<class T> T abs(T x) { re x > 0 ? x : -x; }

	
int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

    int n, q, coin_value;

    cin >> n >> q;

    vi powers_ct(32, 0), coins(n, 0);

    rep(i, n){
        cin >> coins[i];
    }

    srt(coins);

    int p = 0, v = 1;
    rep(i, n){
        while(v != coins[i]){
            p++;
            v *= 2;
        }
        powers_ct[p] ++;
    }

    // rep(i, 32){
    //     cout << powers_ct[i] << " ";
    // }
    // cout << "\n";

    int x;

    rep(l, q){
        vector <bool> setb(32, 0);
        vi temp(32, 0), temp2(32, 0);
        temp = powers_ct;
        temp2 = powers_ct;
        cin >> x;
        p = 1;
        rep(k, 32){
            if(x & p){
                setb[k] = 1;
            }
            p = (p << 1);
        }

        // rep(i, 32){
        //     cout << setb[i] << " ";
        // }
        // cout << "\n";
    
        bool flag = 1;
        int ans = 0;
        rep(i, 30){
            if(temp[i] >= 2 && setb[i] == 0){
                if(temp[i] % 2 == 0){
                    temp[i + 1] += (temp[i] / 2);
                    temp[i] = 0;
                }
                else{
                    temp[i + 1] += (temp[i] - 1)/2;
                    temp[i] = 1;
                }
            }
            else if(temp[i] >= 2 && setb[i] == 1){
                temp[i] -= 1;
                if(temp[i] % 2 == 0){
                    temp[i + 1] += (temp[i] / 2);
                    temp[i] = 0;
                }
                else{
                    temp[i + 1] += (temp[i] - 1)/2;
                    temp[i] = 1;
                }

                if(powers_ct[i] >= 1){
                    temp2[i] --;
                    ans ++;
                }
                else{
                    int val = 0, get = pow(2, i);
                    int j = i - 1;
                    while(j >= 0){
                        int cur = temp2[j]*pow(2, j);
                        if(val + cur > get){
                            ans += (get - val)/(pow(2, j));
                            temp2[j] -= (get - val)/(pow(2, j));
                            break;
                        }
                        val += cur;
                        ans += temp2[j];
                        temp2[j] = 0;
                        if(val == get){
                            break;
                        }
                        j --;
                    }
                }
            }
            else if(setb[i] == 1 && temp[i] == 0){
                flag = 0;
                break;
            }
            else if(setb[i] == 1 && temp[i] == 1){
                if(powers_ct[i] >= 1){
                    temp2[i] --;
                    ans ++;
                }
                else{
                    int val = 0, get = pow(2, i);
                    int j = i - 1;
                    while(j >= 0){
                        int cur = temp2[j]*pow(2, j);
                        if(val + cur > get){
                            ans += (get - val)/(pow(2, j));
                            temp2[j] -= (get - val)/(pow(2, j));
                            break;
                        }
                        val += cur;
                        ans += temp2[j];
                        temp2[j] = 0;
                        if(val == get){
                            break;
                        }
                        j --;
                    }
                }
                temp[i] = 0;
            }
            // cout << temp[i] << " ";
        }
        // cout << "\n";
        if(flag == 0){
            cout << "-1\n";
        }
        else{
            cout << ans << "\n";
        }
    }   
	return 0;
}