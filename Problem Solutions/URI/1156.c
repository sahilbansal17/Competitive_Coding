#include <stdio.h>

int main(){
	
    double a , b = 1,c, S = 0;
    
    for(a = 1; a <= 39; a += 2){
		
        c = a/b;
        S += c;
        b *=2;
    }
    
    printf("%.2lf\n",S);
    return 0;
}
