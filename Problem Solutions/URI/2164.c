#include <stdio.h>
#include <math.h>
int main(){
	double n, x, y, fibb;
	
	scanf("%lf", &n);
	x = (1 + sqrt(5))/ 2.0;
	y = (1 - sqrt(5))/ 2.0;
	fibb = (pow(x, n) - pow(y, n))/ sqrt(5) ;
	printf("%.1lf\n", fibb);
	
	return 0;
}
