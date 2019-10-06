#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MAX(a, b) (a > b) ? a : b;
#define MIN(a, b) (a < b) ? a : b;
#define IsInteger(a) (fabs(a-round(a))<0.00001)
#define swap(a, b) \
    {              \
        a = a + b; \
        b = a - b; \
        a = a - b; \
    }

int main()
{
    int h,w;
    cin>>h>>w;
    int row[h+1]={0};
    int col[w+1]={0};
    int a[h*w+1]={-1};

    for(int i=1;i<=h*w;i++)
    {
        a[i]=-1;
    }

    

    for(int i=1;i<=h;i++)
    {
        cin>>row[i];
    }

   

    for(int i=1;i<=w;i++)
    {
        cin>>col[i];
    }

    

    int i,y,initial;

    for(i=1;i<=h;i++)
    {
        initial=(i-1)*w;
        int limit=MIN(row[i],w);
        for(y=1;y<=limit;y++)
        {
            a[initial+y]=1;
        }

        if(row[i]+1<=w)
        {
            
            a[initial+row[i]+1]=0;
        }
    }

   

    for(i=1;i<=w;i++)
    {
        
        int limit=MIN(col[i],h);
        for(y=1;y<=limit;y++)
        {
           initial=(y-1)*w;
           if(a[initial+i]!=0)
           {
               a[initial+i]=1;
           }
           else
           {
               cout<<0<<endl;
               return 0;
           }
           

        }

        if(col[i]+1<=h)
        {
            if(a[col[i]*w+i]!=1)
            {
                a[col[i]*w+i]=0;
            }
            else
            {
                cout<<0<<endl;
                return 0;
            }
            
        }
    }

    int counter=0;
     //cout<<"ENTERED HERE BEFORE COUNTER"<<endl;

    for(i=1;i<=h*w;i++)
    {
        if(a[i]==-1)
        {
            //cout<<"INCREASING COUNT IS "<<i<<endl;
            counter++;
        }
    }

   // cout<<"COUNTER IS "<<counter<<endl;

    LL p=2,m=1000000007;
    LL t=counter,ans=1;
            while(t)
            {
                if(t%2)
                {
                    ans=ans*(p%m);
                    ans=ans%m;
                }

                p=(p*p)%m;
                t/=2;
            }

            ans=ans%m;
        cout<<ans<<endl;


    return 0;
}