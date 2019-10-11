#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
	 int numCasos;
	 short hora, minuto, acao;
     
     scanf("%d", &numCasos);

     while(numCasos--){
     	scanf("%hd %hd %hd", &hora, &minuto, &acao);

        printf("%02hd:%02hd - A porta ", hora, minuto);
       
        if(acao) printf("abriu!\n");
        else printf("fechou!\n");
     }

	 return 0;
}
