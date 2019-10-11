#include <stdio.h>
int main()
{
    int a,b,c,d,x,y;
    scanf("%d%d%d%d", &a, &x, &b, &y);
    if(a==y && b==y && y==x)
    {
        c=x-y;
        d=24+a-b;
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", d, c);
    }
    else if(a==b && y>x)
    {
        c=y-x;
        d=a-b;
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", d, c);
    }
    else if(a==b && x>y)
    {
        c=60-x+y;
        d=24-a+b-1;
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", d, c);
    }
    else if(x==y && a<b)
    {
        c=0;
        d=b-a;
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", d, c);
    }
    else if(x==y && a>b)
    {
        c=0;
        d=24-a+b;
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", d, c);
    }
    else if(b>a && y>x)
    {
        c=y-x;
        d=b-a;
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", d, c);
    }
    else if(a<b && x>y)
    {
        c=60-x+y;
        d=b-a-1;
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", d, c);
    }
    else if(a>b && x<y)
    {
        c=y-x;
        d=24-a-1+b;
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", d, c);
    }
    else if(a>b && x>y)
    {
        c=60+y-x;
        d=24+b-a-1;
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", d, c);
    }
    return 0;
}
