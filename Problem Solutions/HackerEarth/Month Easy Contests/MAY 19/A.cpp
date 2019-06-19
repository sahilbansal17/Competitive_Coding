#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    int n;
    for (int i = 0; i < t; i ++) {
        cin >> n;
        
        cout << (n - 2)/4 + 1 << endl;
    }
    return 0;
}
