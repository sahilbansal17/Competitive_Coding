// https://www.geeksforgeeks.org/orientation-3-ordered-points/

// C++ code to find orientation of 3 ordered points

#include <bits/stdc++.h>
using namespace std;

vector <pair <int, int> > points;

int findOrientation(vector <pair <int, int> > points) {

}

int main () {

	int n = 3, x, y;
	for (int i = 0; i < n; i ++) {
		cin >> x >> y;
		points.push_back({x, y});
	}

	int orientation = findOrientation(points);
	
	return 0;
}