#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int cur = 0;
    bool valley = false;
    int ans = 0;
    for(auto c:s){
        if(c=='D') cur--;
        if(c=='U') cur++;
        if(cur >= 0 and valley){
            ans ++;
            valley = false;
        }
        if(cur < 0){
            valley = true;
        }
    }
    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
