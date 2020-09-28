#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> arr;
    arr.resize(N);
    unordered_map<int, int> index_of_elem;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        index_of_elem[arr[i]] = i;
    }
    for (int i = 0; i < N; i++)
    {
        if (K == 0)
        {
            break;
        }
        if (arr[i] == N - i)
        {
            continue;
        }
        // Swap i'th largest element to the front
        index_of_elem[arr[i]] = index_of_elem[N - i];
        arr[index_of_elem[N - i]] = arr[i];
        arr[i] = N - i;
        K--;
    }
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
