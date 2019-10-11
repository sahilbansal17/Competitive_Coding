#include <stdio.h>
int main()
{
    int array[4],i,c,e,f, g;
    
    for(i=0; i < 4; i++)
        scanf("%d", & array[i]);
        
        
    for( i= 0;i < 4;i++){
		
        for(c = i + 1 ; c < 4; c++){
			
            if(array[c] < array[i]){
                e=array[i];
                array[i]=array[c];
                array[c]=e;
            }
        }
    }
    g = array[1] + array[2];
    f = array[0] + array[1];
    if( array[3] < g || array[2] < f) printf("S\n");
    else printf("N\n");
    
    return 0;
}

