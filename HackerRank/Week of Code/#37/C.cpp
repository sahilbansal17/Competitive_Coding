#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maximumSuperiorCharacters function below.
long maximumSuperiorCharacters(vector<int> freq) {
    
    long sum_freq = 0;
    for(int alpha = 0; alpha < 26 ; alpha ++){
        sum_freq += freq[alpha];
    }
    
    for(int alpha = 0; alpha < 26; alpha ++){
        if(freq[alpha] > sum_freq - freq[alpha])
        freq[alpha] = sum_freq - freq[alpha];
    }
    
    sum_freq = 0;
    for(int alpha = 0; alpha < 26 ; alpha ++){
        // cout << freq[alpha] << " ";
        sum_freq += freq[alpha];
    }
    
    return ceil(1.0 * (sum_freq - 2)/2);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string freq_temp_temp;
        getline(cin, freq_temp_temp);

        vector<string> freq_temp = split_string(freq_temp_temp);

        vector<int> freq(26);

        for (int freq_itr = 0; freq_itr < 26; freq_itr++) {
            int freq_item = stoi(freq_temp[freq_itr]);

            freq[freq_itr] = freq_item;
        }

        long result = maximumSuperiorCharacters(freq);

        fout << result << "\n";
    }

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