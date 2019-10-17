#include<stdio.h>
int main(void) 
{
    long long int n,t,i,j,f,v,v1,v2,temp[1000000]={0},limit;
    scanf("%lld",&t);
    while(t--)
    { 
        scanf("%lld",&n);
        long long int a[n],kk;
        long long int a2[n],p=0;
        long long int temp[1000000]={0};
        for(i=0;i<n;i++)
        {
             scanf("%lld",&a[i]);
        }
        v=-1;
        for(i=0;i<n;i++)
        {
            a2[p]=temp[a[i]];
            p++;
            limit=sqrt(a[i]);
            for(j=1;j<=limit;j++)
            {
                v2=a[i]%j;
                if(v2==0)
                {
                    
                    v1=a[i]/j;
                    temp[j]=temp[j]+1;
                    
                    if(v1==j)
                    {
                        //do nothing;
                    }
                    else
                    {
                        temp[v1]=temp[v1]+1;
                    }
                        
                   
                    
                        
                }
               
            }
        }
        long long int max=a2[0];
        for(i=0;i<p;i++)
        {
            if(max<a2[i])
            {
                max=a2[i];
            }
        }
        printf("%lld\n",max);
        
    }}

