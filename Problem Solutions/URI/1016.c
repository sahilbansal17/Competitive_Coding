

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main()
{
	int distancia, tempoalcance;

	scanf("%i", &distancia);

	tempoalcance = (60 * distancia) / 30;

	printf("%i minutos\n", tempoalcance);

	return 0;
}



