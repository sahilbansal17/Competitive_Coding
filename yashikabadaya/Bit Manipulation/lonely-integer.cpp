#include <iostream>
#include <vector>

using namespace std;

// This program returns the non-repeating integer in the vector.
int lonelyinteger(vector<int> a) {
    int n = a[0];
    for(int i = 1; i < a.size(); i++){
        n = n ^ a[i];
    }
    return n;

}

// Time Complexity: O(n), Since we are iterating through the entire vector a.

// Space Complexity: O(1), Since we have used only one additional variable n in the function.

int main()
{
    int n, x;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> x;
        a.push_back(x);
    }

    int result = lonelyinteger(a);

    cout << result << "\n";
}

