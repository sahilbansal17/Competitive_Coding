/*
 * Problem Link: https://codedrills.io/problems/day-1-beating-shell-sort
 * Concepts involved: Shell Sort
 */

#include <bits/stdc++.h>
using namespace std;

#define MAX 5000
int main () {

    int n;
    cin >> n;

    vector<int> a(MAX);
    for (int i = 0; i < MAX; ++i) {
        a[i] = (i + 1);
    }

    // takes the position as input which is to be changed to ZERO
    int pos;
    cin >> pos;
    a[pos] = 0;

    vector<int> gaps(n);
    for (auto &gap: gaps) {
        cin >> gap;
    }

    int i, j;
    for (auto gap: gaps) {
        for (i = gap; i < MAX; i += 1) {
            int temp = a[i];
            for (j = i; j >= gap and a[j - gap] > temp; j -= gap) {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }

    for (int i = 0; i < MAX; ++i) {
        cout << a[i] << endl;
    }

    return 0;
}