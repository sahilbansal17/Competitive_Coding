#include <iostream>
#include <algorithm>
int main()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, k, a, b = 0;
        std::cin >> n >> k;
        for (int j = 0; j < n; j++)
        {
            std::cin >> a;
            b = b ^ a;
        }
        if (b == 0)
        {
            std::cout << "Second \n";
        }
        else
        {
            std::cout << "First \n";
        }
    }
}
