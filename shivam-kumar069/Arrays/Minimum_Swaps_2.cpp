// A C++ solution for the problem: https://www.hackerrank.com/challenges/minimum-swaps-2/problem
// Complexity: O(n)

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

//################## The important part ###################################
// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    int ct = 0;
    vector<int> visited;

    for(int i=0; i<arr.size(); i++){
        visited.push_back(0);
    }

    for(int i=0; i<arr.size(); i++){
        if(!visited[i]){
            int num = i;
            do{
                ct++;
                visited[num] = 1;
                num = arr[num]-1;
            } while(!visited[num]);
            ct--;
        }
    }

    return ct;
}
//#########################################################################

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    fout << res << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
