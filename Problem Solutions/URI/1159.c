#include <stdio.h>

int main()
{
    int x, a, b = 0;
    while(1){
		
        scanf("%d", &x);
        
        b = 0 ;
        if(x == 0 )
            break;
            
        else if( x%2 == 0){
			
            for(a=x; a<=x+8; a+=2) b+=a;
        }
        else
        {
            for(a=x+1;a<=x+9;a+=2) b+=a;
        }
        printf("%d\n", b);
    }
    return 0;
}
