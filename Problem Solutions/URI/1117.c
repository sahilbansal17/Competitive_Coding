#include <stdio.h>

int main(){
	int count;
	double nota, soma, media;
	
	while(1){
		
		if(count == 2) break;
		
		scanf("%lf", &nota );
		
		if(nota < 0 || nota > 10){
			printf("nota invalida\n");
			
		}else{
			count++;
			soma += nota;	
		}
		
	}
	media = soma / 2.0;
	printf("media = %.2lf\n", media);
	
	return 0;
}
