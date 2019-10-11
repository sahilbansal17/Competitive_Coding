#include <stdio.h>
#include <math.h>

int main(){
	float a, b, c;
	
	scanf("%f %f %f", &a, &b, &c);
	
	if(fabs(a - b) < c && fabs(a - b) < (a + b)){
		if(fabs(c - a) < b && fabs(c - a) < (a + c)){
			if(fabs(b - c) < a && fabs(b - c) < (b + c)){
				printf("Perimetro = %.1f\n", (a + b + c));
				
			}
			
			
		}
	
	}else {
		printf("Area = %.1f\n", ((a + b) * c)/2 );
	}
	
	
	
	return 0;
}
