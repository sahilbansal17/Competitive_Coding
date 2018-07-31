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

    int numbers;

    cin >> numbers;

    vi number(numbers, 0);

    rep(i, numbers){
        cin >> number[i];
    }

    // simply take the count of distinct numbers from the end

    // the pairs for a number = no. of distinct numbers after the number 

    // need to make sure that we don't overcount

    // so we set a number to be done, if its pairs are already taken 

    int count_distinct_from_index[numbers];

    count_distinct_from_index[numbers - 1] = 1;

    int count_array[100005] = {0};

    count_array[number[numbers - 1]] ++;
    rfl(i, numbers - 2, 0){
        if(count_array[number[i]] == 0){
            count_array[number[i]] = 1;
            count_distinct_from_index[i] = count_distinct_from_index[i + 1] + 1;
        }
        else{
            count_distinct_from_index[i] = count_distinct_from_index[i + 1];
            count_array[number[i]] ++; // not required
        }
    }   

    int done[100005] = {0};
    ll total_pairs = 0;

    rep(i, numbers - 1){
        if(!done[number[i]]){
            total_pairs += 1ll*count_distinct_from_index[i + 1];
            done[number[i]] = 1;
        }   
    }

    cout << total_pairs;
    return 0;
}