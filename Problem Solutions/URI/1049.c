#include <stdio.h>
#include <string.h>
int main()
{
    char c1[]="vertebrado", c11[22]="ave", c12[]="mamifero";
    char c111[]="carnivoro", c112[]="onivoro", c124[]="herbivoro";
    char a1[]="aguia", a2[]="pomba", a3[]="homem", a4[]="vaca";
    char c2[]="invertebrado", c21[]="inseto", c22[]="anelideo";
    char c211[]="hematofago", a5[]="pulga", a6[]="lagarta";
    char a7[]="sanguessuga", a8[]="minhoca";
    char a[22], b[22], c[22];
    scanf("%s", a);
    if(0==strcmp(a,c1))
    {
        scanf("%s",b);
        if(0==strcmp(b,c11))
        {
            scanf("%s",c);
            if(0==strcmp(c,c111))
                printf("%s\n",a1);
            else if(0==strcmp(c,c112))
                printf("%s\n",a2);
        }
        if(0==strcmp(b,c12))
        {
            scanf("%s",&c);
            if(0==strcmp(c,c112))
                printf("%s\n",a3);
            else if(0==strcmp(c,c124))
                printf("%s\n",a4);
        }
    }
    else if(0==strcmp(a,c2))
    {
        scanf("%s",b);
        if(0==strcmp(b,c21))
        {
            scanf("%s",&c);
            if(0==strcmp(c,c211))
                printf("%s\n",a5);
            else if(0==strcmp(c,c124))
                printf("%s\n",a6);
        }
        if(0==strcmp(b,c22))
        {
            scanf("%s",&c);
            if(0==strcmp(c,c211))
                printf("%s\n",a7);
            else if(0==strcmp(c,c112))
                printf("%s\n",a8);
        }
    }
    return 0;
}
