#include <stdio.h>
int main(){
	
    int x, n, a, b=0;
    
    scanf("%d %d", &x, &n);
    
    while(n <= 0)
        scanf("%d", &n);
        
    for(a=1; a<=n; a++){
		
        b += x;
        x++;
    }
    printf("%d\n",b); 
    
    return 0;
}
