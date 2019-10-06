#include <bits/stdc++.h>
using namespace std;
#define MIN(a,b) (a<b)?a:b;
 
int main()
{
    int v1,v2,t,d,dis=0;
    cin>>v1>>v2>>t>>d;
    int max=v2+t*d;
    int min=v2-t*d;
    dis=v1+v2;
    int tnow=2;
    int vmax=v2+(t-2)*d;  //stores the minimum speed required at a particular second so that our speed eventually can be decelerated to v2
    int vbef=v1;
    while(tnow!=t)  //we want to maximize speed in each second for our goal
    {
        int vnow=MIN(vbef+d,vmax);//maximum possible speed each second
        dis+=vnow;
        vbef=vnow;
        vmax=vmax-d;
        tnow++;
    }
    cout<<dis<<endl;
    return 0;
}