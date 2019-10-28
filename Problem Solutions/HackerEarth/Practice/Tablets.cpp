#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,j,k=0;
    cin>>n;
    int a[n],b[n]={1};
    // cout<<"HI"<<endl;
    for(i=0;i<n;i++)
        b[i]=1;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<n;i++)
    {
        if(a[i]>a[i-1])
            b[i]=b[i]+b[i-1];
    }
    // cout<<"HI"<<endl;
    // for(i=0;i<n;i++)
    //     cout<<b[i]<<endl;
    for(i=n-2;i>=0;i--)
    {
        if(a[i]>a[i+1] && b[i]<=b[i+1])
            b[i]=b[i+1]+1;
    }
    // cout<<"HI"<<endl;
    // for(i=0;i<n;i++)
    //     cout<<b[i]<<endl;
    for(i=0;i<n;i++)
        k+=b[i];
    
    // cout<<"HI"<<endl;
    // for(i=0;i<n;i++)
    //     cout<<b[i]<<endl;    
    cout<<k;    
}
