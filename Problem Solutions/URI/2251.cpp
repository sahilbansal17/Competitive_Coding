#include <stdio.h>
#include <math.h>

int main()
{
    int n, tab[31], c = 1;
    for (int i = 0; i < 31; i++) {
        tab[i] = pow(2, i) - 1;
    }
    while (1) {
        scanf("%d", &n);
        if (!n) {
            break;
        }
        printf("Teste %d\n%d\n\n", c++, tab[n]);
    }
    return 0;
}
