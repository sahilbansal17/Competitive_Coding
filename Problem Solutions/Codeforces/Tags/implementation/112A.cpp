#include<bits/stdc++.h>
using namespace std;
int main()
{
    string one, two;
    cin>>one>>two;
    transform(one.begin(), one.end(), one.begin(), ::tolower);
    transform(two.begin(), two.end(), two.begin(), ::tolower);
    cout<<one.compare(two);
    return 0;
}
