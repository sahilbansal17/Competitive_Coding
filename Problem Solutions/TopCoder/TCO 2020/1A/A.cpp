#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

class AveragePrice {
public:
    double nonDuplicatedAverage(vector <int> prices) {
        set<int> price_set;
        for (auto price: prices) {
            price_set.insert(price);
        }
        int sum = 0;
        int cnt = 0;
        for (auto price: price_set) {
            sum += price;
            ++cnt;
        }
        return (1.0*sum)/cnt;
    }
};

int main () {
    AveragePrice e;
    cout << e.nonDuplicatedAverage({10, 10, 20}) << endl;
    return 0;
}