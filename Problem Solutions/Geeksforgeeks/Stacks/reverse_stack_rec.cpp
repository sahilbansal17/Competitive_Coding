// https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/

// C++ code to reverse a stack using recursion

#include <bits/stdc++.h>
using namespace std;

void pushBottom(stack <int> &s, int ele) {
	// base case: stack size = 0, push ele
	if (s.size() == 0) {
		s.push(ele);
		return ;
	}

	// fetch the top element and pop
	int top_ele = s.top();
	s.pop();

	// call push bottom on remaining stack
	pushBottom(s, ele);

	// push to top_ele in the stack
	s.push(top_ele);
}

void reverse(stack <int> &s) {
	// base case: stack size = 0, return
	if (s.size() == 0) {
		return; 
	} 

	// pop the element at the top
	int top_ele = s.top();
	s.pop();

	// call reverse on the remaining stack
	reverse(s);

	// push the top_element in the bottom
	pushBottom(s, top_ele);
}

int main () {

	stack <int> s;
	for (int i = 1; i <= 10; i ++) {
		s.push(i);
	}

	reverse(s);

	cout << "Reversed Stack:" << endl;

	for (int i = 1; i <= 10; i ++) {
		cout << s.top() << " ";
		s.pop();
	}
}