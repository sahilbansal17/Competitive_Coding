#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
    ll T;
    cin >> T;
    while(T--) {
        ll N, K;
        cin >> N >> K;
        vector<ll> v(N);
        for(ll &i : v) cin >> i;
        if((N % 2) && (K > N/2))
            v[(N-1)/2] = 0;
        K = K % (N * 3); // After 2 * N xor will repeat values from original array
        for(ll i = 0;i < K;i++) v[i % N] ^= v[N-(i % N) - 1];
        for(ll i : v) cout << i << " ";
        cout << endl;
    }
    return 0;
}