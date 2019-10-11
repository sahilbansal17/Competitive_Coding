#include <stdio.h>

int main(){
	double n, x = 0.0;
	scanf("%lf", &n);
	
	while(n--){
		x += 6.0;
		x = 1.0 / x;
	}
	x += 3.0;
	printf("%.10lf\n", x);
	
	return 0;
	
}
