#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(int argc, char const *argv[])
{
    ll T;
    cin >> T;
    while (T--)
    {
        ll N, M, Q;
        cin >> N >> M >> Q;
        vector<ll> vn(N, 0), vm(M, 0);
        ll a, b;
        while(Q--) {
            cin >> a >> b;
            vn[a-1] = (vn[a-1] ? 0 : 1);
            vm[b-1] = (vm[b-1] ? 0 : 1);
        }
        ll nval = 0, mval = 0;
        for(ll it : vn) nval += it;
        for(ll it : vm) mval += it;

        ll res = (nval * M) + (mval * N) - (2 * nval * mval);
        cout << res << endl;
    }
    
    return 0;
}