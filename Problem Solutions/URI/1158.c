#include <stdio.h>
int main()
{
    int N, X, Y, a, b, c;
    scanf("%d", &N);
    for(a=1; a<=N; a++)
    {
        scanf("%d %d", &X, &Y);
        if(X%2==1)
        {
            c=0;
            for(b=1; b<=Y; b++)
            {
                c+=X;
                X+=2;
            }
            printf("%d\n", c);
        }
        else
        {
            X++;
            c=0;
            for(b=1; b<=Y; b++)
            {
                c+=X;
                X+=2;
            }
            printf("%d\n", c);
        }
    }
    return 0;
}
