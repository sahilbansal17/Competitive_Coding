#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the maximumProgramValue function below.
 */
long maximumProgramValue(int n) {
    /*
     * Write your code here.
     */
    string op;
    int val, line_num = 1;
    long x = 0;
    while(line_num <= n){
        cin >> op >> val;
        if(op == "add" && val > 0){
            x += val;
        }
        else if(val > x){
            x = val;
        }
        line_num ++;
    }
    return x;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = maximumProgramValue(n);

    fout << result << "\n";

    fout.close();

    return 0;
}