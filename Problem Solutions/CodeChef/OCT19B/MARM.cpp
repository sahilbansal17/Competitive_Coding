#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define deb(x) cout<<#x<<" "<<x<<endl
int main()
{
    fastIO;
    ll t;
    cin>>t;
    while(t--)
    {
    ll n,k;
    cin>>n>>k;
    ll a[n],b[n],c[n];
    for(ll i=0;i<n;i++)
        {cin>>a[i];
         b[i]=a[i];
        }
    for(ll i=0;i<n;i++)
      {
        ll y=n-i-1;
        ll z=b[i]^b[y];
        b[i]=z;
        c[i]=a[i]^b[i];
      }
    /*for(ll i=0;i<n;i++)
    {
        c[i]=a[i]^b[i];
    }*/
    /*deb("b");
    for(auto it:b)
        cout<<it<<" ";
    deb(c);
    for(auto it:c)
        cout<<it<<" ";*/
    ll x=k/n;
    ll y=k%n;
    ll m=x%3;
    ll p=0;
    if(n==1)
    {
        cout<<"0";
    }
   else if(n%2==0)
    {
      if(m==0)
    {
       while(y--)
       {
           a[p]=a[p]^a[n-p-1];
           p++;
       }
       for(auto it:a)
       cout<<it<<" ";
    }
    else if(m==1)
    {
        while(y--)
       {
           b[p]=b[p]^b[n-p-1];
           p++;
       }
      for(auto it:b)
      cout<<it<<" ";
    }
    else
    {
        while(y--)
       {
           c[p]=c[p]^c[n-p-1];
           p++;
       }
        for(auto it:c)
        cout<<it<<" ";
    }
    }
    else
    {
        b[n/2]=0;
        c[n/2]=0;
        if(k<=n/2)
        {
            while(y--)
        {
           a[p]=a[p]^a[n-p-1];
           p++;
        }
         for(auto it:a)
         cout<<it<<" ";
        }
        else
        {
            a[n/2]=0;
            if(m==0)
    {
       while(y--)
       {
           a[p]=a[p]^a[n-p-1];
           p++;
       }
       for(auto it:a)
       cout<<it<<" ";
    }
    else if(m==1)
    {
        while(y--)
       {
           b[p]=b[p]^b[n-p-1];
           p++;
       }
      for(auto it:b)
      cout<<it<<" ";
    }
    else
    {
        while(y--)
       {
           c[p]=c[p]^c[n-p-1];
           p++;
       }
        for(auto it:c)
        cout<<it<<" ";
    }
        }
    }
     cout<<endl;
    }
    return 0;
}
