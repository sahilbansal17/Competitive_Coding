#include <stdio.h>

int main(){
	double x, y, media;
	
	scanf("%lf %lf", &x, &y);
	media = (((y - x) * 100.00)/x);
	
	printf("%.2lf%%\n", media);
	
	return 0;
	
}
