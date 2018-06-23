/**************************************************************
Solution by Indraneel Ghosh
Probem statement:https://codeforces.com/contest/821/problem/A

***************************************************************/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, k, l, n;
    int flag = 0;
    scanf("%d", &n);
    int arr[n][n];
    int final = 1;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (arr[i][j] != 1) {
                {
                    for (l = 0; l < n; l++) {
                        for (k = 0; k < n; k++) {
                            if (arr[i][j] == arr[i][l] + arr[k][j]) {
                                flag = 1;

                                break;
                            }
                        }
                    }
                }

                if (flag == 1) {
                    final++;
                    flag = 0;
                }
                else
                    final -= 90000;
            }
            else {
                continue;
            }
        }
    }

    if (final >= 0) {
        printf("Yes");
    }
    else {
        printf("No");
    }
    return 0;
}
