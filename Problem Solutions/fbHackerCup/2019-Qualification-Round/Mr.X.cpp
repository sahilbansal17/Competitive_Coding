// Gives Wrong answer, to be fixed

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isClosing(char s) {
	if (s == ')') {
		return true;
	}
	return false;
}

bool isOpening(char s) {
	if (s == '(') {
		return true;
	}
	return false;
}

bool isVariable(char s) {
	if (s == 'x' || s == 'X') {
		return 1;
	} return 0;
}

bool myNegate(char s) {
	if (s == 'x') {
		return 'X';
	} else if (s == 'X') {
		return 'x';
	} else if (s == '0') {
		return '1';
	} else {
		return '0';
	}
}
char evaluate(char opr1, char opt, char opr2) {
	char res;
	switch (opt) {
		case '|':
			if (opr1 == '1' || opr2 == '1') {
				res = '1';
			} else if (opr1 == '0') {
				res = opr2;
			} else if (opr2 == '0') {
				res = opr1;
			} else if ((opr1 == 'x' && opr2 == 'X') || (opr1 == 'X' || opr2 == 'x')) {
				res = '1';
			} else {
				// opr1 = opr2 in this case
				res = opr1;
			}
			break;
		case '&':
			if (opr1 == '0' || opr2 == '0') {
				res = '0';
			} else if (opr1 == '1') {
				res = opr2;
			} else if (opr2 == '1') {
				res = opr1;
			} else if (opr1 == opr2) {
				res = opr1;
			} else {
				// both are different
				res = '0';
			}
			break;
		case '^':
			if (opr1 == '1') {
				res = myNegate(opr2);
			} else if (opr2 == '1') {
				res = myNegate(opr1);
			} else if (opr1 == '0') {
				res = opr2;
			} else if (opr2 == '0') {
				res = opr1;
			} else if ((opr1 == 'x' && opr2 == 'X') || (opr1 == 'X' && opr2 == 'x')) {
				res = '1';
			} else if (opr1 == opr2) {
				res = '0';
			}
			break;
	}
	return res;
}
int main(){

	// #ifndef ONLINE_JUDGE
	// freopen("/Users/sahilbansal/Downloads/mr_x.txt", "r", stdin);
	// freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	// freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
	// #endif

	int t;
	cin >> t;

	for (int k = 0; k < t; k ++) {
		string s;
		cin >> s;

		stack <char> st;
		int n = s.length();
		for (int i = 0; i < n; i ++) {
			if (isOpening(s[i])) {
				st.push(s[i]); // not necessary
			} else if (isClosing(s[i])) {
				// pop the operator and 2 operands
				char opr1 = st.top();
				st.pop();
				char opt = st.top();
				st.pop();
				char opr2 = st.top();
				st.pop();
				// pop the opening parenthesis
				st.pop();

				char res = evaluate(opr1, opt, opr2);
				st.push(res);
			} else {
				st.push(s[i]);
			}
		}

		int res = 0;
		// assert(st.size() == 1);
		if (isVariable(st.top() ) ) {
			// 1 modification will work
			res = 1;
		}

		// cerr << st.top() << endl;
		cout << "Case #" << k + 1 << ": " << res << endl;
	}	

	return 0;
}