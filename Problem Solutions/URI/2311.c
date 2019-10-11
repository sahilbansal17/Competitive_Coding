#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Competidor{
	char nome[100];
	float nota;
	float grauDif;
};

int main(){
	short numCompet, i;
	struct Competidor compet;
	double somaNotas;
	float maior, menor;
		
	scanf("%hd", &numCompet);

    while(numCompet--){
		scanf("%s %f", compet.nome, &compet.grauDif);
		
		for(i = 7, somaNotas = maior = 0., menor = 11.; i ;i--){
			scanf("%f", &compet.nota);
			if(compet.nota > maior) maior = compet.nota;
			if(compet.nota < menor) menor = compet.nota;
			somaNotas += compet.nota;
		}
		
		somaNotas -= maior + menor;
		
		printf("%s %.2lf\n", compet.nome, somaNotas*compet.grauDif);
	}
     	
	return 0;
}
