#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T--) {
        int N, m;
        bool flag = true;
        int count = 0;
        cin >> N;
        vector<int> arr(N+5); // To store initial 5 maximums we add 5 extra spaces
        for(int i = 0;i < 5;i++) arr[i] = INT_MAX; // Set initial 5 values to INT_MAX for comparision
        for(int i = 5;i < N+5;i++) cin >> arr[i]; // Taking input
        // Loop will run from first element to last
        // Each iteration we will compare last 5 values
        // Thus, complexity will be O(n)
        for(int i = 5;i < N+5;i++) {
            m = arr[i];
            flag = true;
            // Comparing previous five values for getting local maxima
            for(int j = 1;j <= 5;j++)
                if(arr[i-j] <= m) flag = false;
            if(flag) count++;
        }
        cout << count << endl;
    }
    return 0;
}
