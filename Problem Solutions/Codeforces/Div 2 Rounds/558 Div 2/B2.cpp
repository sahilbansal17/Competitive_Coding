#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef long long ll;

const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

template <typename T> T gcd(T a, T b) { 
    if(b == 0) 
        return a; 
    return gcd(b, a % b); 
}

template <typename T> T power(T x, T y, ll m = MOD) {
    T ans = 1; 
    x %= m; 
    while (y > 0) { 
        if (y & 1LL) {
            ans = (ans * x) % m;   
        } 
        y >>= 1LL; 
        x = (x * x) % m; 
    } 
    return (ans % m); 
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    #endif

    FAST_IO;    

    int n, val;
    cin >> n;

    unordered_map <int, int> cnt; // frequency
    unordered_map <int, int> num; // num of elements with given frequency

    int max_streak = 1;
    int max_freq = -1; // highest frequency
    for (int i = 0; i < n; i ++) {
        cin >> val;
        
        // updating the hash maps
        ++cnt[val]; // increase the frequence of current element
        int f = cnt[val]; // save frequency to f
        --num[f - 1]; // decrease the no of elements with f-1 count
        ++num[f]; // increase the no of elements with f count

        if (f > max_freq) {
            max_freq = f;
        }

        bool current_day_streak_possible = false;
        if (num[1] == i + 1) { // every color has single occurrence
            // remove a color from any of the i-days
            current_day_streak_possible = true;
        }
        else if (num[i + 1] == 1) { // only one color occurred till now
            // remove a color from any of the i-days
            current_day_streak_possible = true;
        }
        else if (num[1] == 1 && num[max_freq] * max_freq == i) { // one color has occurred once, rest all have the same frequency
            // remove the color with frequency = 1
            current_day_streak_possible = true;
        }
        else if (num[max_freq - 1] * (max_freq - 1) == (i+1 - max_freq) && num[max_freq] == 1) { // one color has frequency 1 more than frequency of all others
            // remove one occurrence of the color with frequency = max_freq
            // to make all having the same frequency = max_freq - 1
            current_day_streak_possible = true;
        }

        // update the largest streak
        if (current_day_streak_possible == true) {
            max_streak = i + 1;
        }
    }
    
    cout << max_streak << endl;
    return 0;
}