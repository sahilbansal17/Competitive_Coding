#include<bits/stdc++.h>
using namespace std;
int main() 
{
     int t;
     cin>>t;
     while(t--)
     {
        int n,x;
        cin>>n;
        map<int,int>a;
        vector<int>arr;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            a[x]++;
            if(a[x]==1)
                arr.push_back(x);
        }
        sort(arr.begin(),arr.end());
        int val=a.size();
        int res=n/4;
        int check=0;
        int cnt=0;
        int z[4]={0};
        for(int i=0;i<arr.size();i++)
        {
            check+=a[arr[i]];
            if(check==res)
            {
                check=0;
                z[cnt]=i;
                cnt++;
            }
            if(check>res)
            {
                cout<<"-1";
                break;
            }
        }
        if(cnt==4)
        {
            for(int i=0;i<cnt-1;i++)
            {
                cout<<arr[z[i]+1]<<" ";
            }
        }
        cout<<endl;
     }
     return 0;
}
