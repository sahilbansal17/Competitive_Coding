#include <iostream>
#include <algorithm>
#include <vector>
int main()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, a = 0, b;
        std::cin >> n;
        for (int j = 0; j < n; j++)
        {
            std::cin >> b;
            if (j > 0 && b % 2 == 1)
            {
                a = a ^ j;
            }
        }
        if (a == 0)
        {
            std::cout << "Second"
                      << "\n";
        }
        else
        {
            std::cout << "First"
                      << "\n";
        }
    }
}
