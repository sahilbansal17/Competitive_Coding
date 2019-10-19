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
        vector<int> arr(N+5);
        for(int i = 0;i < 5;i++) arr[i] = INT_MAX;
        for(int i = 5;i < N+5;i++) cin >> arr[i];

        for(int i = 5;i < N+5;i++) {
            m = arr[i];
            flag = true;
            for(int j = 1;j <= 5;j++)
                if(arr[i-j] <= m) flag = false;
            if(flag) count++;
        }
        cout << count << endl;
    }
    return 0;
}
