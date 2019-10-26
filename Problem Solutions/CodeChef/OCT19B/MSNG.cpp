
#include <bits/stdc++.h>
using namespace std;

int minb(string s)
{
    int min=2;
    int l=s.length();

    for(int i=0;i<l;i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
        {
            if((s[i]-'A'+10)>=min)
                min = (s[i]-'A'+11);
        }
        else
        {
            if((s[i]-'0')>=min)
                min=(s[i]-'0'+1);
        }

        if(min==36)
             break;
    }
    return min;
}

long long convert(int b,string s)
{
    int l=s.length();
    long long sum=0;
    long long val=1;

    for(int i=l-1;i>=0;i--)
    {
        if(s[i]>='A'&&s[i]<='Z')
            sum+=val*(s[i]-'A'+10);
        else
            sum+=val*(s[i]-'0');

        if(sum>1000000000000)
        {
            sum=-1;
            break;
        }
        if(val<=1000000000000)
            val=val*b;
    }
    return sum;
}

int main()
{
    int T;
    cin>>T;
    int n;
    int p;
    string s;
    int cy;
    long long a[4000];

    while(T--)
    {
        cy=0;
        cin>>n;
        int check=1;
        for(int j=0;j<n;j++)
        {
            cin>>p;
            cin>>s;
            if(p!=-1)
            {
                a[cy++]=convert(p,s);
                if(a[cy-1]==-1)
                    check=0;
            }
            else
            {
                int mb=minb(s);
                for(int k=mb;k<=36;k++)
                {
                    a[cy++]=convert(k,s);
                    if(a[cy-1]==-1)
                    {
                        cy--;
                        break;
                    }
                    if(k>mb&&a[cy-1]==a[cy-2])
                    {
                        cy--;
                        break;
                    }
                }
            }
        }
        if(check==0)
        {
            cout<<"-1"<<endl;
            continue;
        }
        else
        {
            if(cy>0)
                sort(a,a+cy);
            int c=1;
            int j;
            for(j=1;j<cy;j++)
            {
                if(c==n)
                    break;
                if(a[j]==a[j-1])
                    c++;
                else
                    c=1;
            }
            if(c==n)
                cout<<a[j-1]<<endl;
            else
                cout<<"-1"<<endl;
        }
    }
    return 0;
}