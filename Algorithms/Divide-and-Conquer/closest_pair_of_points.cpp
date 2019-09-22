/**
Closest pair of points in an Euclidean Plane.
! ^ represents exponentiation.

Consider an euclidean plane which contains N points given by their coordinates.
The euclidean distance between 2 points A(x1, y1) and B(x2, y2) is equal to sqrt((x1-x2)^2 + (y1-y2)^2) and shall be expressed as d(A, B) from now on.
We have to determine the distance between distance between the 2 closest points.

One straightforward solution is to consider every pair of points A and B and calculate d(A, B) for every one of them.
However, this approach has an O(n^2) time complexity.

An efficient solution follows the divide & conquer paradigm and has an O(n*log2(n)) time complexity.
Let P be a subset of the given points. If |P| (cardinal of P) < 4, we will consider all |P|/2 pairs and remember the minimum [**].
If |P| >= 4, we will use a divide & conquer approach as it follows:
    1. divide: determine a vertical line, let's call it a, which "cuts" the subset in 2 smaller ones, let's say PL (left) and PR (right), as close in size as possible.
    2. conquer: 2 recursive calls to determine the closest pair of points in PL and PR.
    3. combine: let's assume that D = min distance between 2 points. D is either determined by one of the 2 recursive calls, or is satisfied by a point in PL and one in PR [1].
       We can observe that if we have a possible D from the recursive calls, we can find [1] if the distance between every point and line a is < D, so the 2 points shall be contained in a region of length 2*D.
       In order to determine if 2 points which satisfy [1] exist, we can do the following:
            - build another array, let's call it Q, ordered by the y coordinate.
            - for each point q in Q we try to find points k in Q such as d(q, k) < D and return the one for which d(q, k) is minimum.

For precision, in the implementation below I chose to work with the squares of the distances.
For optimality, we should obtain Q by sorting the numbers by y at [**], and then merge them on returning from recursion.

Test data:
N = 10
Points: X Y
26 77
12 37
14 18
19 96
71 95
91 9
98 43
66 77
2 75
94 91

expected result: 18.681542
**/
#include <bits/stdc++.h>

using namespace std;

struct point {
    int x, y;
};
vector<point> P, Q;

/// functors for sorting points.
class compX {
    public: bool operator()(const point& A, const point& B) {
        return A.x < B.x;
    };
};
class compY {
    public: bool operator()(const point& A, const point& B) {
        return A.y < B.y;
    };
};

inline int sqr(int x) {
    return x*x;
}

int dist(const point& A, const point& B) {
    return sqr(A.x - B.x) + sqr(A.y - B.y);
}

int minDist(int f, int l) {
    int minD = INT_MAX;
    for(int i = f; i < l; i++)
        for(int j = i+1; j <= l; j++)
            minD = min(minD, dist(P[i], P[j]));
    return minD;
}

/// divide & conquer function call.

int calculateD(int f, int l) {
    if(l-f < 4) {
        sort(P.begin()+f, P.begin()+l+1, compY());
        return minDist(f, l);
    }
    int m = (f+l) / 2, /// determine the median -> line a.
        x = P[m].x,
        D = min(calculateD(f, m), calculateD(m, l));
    merge(P.begin()+f, P.begin()+m+1, P.begin()+m+1, P.begin()+l+1, Q.begin()+f, compY());
    /// we will determine Q by merging the 2 subsets. (PL and PR)
    int k = 0;
    for(int i = f; i <= l; i++) {
        P[i] = Q[i];
        if(sqr(P[i].x - x) < D)
            Q[++k] = P[i];
    }

    for(int i = 1; i < k; i++)
        for(int j = i+1; j <= k && sqr(Q[j].y - Q[i].y) < D; j++)
            D = min(D, dist(Q[i], Q[j]));

    return D;
}

int main()
{
    int N;
    cout << "Give the number of points (N): "; cin >> N;
    P.reserve(N);
    Q.reserve(N); /// we have to reserve memory in advance for Q
    cout << "Give the points by their x, y coordinates:\n";
    int x, y;

    for(int i = 1; i <= N; i++) {
        cin >> x >> y;
        P.push_back({x, y});
    }

    sort(P.begin(), P.end(), compX());

    cout << fixed << setprecision(6) << sqrt(calculateD(0, N-1));
    return 0;
}
