#include <stdio.h>

int main(){
	int a, b, c, aux;
	scanf("%d %d %d", &a, &b, &c);
	int v[3];
	
	v[0] = a;
	v[1] = b;
	v[2] = c;
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j< 3; j++){
			if(v[i] < v[j]){
				aux = v[j];
				v[j] = v[i];
				v[i] = aux;
			}
		}
	}
	
	printf("%d\n%d\n%d\n", v[0], v[1], v[2]);
	
	return 0;
}
