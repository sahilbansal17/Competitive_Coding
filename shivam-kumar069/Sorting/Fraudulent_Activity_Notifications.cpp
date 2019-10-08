// A C++ solution to the problem: https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem
// Complexity: O((n-d)*log(d))

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

//########################## The important part ###########################################
// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    if(d>=expenditure.size()){
        return 0;
    }
    int ct = 0;

    multiset<int> ms;
    for(int i=0; i<d; i++){
        ms.insert(expenditure[i]);
    }

    int tmp;
    multiset<int> :: iterator itr = ms.begin(), itr2 = ms.begin(), itr3 = ms.begin(), itr4;

    if(d%2==0){
        advance(itr2, d/2 - 1);
        advance(itr3, d/2);
    }
    else{
        advance(itr2, d/2);
    }


    for(int i=d; i<expenditure.size(); i++){
        tmp = expenditure[i];
        itr4 = ms.find(expenditure[i-d]);

        
        if(d%2!=0){
            if(expenditure[i] >= 2 * (*itr2)){
                ct++;
            }
            ms.insert(tmp);
            if(tmp<*itr2){
                if(*itr4 > *itr2 || itr4==itr2){
                    itr2--;
                }
            }
            else{
                if(*itr4 <= *itr2){
                    itr2++;
                }
            }
            ms.erase(itr4);
        }
        else{
            if(expenditure[i] >= 2 * ((*itr2 + *itr3)/2.0)){
                ct++;
            }
            ms.insert(tmp);
            if(tmp < *itr2){
                if(itr4 == itr3 || *itr4 > *itr3){                    
                    itr2--;
                    itr3--;
                }
                else if(itr4 == itr2){
                    itr2--;
                }
            }
            else if(tmp >= *itr3){
                if(*itr4 <= *itr2){
                    itr2++;
                    itr3++;
                }
                else if(itr4 == itr3){
                    itr3++;
                }
            }
            else if(tmp >= *itr2 && tmp < *itr3){
                if(*itr4 <= *itr2){
                    itr2++;
                }
                else{
                    itr3--;
                }
            }
            ms.erase(itr4);
        }
    }

    return ct;
}
//#########################################################################################

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

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
