// works for small test case

#include <iostream>
using namespace std;

int main () {

    int t;
    cin >> t;
    
    int a, x, y;
    bool done[1010][1010];
    for (int i = 0; i < t; i ++) {
        cin >> a;
        
        bool done = false, wrong = false;
        while (!done) {
            for (int k = 4; k < 8; k ++) {
                for (int l = 4; l < 8; l ++) {
                    cout << k << " " << l << endl;
                    fflush(stdout);
                    cin >> x >> y;
                    if (x == 0 && y == 0) {
                        done = true;
                        break;
                    }
                    if (x == -1 && y == -1) {
                        wrong = true;   
                    }
                }
                if (done == true) {
                    break;
                }
                if (wrong == true) {
                    break;
                }
            }
            if (done == true) {
                break;
            }
            if (wrong == true) {
                break;
            }
        }
        if (done == true) {
            continue;
        }
        if (wrong == true) {
            break;
        }
    }

    return 0;
}