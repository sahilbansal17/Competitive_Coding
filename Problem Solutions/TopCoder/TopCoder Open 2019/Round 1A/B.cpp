// solution hacked

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

class EllysCodeConstants{
private:
	
	public:
		 string getLiteral(string s) {
		 	int n = s.size();
		 	string res = "0x";
		 	int possible = 1;
		 	int next = 0;
		 	for (int i = 0; i < n; i ++) {
		 		if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'F')) {
		 			res += s[i];
		 		} 
		 		else if (s[i] == 'O') {
		 			res += '0';
		 		}
		 		else if (s[i] == 'I') {
		 			res += '1';
		 		}
		 		else if (s[i] == 'T') {
		 			res += '7';
		 		}
		 		else if (s[i] == 'S') {
		 			res += '5';
		 		}
		 		else if (s[i] == 'Z') {
		 			res += '2';
		 		}
		 		else {
		 			possible = 2;
		 			next = i;
		 			break;
		 		}
		 	}
		 	string suff;
		 	for (int j = next; j < n; j ++) {
		 		suff += s[j];
		 	}
		 	if (suff == "L" || suff == "U" || suff == "LL" || suff == "UL" || suff == "LU" || suff == "LLU" || suff == "ULL") {
		 		res += suff;
		 	}
		 	else if (possible == 2){
		 		possible = 0;
		 	}
		 	if (possible == 0) {
		 		string temp;
		 		return temp;
		 	}
		 	return res;
		 }
	
};

int main(){

	EllysCodeConstants a;
	
	
	cout << "\n" << a.getLiteral("FLUU") << "\n";
}