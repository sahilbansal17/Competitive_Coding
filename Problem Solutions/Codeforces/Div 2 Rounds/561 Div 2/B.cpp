#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

vector <int> factorize(int n) {
    vector <int> res;
    for (int i = 2; i <= sqrt(n); i ++) {
        if (n % i == 0) {
            res.push_back(i);
            res.push_back(n/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main(){

    FAST_IO;    

    int n;
    cin >> n;

    vector <int> facs = factorize(n);
    
    int rows = 0, cols = 0;
    int i = 0, j = facs.size() - 1;

    while (i < j) {
        if (facs[i] >= 5 && facs[j] >= 5) {
            rows = facs[i];
            cols = facs[j];
            break;
        }
        i ++;
        j --;
    }

    if (rows == 0 && cols == 0) {
        cout << "-1" << endl;
    }
    else {
        // cerr << rows << " " << cols << endl;
        char vowels[6] = "aeiou";
        int k = 0;
        for (int i = 0; i < rows; i ++) {
            int vid = k;
            for (int j = 0; j < cols; j ++) {
                cout << vowels[vid];
                vid ++;
                vid %= 5;
            }
            // cout << endl;
            k ++;
            k %= 5;
        }
    }
    return 0;
}