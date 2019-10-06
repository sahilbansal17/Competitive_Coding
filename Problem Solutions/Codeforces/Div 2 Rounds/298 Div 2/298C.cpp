#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MIN(a,b) (a<b)?a:b;
#define MAX(a,b) (a>b)?a:b;
 
int main()
{
    LL n,sum;
    cin>>n>>sum;
    LL tot=0;
    LL a[n]={0};
    for(LL i=0;i<n;i++)
    {
        cin>>a[i];
        tot+=a[i];
 
    }
    
    for(LL i=0;i<n;i++)
    {
        int minima=MAX(1,sum-tot+a[i]);
        int maxima=MIN(a[i],sum-n+1);
        cout<<(a[i]-1-maxima+minima)<<" ";
    }
    
    return 0;
}