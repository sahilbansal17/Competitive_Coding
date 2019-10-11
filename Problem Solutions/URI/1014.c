#include <stdio.h>


int main(){
	int distancia;
	float combustivel, kml;
	
	scanf("%d %f", &distancia, &combustivel);
	kml = distancia / combustivel;
	
	printf("%.3f km/l\n", kml);
	
	return 0;
}
