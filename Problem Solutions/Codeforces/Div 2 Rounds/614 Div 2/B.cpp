#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int n;
    cin >> n;

    int cp = n;

    /*/ O(N^2) solution to find the OPTIMAL APPROACH
    float res = 1.0;
    while (n != 1) {
        res += floor((1.0*n)/2)/(1.0*n);
        n -= floor((1.0*n)/2);
    }

    vector<double> sol(cp + 1, 0.0);
    sol[0] = 0.0;
    sol[1] = 1.0;
    sol[2] = 1.5;

    vector<int> par(n + 1, 0);
    for (int i = 3; i <= cp; ++i) {
        double maxi = 0.0;
        int idx = -1;
        for (int j = 1; j <= i; ++j) {
            if ( ((1.0*j)/i + sol[i - j]) > maxi) {
                maxi = (1.0*j)/i + sol[i - j];
                idx = j;
            }
        }
        par[i] = idx;
        sol[i] = maxi;
    }

    for (int i = 1; i <= cp; ++i) {
        cout << par[i] << " ";
    }
    cout << endl;
    int idx = cp;
    while (idx > 2) {
        cout << idx << " ";
        idx = par[idx];
    }
    cout << endl;
    cout << fixed;
    cout << setprecision(15) << res << endl;

    cout << sol[cp] << endl;   
    //*/
    
    double res2 = 1.0;
    while (cp != 1) {
        res2 += (1.0)/cp;
        --cp;
    } 
    cout << fixed;
    cout << setprecision(15) << res2 << endl;
    return 0;
}