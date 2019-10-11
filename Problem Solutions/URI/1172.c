#include <stdio.h>

int main(){
	int n[10], i, x;
	
	for(i = 0; i < 10; i++){
		scanf("%d", &x);
		if(x > 0){
			n[i] = x;
		}else{
			n[i] = 1;
		}
		
	}
	for(i = 0; i < 10; i++)
        printf("X[%d] = %d\n",i,n[i]);
   
   
    return 0;
			
}
