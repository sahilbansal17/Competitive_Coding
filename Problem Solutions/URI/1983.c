#include <stdio.h>

int main(){
	int n;
	
	scanf("%d", &n);
	int alunos[n], i , local;
	double notas[n], max = 0.0;
	
	for(i = 0; i < n; i++)
		scanf("%d %lf", &alunos[i], &notas[i]);
	
	for(i = 0; i < n; i++){
		if(notas[i] > max){
			max = notas[i];
			local = i;
		}
	}
	
	if(max < 8)
		printf("Minimum note not reached\n");
	else
		printf("%d\n", alunos[local]);
	
	return 0;
	
	
}
