#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    int cnt = count(s.begin(),s.end(),'a');
    int ns = s.size();
    long num = n/ns;
    int len = n%ns;
    int rem = count(s.begin(),s.begin()+len,'a');
    // cout << ns << "," << num << "," << len << "," << rem << endl;
    return num*cnt + rem;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
