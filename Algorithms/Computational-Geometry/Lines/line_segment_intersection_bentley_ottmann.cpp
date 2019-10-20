#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;
typedef pair<int, int> point;

struct event {
    point p1;
    point p2;
    int type;
    event() {}
    // Initialization of point
    event(point p1, point p2, int type) : p1(p1), p2(p2), type(type) {}
};

bool compare(const event &a, const event &b) {
    return a.p1.second < b.p1.second;
}

void intersection(vector<event> &events) {
    set<point> s;
    for(event e : events) {
        if(e.type == 0) s.insert(e.p1);
        else if(e.type == 1) s.erase(e.p2);
        else {
            for(auto it = s.lower_bound({e.p1.first, -1}); it != s.end() && it->first <= e.p2.first; it++)
                cout << e.p1.second << " " << it->first << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    int x1, y1, x2, y2;
    vector<event> events;
    for(int i = 0;i < N;i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        // If vertical line then we add only one event of type 2
        if(x1 == x2) events.push_back(event({y1, x1}, {y2, x2}, 2));
        else {
            // For horizontal line we add two events:
            // For starting point of type 0
            // For ending point of type 1
            // We add second event p2 first and then p1 because
            // We sort on p1,so ending points first
            // We remove a line when we hit its end point so we need it's starting point
            // Hence store in reverse order
            events.push_back(event({y1, x1}, {y2, x2}, 0));
            events.push_back(event({y2, x2}, {y1, x1}, 1));
        }
    }
    sort(events.begin(), events.end(), compare);
    intersection(events);
    return 0;
}
