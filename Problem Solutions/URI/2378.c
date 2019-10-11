#include <stdio.h>

int main(){
    int N, C, S, E, P;
    int sobrecarga;
    while(scanf("%d %d", &N, &C) != EOF){
        P = 0;
        sobrecarga = 0;
        while(N--){
            scanf("%d %d", &S, &E);
            P -= S;
            P += E;
            if(P > C)
                sobrecarga = 1;
        }
        printf("%c\n", sobrecarga ? 'S' : 'N');
    }
    return 0;
}
