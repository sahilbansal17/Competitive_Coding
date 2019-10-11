#include <stdio.h>

int main(){
	
    int n, x, a;
    scanf ("%d", &n);
    
    for(a = 1;a <= n; a++) {
        scanf ("%d",&x);
        if(x == 0)
            printf("NULL\n");
        else if(x <= 0 && x % 2==0)
            printf ("EVEN NEGATIVE\n");
        else if(x <= 0&& x %2 == -1)
            printf ("ODD NEGATIVE\n");
        else if(x >= 0 && x % 2 == 0)
            printf ("EVEN POSITIVE\n");
        else if(x >= 0 && x % 2 == 1)
            printf ("ODD POSITIVE\n");
    }
    
    return 0;
}
