/*
 * Problem Link: https://www.interviewbit.com/problems/evaluate-expression/
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int convertToInt(string s) {
    int n = s.length();
    int res = 0;
    bool neg = 0;
    int i = 0;
    if (s[0] == '-') {
        neg = 1;
        i = 1;
    }
    while (i < n) {
        res = res * 10 + (s[i] - '0');
        ++i;
    }
    return (neg == 0) ? res : -1*res;
}

bool isInt(string s) {
    int n = s.length();
    if (s[0] == '-' && n > 1) {
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            continue;
        } else {
            return 0;
        }
    }
    return 1;
}

int evalRPN(vector<string> &A) {
    reverse(A.begin(), A.end());
    stack<string> st;
    int n = A.size();
    int op1, op2, res, ans;
    string op;
    int consecNumbersCnt = 0;
    for (int i = 0; i < n; ++i) {
        if (A[i] == "+"
        || A[i] == "-"
        || A[i] == "*"
        || A[i] == "/") {
            st.push(A[i]);
            consecNumbersCnt = 0;
        } else {
            st.push(A[i]);
            ++consecNumbersCnt;
            if (consecNumbersCnt == 2) {
                op1 = convertToInt(st.top());
                st.pop();
                op2 = convertToInt(st.top());
                st.pop();
                op = st.top();
                st.pop();
                if (op == "+") {
                    res = op1 + op2;
                } else if (op == "-") {
                    res = op1 - op2;
                } else if (op == "*") {
                    res = op1 * op2;
                } else {
                    res = op1 / op2;
                }
                ans = res;
                while (!st.empty() && isInt(st.top())) {
                    op2 = convertToInt(st.top());
                    st.pop();
                    op1 = res;
                    op = st.top();
                    st.pop();
                    if (op == "+") {
                        res = op1 + op2;
                    } else if (op == "-") {
                        res = op1 - op2;
                    } else if (op == "*") {
                        res = op1 * op2;
                    } else {
                        res = op1 / op2;
                    }
                    ans = res;
                }
                st.push(to_string(res));
                consecNumbersCnt = 1;
            }
        }
    }
    ans = convertToInt(st.top());
    st.pop();
    return ans;
}

int main () {

  vector<string> vs;
  vs.push_back("-2");
  vs.push_back("-1");
  vs.push_back("+");
  cout << evalRPN(vs);
  return 0;
}