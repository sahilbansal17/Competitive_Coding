/**
We are given 3 points in a plane (A, B, C) by their x and y coordinates. We have to compute their area.

One mathematical approach is to use Heron's formula (https://en.wikipedia.org/wiki/Heron%27s_formula)
This implies calculating the distance between every 2 points, as in:
    AB = sqrt((xA - xB)^2 + (yA-yB)^2)

And then apply Heron's formula:
    area = sqrt(p * (p-AB) * (p-BC) * (p-AC)), where p = (a+b+c)/2

However, this is quite computationally-expensive and sometimes inexact as it requires 4 square roots to be calculated and uses floating point number representation.
There exists a cheaper and more exact approach, based on the geometrical interpretation of the cross products of 2 vectors (more info on this here: https://github.com/sahilbansal17/Competitive_Coding/blob/master/Algorithms/Computational-Geometry/Lines/point_orientation.cpp)
We can view a triangle as "half of a paralelogram", so if pArea = cross product, then tArea = abs(pArea)/2 (because pArea is signed as explained in the link above)
So, in the end:
    tArea = abs((xB - xA)*(yC - yA) - (xC - xA)*(yB - yA))/2

This is a much more computationally-cheaper approach, as it doesn't involve any work with real numbers (only eventually in the end if the cross product is odd)
The implementation is very similar to the point orientation problem as it uses the same concepts.
Test: A(2, 1)
      B(4, 3)
      C(3, 5)

      area: 3
**/

#include <bits/stdc++.h>

using namespace std;

struct point {
    int x, y;
};

int main() {
    point A, B, C;
    cout << "A: "; cin >> A.x >> A.y;
    cout << "B: "; cin >> B.x >> B.y;
    cout << "C: "; cin >> C.x >> C.y;
    cout << '\n';
    float area = abs((B.x - A.x)*(C.y - A.y) - (C.x - A.x)*(B.y - A.y))/2;

    cout << "area: " << area;
}
