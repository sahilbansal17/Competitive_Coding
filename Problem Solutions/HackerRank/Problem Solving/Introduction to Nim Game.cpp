#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    int g;
    std::cin >> g;
    std::vector<std::string> ans;
    for (int i = 0; i < g; i++)
    {
        int n;
        std::cin >> n;
        int s = 0, t;
        for (int j = 0; j < n; j++)
        {
            std::cin >> t;
            s = s ^ t;
        }
        if (s == 0)
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
