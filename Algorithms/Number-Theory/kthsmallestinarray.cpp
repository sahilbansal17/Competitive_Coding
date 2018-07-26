#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int KthSmallest(vector<int>, int);

int main(void){
	vector <int> v;
	int k;
	cout<<"Enter the value of K:\n";
	cin>>k;
	cout<<"Enter the number of array elements:\n";
	int n, num = 0;
	cin>>n;
	for(int i = 0; i < n; i ++){
		cin>>num;
		v.push_back(num);
	}
	cout<<"The Kth samllest element is: "<<KthSmallest(v, k)<<endl;

	return 0;
}

int KthSmallest(vector<int> v, int k){
	priority_queue<int, vector<int>, greater<> > pq(v.begin(), v.end());

	while(--k){
		pq.pop();
	}

	return pq.top();
}
