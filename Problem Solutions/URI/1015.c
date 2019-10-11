#include <stdio.h>
#include <math.h>


int main(){
	
	float x1, x2, y1, y2, a, b, c, distancia;
	
	scanf("%f %f\n", &x1, &y1);
	scanf("%f %f", &x2, &y2);
	a = x2 - x1;
	b = y2 - y1;
	c = (a * a) + (b * b);
	distancia = sqrt(c);
	printf("%.4f\n",distancia);
}
