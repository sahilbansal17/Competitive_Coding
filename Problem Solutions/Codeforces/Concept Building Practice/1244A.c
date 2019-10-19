#include<stdio.h>

int main()
{
    int t,n,i,j,k,count,ans1,ans2,answer;
    //char s[1001];
    scanf("%d",&t);
    while(t--)
    {
        i=0;k=0;answer=0;
        scanf("%d",&n);
        j=n-1;count=0;
        char s[n];
        scanf("%s",s);
        while(k<n)
        {
            if(s[k]=='1')
            {
                answer=1;
                break;
            }
            k++;
        }
        while(s[i]!='1' && i<n)
            i++;
        while(s[j]!='1' && j>=0)
        {
            j--;
            count++;
        }

        //printf("i:%d count:%d",i,count);
        i++;count++;
        ans1=n-i+1;
        ans2=n-count+1;
        if(answer==0)
            printf("%d\n",n);
        else
        {
            if(ans2>ans1)
                printf("%d\n",2*ans2);
            else printf("%d\n",2*ans1);
        }
    }
    return 0;
}
