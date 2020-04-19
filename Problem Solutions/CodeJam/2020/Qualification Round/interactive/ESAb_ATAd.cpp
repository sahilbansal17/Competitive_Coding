#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MOD = 1e9 + 7;

bool solve(int case_no, int bits) {
    vector<int> arr(bits, 0);
    for (int i = 0; i < 10; ++i) {
        cout << i + 1 << endl;
        cout.flush();
        cin >> arr[i];
    }

    int p0 = -1, p1 = -1;
    for (int i = 0; i < 5; ++i) {
        if ((arr[i] ^ arr[9 - i]) == 0) {
            p0 = i;
        } else {
            p1 = i;
        }
    }

    vector<int> arr2(bits, 0);
    bool c_rc = false; // complement or reverse complement
    bool r_s = false; // reverse or same
    bool r_c = false; // reverse or complement
    bool s_rc = false; // same or reverse complement

    if (p0 != -1) {
        cout << p0 + 1 << endl;
        cout.flush();
        cin >> arr2[p0];

        if (arr[p0] != arr2[p0]) {
            c_rc = true;
        } else {
            r_s = true;
        }
    }
    if (p1 != -1) {
        cout << p1 + 1 << endl;
        cout.flush();
        cin >> arr2[p1];

        if (arr2[p1] != arr[p1]) {
            r_c = true;
        } else {
            s_rc = true;
        }
    }


    if (r_s && r_c) {
        // reverse
        reverse(arr.begin(), arr.end());
        for (int i = 0; i < 10; ++i) {
            cout << arr[i];
        }
    } else if (c_rc && r_c) {
        // complement
        for (int i = 0; i < 10; ++i) {
            cout << (1 ^ arr[i]);
        }
    } else if (r_s && s_rc) {
        // same
        for (int i = 0; i < 10; ++i) {
            cout << arr[i];
        }
    } else if (c_rc && s_rc) {
        // reverse complement
        reverse(arr.begin(), arr.end());
        for (int i = 0; i < 10; ++i) {
            cout << (1 ^ arr[i]);
        }
    } else if (r_s || r_c) {
        // reverse
        reverse(arr.begin(), arr.end());
        for (int i = 0; i < 10; ++i) {
            cout << arr[i];
        }
    } else {
        // c_rc || s_rc
        // reverse complement
        reverse(arr.begin(), arr.end());
        for (int i = 0; i < 10; ++i) {
            cout << (1 ^ arr[i]);
        }
    }
    cout << endl;
    cout.flush();

    char res;
    cin >> res;
    if (res == 'N') {
        return 0;
    }
    return 1;
}

int main() {
    FAST_IO;

    int t, b;
    cin >> t >> b;

    for (int id = 1; id <= t; ++id) {
        bool next = solve(id, b);
        if (!next) {
            return 0;
        }
    }
    
    return 0;
}