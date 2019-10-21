#include <stdio.h>
int main()
{
int A[10000]={0}, i, j, Q, N, a, b;
scanf("%d", &N);

for(i=0; i<N; i++){
scanf("%d", &a);
A[a]++;
}

scanf("%d", &Q);
for(i=0; i<Q; i++){
scanf("%d", &b);
if(A[b]==0){
printf("NOT PRESENT\n");
}
else
printf("%d\n", A[b]);
}

return 0;
}
