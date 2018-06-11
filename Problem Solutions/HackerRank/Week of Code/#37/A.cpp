#include <bits/stdc++.h>

using namespace std;

// Complete the averageOfTopEmployees function below.
void averageOfTopEmployees(vector<int> rating) {
    
    int sumRatingOfTopEmployees = 0, numOfTopEmployees = 0;
    for(int rating_itr = 0 ; rating_itr < rating.size(); rating_itr ++){
        if(rating[rating_itr] >= 90){
            sumRatingOfTopEmployees += rating[rating_itr];
            numOfTopEmployees ++;
        }
    }
    double avg = 1.0 * sumRatingOfTopEmployees / numOfTopEmployees;
    avg = floor(100*avg + 0.5)/100;
    cout << fixed;
    cout << setprecision(2) << avg;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> rating(n);

    for (int rating_itr = 0; rating_itr < n; rating_itr++) {
        int rating_item;
        cin >> rating_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        rating[rating_itr] = rating_item;
    }

    averageOfTopEmployees(rating);

    return 0;
}