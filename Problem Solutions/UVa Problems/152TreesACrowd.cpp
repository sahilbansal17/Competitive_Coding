// UVA 152 - Tree's a Crowd

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define FOR(i,a,b) for(int i(a);i<(b);i++)
#define RFOR(i,a,b) for(int i(a);i>=(b);i--)
#define SORT(v) sort((v).begin(),(v).end())
#define pb push_back
#define EPS 1e-9 // epsilon 

struct point{
	int x,y,z;
	point(int _x, int _y, int _z){
		x = _x;
		y = _y;
		z = _z;
	}
	// comparison function to be used while sorting list of points 
	bool operator < (point other) const{
		if(x != other.x)
			return x < other.x; // first preference to x
		if(y != other.y)
			return y < other.y; // second preference to y
		return z < other.z; // last preference to z
	}
};
// # function to calculate the euclidean distance between two points
int dist(point p1, point p2){
	int inside_root = pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2);
	return sqrt(inside_root);
}

int main(){

	/* FOR READING INPUT FROM FILE & WRITING OUTPUT TO FILE 

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	*/
	
	int x,y,z;
	vector <point> p;
	while(1){
		scanf("%d %d %d",&x,&y,&z);
		if(x == 0 && y == 0 && z == 0){
			break;
			// as specified in input formatting for the problem
		}
		p.pb(point(x,y,z)); // adding this point to the vector (list) of points
	}
	SORT(p);
	vector <int> count(10,0); // histogram array 
	/* BRUTE FORCE APPROACH

	FOR(i,0,p.size()){
		int min_dist = INT_MAX;
		// finding the closest neighbour of this point
		FOR(j,0,p.size()){
			if(j!=i){
				if(dist(p[i],p[j]) < min_dist){
					min_dist = dist(p[i],p[j]);
				}
			}
		}
		if(min_dist < 10)
			count[min_dist]++; 
	}

	*/

	// FASTER APPROACH : since the points are sorted, we first check on the left side of the point and then right side
	int min_dist,current_dist;
	FOR(i,0,p.size()){
		min_dist = 10;
		// for left side
		RFOR(j,i-1,0){
			if(abs(p[i].x - p[j].x) > min_dist){
				break;
				// it will stop as soon as we can no longer get a point with smaller distance
			}
			current_dist = dist(p[i],p[j]);
			if(current_dist < min_dist){
				min_dist = current_dist;
			} 
		}

		// similarly for right side as possibility exists that closest neighbour has larger x-coordinate value than this point
		FOR(j,i+1,p.size()){
			if(abs(p[i].x - p[j].x) > min_dist){
				break;
			}
			current_dist = dist(p[i],p[j]);
			if(current_dist < min_dist){
				min_dist = current_dist;
			}
		}
		if(min_dist < 10){
			count[min_dist]++; // update the count table with appropriate distance value
		}
	}
	/* TO SEE THE SORTED LIST OF POINTS

	FOR(i,0,p.size()){
		cout << p[i].x << " " << p[i].y << " " << p[i].z << "\n";
	}

	*/
	FOR(i,0,10){
		printf("%4d",count[i]); // as specified in output formatting for the problem
	}
	printf("\n");  // without this you get a WA verdict
	return 0;
}