#include <stdio.h>

int main(){
	int inter = 0, gremio = 0, golI = 0, golG = 0, empate = 0, jogos = 0, x = 0;
	
	while(1){
		scanf("%d %d", &golI, &golG);
		jogos += 1;
		if(golI > golG){
			inter += 1;
		}else if(golG > golI){
			gremio += 1;
		}else{
			empate += 1;
		}
		printf("Novo grenal (1-sim 2-nao)\n");
		scanf("%d", &x);
		if (x == 2) break;
		
	}
	
	printf("%d grenais\n", jogos);
	printf("Inter:%d\n", inter);
	printf("Gremio:%d\n", gremio);
	printf("Empates:%d\n", empate);
	if(inter > gremio)
		printf("Inter venceu mais\n");
	else if(gremio > inter)
		printf("Gremio venceu mais\n");
	else
		printf("Nao houve vencedor\n");
	
	
	
}
