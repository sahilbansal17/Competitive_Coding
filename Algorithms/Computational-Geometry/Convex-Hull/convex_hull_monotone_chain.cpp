// Name: tpoppo
// C++ program for monotone chain to find the convex hull
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

using pii = pair<int,int>;

pii getVector(pii a, pii b){
	return {a.first - b.first,a.second - b.second};
}
// Cross product
int orientation(pii a, pii b){
	return a.first*b.second - a.second*b.first;
}

// Check if the orientation of the three points is clockwise
bool clockwise(pii a, pii b, pii c){
	int r = orientation(getVector(a,c),getVector(b,c));
	return r <=  0;
}
// Squared euclidean distance
int distance(pii a,pii b){
	int dx = abs(a.first - b.first);
	int dy = abs(a.second - b.second);
	return dx*dx + dy*dy;
}

// Find the convex hull given a set of 2d points
// Return the points in the convex hull in a counterclockwise fashion
vector<pii> monotoneChain(vector<pii> v){
	vector<pii> up, down;
	sort(v.begin(), v.end());

	for(int i=0;i<v.size();i++){

		// Upper chain
		while(up.size() >= 2){
			// Check if the polygon is still convex
			if(clockwise(up[up.size() - 2], up.back(), v[v.size() - 1 - i]))
				up.pop_back();
			else
				break;
		}
		up.push_back(v[v.size() - 1 - i]);

		// Lower chain
		while(down.size() >= 2){
			// Check if the polygon is still convex
			if(clockwise(down[down.size() - 2], down.back(), v[i]))
				down.pop_back();
			else
				break;
		}
		down.push_back(v[i]);
	}
	up.pop_back();
	down.pop_back();
	//merge the chain
	up.insert(up.begin(), down.begin(), down.end());

	return up;
}
// Time Complexity: O(n logn), due to sorting
// O(n logn) complexity for sorting
// O(n) complexity for creating the upper and lower chain, because every element can be push and pop from each chain at most once 


// Solution for Convex Hull 1
// https://www.hackerrank.com/contests/justins-test-contest/challenges/convex-hull-1/problem
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int t;
	int n;
	vector<pii> v;
	cin >> t;
	for(int _=0;_<t;_++){
			cin>>n;
			v.resize(n);
			for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
			auto rs = monotoneChain(v);
			//rotate until the first point is the smallest
			rotate(rs.begin(),min_element(rs.begin(),rs.end()),rs.end());
			cout<<"Case #"<<(_+1)<<'\n';
			for(auto el : rs) cout<<el.first<<" "<<el.second<<'\n';
			v.clear();
	}

	return 0;
}