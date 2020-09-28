#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> order;
    for (int i = 0; i < n; i++)
    {
        int t, d;
        cin >> t >> d;
        order.push_back({t + d, i + 1});
    }
    sort(order.begin(), order.end());
    for (int i = 0; i < n; i++)
    {
        cout << order[i].second << " ";
    }
    return 0;
}
