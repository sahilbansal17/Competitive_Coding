#include <stdio.h>

int main(){
	int qtdNotas, x;
	double nota, media, soma;
	
	while(1){
	
		if(qtdNotas == 2){
			media = soma / 2.0;
			printf("media = %.2lf\n", media);
			printf("novo calculo (1-sim 2-nao)\n");
			scanf("%d", &x);
			
			if(x == 2) break;
			else{ 
				qtdNotas = 0;
				soma = 0;
			}
		}else{
			scanf("%lf", &nota);
			if( nota < 0 || nota > 10){
				printf("nota invalida\n");
			}else{
				soma += nota;
				qtdNotas += 1;
			}
		}
	}
	
	
	
}
