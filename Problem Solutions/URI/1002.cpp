#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double raio, n = 3.14159;
    cin >> raio;
    double saida = n * pow(raio, 2);
    printf("A=%.4f", saida);
    cout << endl;
    return 0;
}