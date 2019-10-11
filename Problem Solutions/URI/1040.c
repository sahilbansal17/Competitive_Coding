
#include <stdio.h>
int main (){
	float a, b, c, d, media, exame;

	scanf("%f %f %f %f", &a, &b, &c, &d);

	media = (a*2+b*3+c*4+d*1)/10;

	printf("Media: %.1f\n", media);

	if (media >= 7.0){
		printf("Aluno aprovado.\n");
	}

	else if (media>= 5){
		printf("Aluno em exame.\n");
		
		scanf("%f", &exame);
			
		printf("Nota do exame: %.1f\n", exame);


			if (media + exame / 2.0 >= 5){
				printf("Aluno aprovado.\n");
			}
			else{
				printf("Aluno reprovado.\n");
			}

			printf("Media final: %.1f\n",(media + exame) / 2);

	}
	else {
		printf("Aluno reprovado.\n");
	}

	return 0;

}
