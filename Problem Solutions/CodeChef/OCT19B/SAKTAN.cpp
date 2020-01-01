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
        vector<ll> vn(N, 0), vm(M, 0); // Vectors to store whether row and column selections
        ll a, b;
        while(Q--) {
            cin >> a >> b;
            // Instead of inputting values in a 2D array
            // Store whether given row/column index will be contribute towards odd numbers
            // So adding each time we switch the values, so if a row/column index comes up even times it does not effect total number of odd cells
            vn[a-1] = (vn[a-1] ? 0 : 1);
            vm[b-1] = (vm[b-1] ? 0 : 1);
        }
        ll nval = 0, mval = 0;
        // Add all row and column sums
        for(ll it : vn) nval += it;
        for(ll it : vm) mval += it;
        // Total number of rows affecting * No. of Columns will give number of cells affected by the rows
        // Vice-versa for columns
        // Intersection points will be repeated so we subtract them
        ll res = (nval * M) + (mval * N) - (2 * nval * mval);
        cout << res << endl;
    }
    
    return 0;
}