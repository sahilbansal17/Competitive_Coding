#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the dynamicLineIntersection function below.
 */
void dynamicLineIntersection(int n) {
    /*
     * Write your code here.
     */
    
    char q;
    int k, b, y;
    
    vector < pair <int, int> > lines;
    for(int q_count = 0 ; q_count < n ; q_count ++){
        cin >> q;
        if(q == '+'){
            cin >> k >> b;
            lines.push_back(make_pair(k, b));
        }
        else if(q == '-'){
            cin >> k >> b;
            for(int i = 0 ; i < lines.size(); i ++){
                pair <int, int> l = lines[i];
                if(l.first == k && l.second == b){
                    lines.erase(lines.begin() + i);
                }
            }
        }
        else if(q == '?'){
            cin >> y;
            int count = 0;
            for(int i = 0 ; i < lines.size(); i ++){
                if((y - lines[i].second) % lines[i].first == 0){
                    count ++;
                }
            }
            cout << count << "\n";
        }   
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    dynamicLineIntersection(n);

    return 0;
}