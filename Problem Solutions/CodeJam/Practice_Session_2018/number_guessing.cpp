#include <iostream>
using namespace std;

int main () {
    
    long long t, a, b, n; // test cases
    cin >> t;
    
    string output;
    
    long long start, end, mid;
    bool done, wrong;
    for (int i = 0; i < t; i ++) {
        cin >> a >> b;
        cin >> n;
        
        start = a + 1;
        end = b;
        
        done = false;
        wrong = false;
        while (!done) {
            mid = (start + end)/2;
            cout << mid << endl;
            fflush(stdout);
            cin >> output;
            if (output == "CORRECT") {
                done = true;
            }
            else if (output == "TOO_BIG") {
                // actual number is smaller
                end = mid - 1;
            }
            else if (output == "TOO_SMALL") {
                // actual number is larger
                start = mid + 1;
            }
            else if (output == "WRONG_ANSWER") {
                wrong = true;
            }
        }
        if (wrong == true) {
            break;
        }
    }
    return 0;
}
