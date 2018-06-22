#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int x,y;
    cin>>x;
    cin>>y;
    if(pow(x,y)>pow(y,x))
        cout<< ">"<<endl ;
    else if(pow(x,y)<pow(y,x))
        cout<< "<"<<endl ;
    else
        cout<< "="<<endl ;

    return 0;

}
