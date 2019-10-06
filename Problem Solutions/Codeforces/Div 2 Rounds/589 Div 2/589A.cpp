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
    int l,r;
    cin>>l>>r;
    for(int i=l;i<=r;i++)
    {
        int k=i;
        int b=1;
        int a[10]={0};
        while(k>0)
        {
            a[k%10]++;
            k/=10;
        }
        for(int j=0;j<10;j++)
        {
            if(a[j]>1)
            {
                b=0;
                break;
            }
        }
        if(b==1)
        {
            cout<<i;
            return 0;
        }


    }
    cout<<-1;


    return 0;
}
