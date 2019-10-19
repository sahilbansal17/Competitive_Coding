#include <stdio.h>

int main()
{
    //pens is the number of pens required
    //p is the number of pencils required
    int t,a,b,c,d,k,pens,p;
    //t is the number of test cases.
    scanf("%d",&t);
    while(t--)
    {
        //scanning a,b,c,d,k
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        //if a is exactly divisble by c then we would need only c number of pens
        //else we would need 1 more than a/c pens
        if(a%c==0)
            pens=a/c;
        else
            pens=a/c+1;
        //similarly we can find the minimum number of pencils required 
        if(b%d==0)
            p=b/d;
        else
            p=b/d+1;
        //checking if number of pens and pencils are less than or equal to
        //the number of writing implements that can fit into Polycarp's pencilcase
        if(p+pens<=k)
            printf("%d %d",pens,p);
        else
            printf("-1");
        printf("\n");
    }
    return 0;
}
