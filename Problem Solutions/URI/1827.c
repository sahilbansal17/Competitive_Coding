#include <stdio.h>

int main(){
	
    int z;
    while(scanf("%d",&z)!=EOF)
    {
        int ara[z][z];
        int a,aa,b,c,d,e,f,g,x,y;
        for(a=0; a<z; a++)
        {
            for(b=0; b<z; b++)
                ara[a][b]=0;
        }
        for(a=0; a<z; a++)
            ara[a][a]=2;
        d=z-1;
        for(a=0,b=d; a<z;a++,b--)
            ara[a][b]=3;
        c=z/3;
        e=z-c-c;
        for(f=c,x=1; x<=e; f++,x++)
        {
            for(g=c,y=1; y<=e; g++,y++)
                ara[f][g]=1;
        }
        if(z%2==1)
            aa=z/2;
        else
            aa=(z/2)-1;
        ara[aa][aa]=4;
        for(a=0; a<z; a++)
        {
            for(b=0; b<z; b++)
                printf("%d",ara[a][b]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}

