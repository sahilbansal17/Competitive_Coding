#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long int n;
    scanf("%llu",&n);
    while(n)
    {
        unsigned long long int k=0;
        while(n%2==0)
            n/=2,k++;
        if(k>0)
        	printf("2^%llu ",k);
        for(unsigned long long int i=3;i*i<=n && n!=1;i+=2)
        {
            k=0;
                while(n%i==0)
                    n/=i,k++;
        	if(k>0)
        		printf("%llu^%llu ",i,k);
        }
        if(n!=1)
            printf("%llu^1 ",n);
        printf("\n");
        scanf("%llu",&n);
    }
}
