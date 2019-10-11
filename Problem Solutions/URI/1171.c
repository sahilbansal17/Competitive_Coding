#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void inserctionSort(int *, int);

int main()
{
  int n, i, j, total, compara;
	
  scanf("%d", &n);
	
  int vetor[n];
	
  for(i = 0; i < n; i++)
    scanf("%d", &vetor[i]);
	
  inserctionSort(vetor, n);
	
  i = 0;
  while(i < n)
  {
    compara = vetor[i];
    total = 0;
		
    while(1)
    {
      if(vetor[i] == compara) total++;
      else break;	
      i++;			
    }
	  
    printf("%d aparece %d vez(es)\n", compara, total);
	  
  }
	
  return 0;
}

void inserctionSort(int *vetor, int n)
{
  int pivo = 1, aux, i;
	
  while(pivo < n){
    aux = vetor[pivo];
    i = pivo - 1;
		
  while(vetor[i] > aux)
  {
     vetor[i+1] = vetor[i];
     i--;
     if(i < 0) break;
  }
	  
  vetor[i+1] = aux;
  pivo++;
  }
}
