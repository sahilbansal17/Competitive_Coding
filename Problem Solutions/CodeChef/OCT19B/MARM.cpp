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
        for(ll &i : v) cin >> i; // Input array
        // If N is odd and K > N/2 that means v[(N-1)/2] = v[(N-1)/2] ^ v[(N-1)/2] = 0
        // So we set that to zero
        if((N % 2) && (K > N/2))
            v[(N-1)/2] = 0;
        // After 3N values xor will restore the array
        // A = A ^ B = C
        // B = B ^ A = B ^ C = A
        // A = A ^ B = C ^ A = B
        // B = B ^ A = A ^ B = C
        // A = A ^ B = B ^ C = A
        // B = B ^ A = C ^ A = B
        // Hence we will revert back to the same array, except for (N-1)/2 that will remain zero
        K = K % (N * 3);
        for(ll i = 0;i < K;i++) v[i % N] ^= v[N-(i % N) - 1];
        for(ll i : v) cout << i << " ";
        cout << endl;
    }
    return 0;
}