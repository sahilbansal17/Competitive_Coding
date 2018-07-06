#include <bits/stdc++.h>

using namespace std;

/* Template file for Online Algorithmic Competitions */
/* Typedefs */
	/* Basic types */
	typedef long long ll;
	typedef unsigned long long ull;
	/* STL containers */
	typedef vector <int> vi;
	typedef vector <ll> vll;
	typedef pair <int,int> pii;
	typedef pair <ll,ll> pll;
	typedef vector < pii > vpii;
	typedef vector < pll > vpll;
/* Macros */
	/* Loops */
	#define fl(i,a,b) for(int i(a);i<(b);i++)
	#define rep(i,n) fl(i,0,n)
	#define rfl(i,a,b) for(int i(a);i>=(b);i--)
	/* Algorithmic functions */
	#define srt(v) sort((v).begin(),(v).end())
	/* STL container methods */
	#define pb push_back
	#define mp make_pair
	/* String methods */
	#define slen(s) s.length()
	/* Shorthand notations */
	#define F first
	#define S second
	#define MOD 1000000007
	#define MAX 100010


	
int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	int sq1_x[4], sq2_x[4], sq1_y[4], sq2_y[4];

	rep(i, 4){
		cin >> sq1_x[i] >> sq1_y[i];
	}
	
	rep(i, 4){
		cin >> sq2_x[i] >> sq2_y[i];
	}

	int x1, x2, y1, y2 ; // sq1 credentials
	int x3, xc, x4, y3, yc, y4 ; // sq2 credentials

	// ascending order credentials
	sort(sq1_x, sq1_x + 4);
	x1 = sq1_x[0];
	x2 = sq1_x[2];

	sort(sq1_y, sq1_y + 4);
	y1 = sq1_y[0];
	y2 = sq1_y[2];

	sort(sq2_x, sq2_x + 4);
	x3 = sq2_x[0];
	xc = sq2_x[1];
	x4 = sq2_x[3];

	sort(sq2_y, sq2_y + 4);
	y3 = sq2_y[0];
	yc = sq2_y[1];
	y4 = sq2_y[3];

	int caesar;
	bool intersect = false;
	// completely inside
	if(x1 <= x3 && x3 < x4 && x4 <= x2 && y1 <= y3 && y3 < y4 && y4 <= y2){
		intersect = true;
		caesar = 1;
	}
	else if(x3 <= x1 && x1 < x2 && x2 <= x4 && y3 <= y1 && y1 < y2 && y2 <= y4){
		cout << x3 << " " << x1 << " " << x2 << " " << x4;
		cout << "\n" << y3 << " " << y1 << " " << y2 << " " << y4 << "\n";
		intersect = true;
		caesar = 2;
	}
	else{

		// check whether intersection points exist

		// slopes of lines 
		int m1 = +1, m2 = -1;

		// c1
		int y11 = yc - x1 + x3;
		int y12 = yc - x2 + x3;
		if(y1 <= y11 && y11 <= y2 && x3 <= x1 && x1 <= x4 && y3 <= y11 && y11 <= y4){
			intersect = true;
			caesar = 3;	
		}

		if(y1 <= y12 && y12 <= y2 && x3 <= x2 && x2 <= x4 && y3 <= y12 && y12 <= y4){
			intersect = true;
			caesar = 4;
			// cout << y12;
			// cout << "\n" << x3 << " " << x2 << " " << x4;
		}

		int x11 = x3 - y1 + yc;
		int x12 = x3 - y2 + yc;
		if(x1 <= x11 && x11 <= x2 && y3 <= y1 && y1 <= y4 && x3 <= x11 && x11 <= x4){
			intersect = true;
			caesar = 5;
		}
		if(x1 <= x12 && x12 <= x2 && y3 <= y2 && y2 <= y4 && x3 <= x12 && x12 <= x4){
			intersect = true;
			caesar = 6;
			// cout << x12;
			// cout << "\n" << y3 << " " << y2 << " " << y4;
		}

		// c2
		y11 = yc + x1 - x3;
		y12 = yc + x2 - x3;
		if(y1 <= y11 && y11 <= y2 && x3 <= x1 && x1 <= x4 && y3 <= y11 && y11 <= y4){
			intersect = true;
			caesar = 7;	
		}

		if(y1 <= y12 && y12 <= y2 && x3 <= x2 && x2 <= x4 && y3 <= y12 && y12 <= y4){
			intersect = true;
			caesar = 8;
			// cout << y12;
			// cout << "\n" << x3 << " " << x2 << " " << x4;
		}

		x11 = x3 + y1 - yc;
		x12 = x3 + y2 - yc;
		if(x1 <= x11 && x11 <= x2 && y3 <= y1 && y1 <= y4 && x3 <= x11 && x11 <= x4){
			intersect = true;
			caesar = 9;
		}
		if(x1 <= x12 && x12 <= x2 && y3 <= y2 && y2 <= y4 && x3 <= x12 && x12 <= x4){
			intersect = true;
			caesar = 10;
		}

		// c3 
		y11 = yc + x1 - x4;
		y12 = yc + x2 - x4;
		if(y1 <= y11 && y11 <= y2 && x3 <= x1 && x1 <= x4 && y3 <= y11 && y11 <= y4){
			intersect = true;
			caesar = 11;	
		}

		if(y1 <= y12 && y12 <= y2 && x3 <= x2 && x2 <= x4 && y3 <= y12 && y12 <= y4){
			intersect = true;
			caesar = 12;
			// cout << y12;
			// cout << "\n" << x3 << " " << x2 << " " << x4;
		}

		x11 = x4 + y1 - yc;
		x12 = x4 + y2 - yc;
		if(x1 <= x11 && x11 <= x2 && y3 <= y1 && y1 <= y4 && x3 <= x11 && x11 <= x4){
			intersect = true;
			caesar = 13;
		}
		if(x1 <= x12 && x12 <= x2 && y3 <= y2 && y2 <= y4 && x3 <= x12 && x12 <= x4){
			intersect = true;
			caesar = 14;
			// cout << x12;
			// cout << "\n" << y3 << " " << y2 << " " << y4;
		}

		// c4
		y11 = yc - x1 + x4;
		y12 = yc - x2 + x4;
		if(y1 <= y11 && y11 <= y2 && x3 <= x1 && x1 <= x4 && y3 <= y11 && y11 <= y4){
			intersect = true;
			caesar = 15;	
		}

		if(y1 <= y12 && y12 <= y2 && x3 <= x2 && x2 <= x4 && y3 <= y12 && y12 <= y4){
			intersect = true;
			caesar = 16;
		}

		x11 = x4 - y1 + yc;
		x12 = x4 - y2 + yc;
		if(x1 <= x11 && x11 <= x2 && y3 <= y1 && y1 <= y4 && x3 <= x11 && x11 <= x4){
			intersect = true;
			caesar = 15;
		}
		if(x1 <= x12 && x12 <= x2 && y3 <= y2 && y2 <= y4 && x3 <= x12 && x12 <= x4){
			intersect = true;
			caesar = 16;
		}
	}
	if(intersect){
		cout << "YES";
		cout << "\n" << caesar;
	}
	else{
		cout << "NO";
	}
	return 0;
}