#include <stdio.h>

int main(){
	float a, b, c, media;
	scanf("%f%f%f", &a, &b, &c);
	media = ((a * 2) + (b * 3) + (c * 5))/10.0;
	printf("MEDIA = %.1f\n",(media));
	
	return 0;
	
}
