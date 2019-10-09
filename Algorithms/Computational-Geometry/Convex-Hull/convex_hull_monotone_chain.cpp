// Name: tpoppo
// C++ program for monotone chain to find the convex hull
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

using pii = pair<int,int>;

pii getVector(pii a, pii b){
    return {a.first - b.first, a.second - b.second};
}
// Cross product
int orientation(pii a, pii b){
    return a.first*b.second - a.second*b.first;
}

// Check if the orientation of the three points is clockwise
bool clockwise(pii a, pii b, pii c){
    int r = orientation(getVector(a,c), getVector(b,c));
    return r <=  0;
}
// Squared euclidean distance
int distance(pii a, pii b){
    int dx = abs(a.first - b.first);
    int dy = abs(a.second - b.second);
    return dx*dx + dy*dy;
}
// Find the convex hull given a set of 2d points
// Return the points in the convex hull in a counterclockwise fashion
vector<pii> monotoneChain(vector<pii> points){
    vector<pii> up, down;
    sort(points.begin(), points.end());

    for(int i=0; i<points.size(); ++i){

        // Upper chain
        while(up.size() >= 2){
            // Check if the polygon is still convex
            if(clockwise(up[up.size() - 2], up.back(), points[points.size() - 1 - i]))
                up.pop_back();
            else
                break;
        }
        up.push_back(points[points.size() - 1 - i]);

        // Lower chain
        while(down.size() >= 2){
            // Check if the polygon is still convex
            if(clockwise(down[down.size() - 2], down.back(), points[i]))
                down.pop_back();
            else
                break;
        }
        down.push_back(points[i]);
    }
    up.pop_back();
    down.pop_back();
    //merge the chains
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
    vector<pii> points;
    
    cin >> t;
    for(int tcase = 0; tcase < t; ++tcase){
            cin >> n;
            points.resize(n);
    
            for(int i = 0; i < n; ++i) 
                cin >> points[i].first >> points[i].second;
    
            auto rs = monotoneChain(points);
            //rotate until the first point is the smallest
            rotate(rs.begin(), min_element(rs.begin(), rs.end()), rs.end());
            
            cout << "Case #" << (tcase + 1) << '\n';
            for(auto el : rs) 
                cout << el.first << " " << el.second << '\n';
            points.clear();
    }
    return 0;
}