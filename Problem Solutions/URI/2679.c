#include <stdio.h>

int main(){
    int x;
    while(scanf("%d", &x) != EOF){
        printf("%d\n", x&1 ? x+1 : x+2);
    }
    return 0;
}
