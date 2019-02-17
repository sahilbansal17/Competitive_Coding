#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef long long ll;

const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

template <typename T> T gcd(T a, T b) { 
    if(b == 0) 
        return a; 
    return gcd(b, a % b); 
}

template <typename T> T power(T x, T y, ll m = MOD) {
    T ans = 1; 
    x %= m; 
    while (y > 0) { 
        if (y & 1LL) {
            ans = (ans * x) % m;   
        } 
        y >>= 1LL; 
        x = (x * x) % m; 
    } 
    return (ans % m); 
}

// Returns count of subarrays of arr with XOR 
// value equals to m 
long long subarrayXor(vector <int> arr, int n, int m) { 
    long long ans = 0; // Initialize answer to be returned 
  
    // Create a prefix xor-sum array such that 
    // xorArr[i] has value equal to XOR 
    // of all elements in arr[0 ..... i] 
    int* xorArr = new int[n]; 
  
    // Create map that stores number of prefix array 
    // elements corresponding to a XOR value 
    unordered_map<int, int> mp_odd, mp_even; 
  
    // Initialize first element of prefix array 
    xorArr[0] = arr[0]; 
  
    // Computing the prefix array. 
    for (int i = 1; i < n; i++) {
        xorArr[i] = xorArr[i - 1] ^ arr[i]; 
        // cerr << xorArr[i] << " ";
    }
  
    // Calculate the answer 
    for (int i = 0; i < n; i++) { 
        // Find XOR of current prefix with m. 
        int tmp = m ^ xorArr[i]; 
  
        // If above XOR exists in map, then there 
        // is another previous prefix with same 
        // XOR, i.e., there is a subarray ending 
        // at i with XOR equal to m. 
        if (i % 2 == 0) ans = ans + ((long long)mp_odd[tmp]); 
        else ans = ans + ((long long)mp_even[tmp]);
  
        // If this subarray has XOR equal to m itself. 
        if (xorArr[i] == m && (i % 2 == 1))
            // i % 2 == 1 because even length
            ans++; 
  
        // Add the XOR of this subarray to the map 
        if (i % 2 == 0) mp_odd[xorArr[i]]++; 
        else mp_even[xorArr[i]] ++;
    } 
  
    // Return total count of subarrays having XOR of 
    // elements as given value m 
    return ans; 
} 

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    #endif

    FAST_IO;    

    int n;
    cin >> n;

    vector <int> a(n);

    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    long long ans = subarrayXor(a, n, 0);
    cout << ans << endl;

    return 0;
}