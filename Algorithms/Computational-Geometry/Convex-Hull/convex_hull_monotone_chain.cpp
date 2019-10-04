#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

using pii = pair<int,int>;

pii getVector(pii a, pii b){
	return {a.first - b.first,a.second - b.second};
}

int orientation(pii a, pii b){
	return a.first*b.second - a.second*b.first;
}

bool clockwise(pii a, pii b, pii c){
	int r = orientation(getVector(a,c),getVector(b,c));
	return r <=  0;
}

int distance(pii a,pii b){
	int dx = abs(a.first - b.first);
	int dy = abs(a.second - b.second);
	return dx*dx + dy*dy;
}

vector<pii> monotoneChain(vector<pii> v){
	vector<pii> up, down;
	sort(v.begin(), v.end());

	for(int i=0;i<v.size();i++){
		while(up.size() >= 2){
			if(clockwise(up[up.size() - 2], up.back(), v[v.size() - 1 - i]))
				up.pop_back();
			else
				break;
		}
		up.push_back(v[v.size() - 1 - i]);

		while(down.size() >= 2){
			if(clockwise(down[down.size() - 2], down.back(), v[i]))
				down.pop_back();
			else
				break;
		}
		down.push_back(v[i]);
	}
	up.pop_back();
	down.pop_back();
	up.insert(up.begin(), down.begin(), down.end());

	return up;
}

