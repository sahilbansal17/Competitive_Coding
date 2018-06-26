#include <bits/stdc++.h>
using namespace std;
int main()
{   int x,y;
    cin>>x>>y;
    //Greater than 9*(10^-9) is used due to the condition on input x,y.
    if (log10(x)*y-log10(y)*x>(9*1e-9))
        cout<<">";
    else if (-log10(x)*y+log10(y)*x>(9*1e-9))
        cout<<"<";
    else
        cout<<"=";
    return 0;
}
//Used log10 because input is less than or equal to 1 for x,
//But log1=0 hence to make the code work it is used.
