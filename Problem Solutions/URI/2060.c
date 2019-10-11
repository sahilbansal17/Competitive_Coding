#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
	 int n;
	 short j, l, multi2, multi3, multi4, multi5;
	 
	 multi2 = multi3 = multi4 = multi5 = 0;
	 
	 scanf("%d", &n);
	
	 for(j = 0; j < n; j++){
			 scanf("%hd", &l);
			 if(l % 2 == 0){
			     multi2++;
			     if(l % 4 == 0) multi4++;
			 }
			 if(l % 3 == 0) multi3++;
			 if(l % 5 == 0) multi5++;
	 }
	 printf("%hd Multiplo(s) de 2\n", multi2);
	 printf("%hd Multiplo(s) de 3\n", multi3);
	 printf("%hd Multiplo(s) de 4\n", multi4);
	 printf("%hd Multiplo(s) de 5\n", multi5);
		
	 return 0;
	
}
