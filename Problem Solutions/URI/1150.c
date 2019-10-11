#include <stdio.h>

int main(){
    int a,b,c=0,x,z;
 
    scanf("%d", &x);
 
    do{
        scanf("%d", &z);
    }
    while(x >= z);
    
    for(a=x,b=0; b<z; a++){	
        b += a;
        c++;
    }
    
    printf("%d\n", c);
    return 0;
}
