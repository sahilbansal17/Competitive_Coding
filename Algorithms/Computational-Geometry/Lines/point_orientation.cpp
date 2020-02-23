/**
We are given three points A, B, C in a plane. We have to determine if A, B, C are oriented:
    - clockwise
    - counterclockwise
    - collinear

In order to use the technique I am going to present efficiently, we should familiarise ourselves with the concept of cross product (https://en.wikipedia.org/wiki/Cross_product)

First, let's solve the problem for the case where A = (0, 0). I will be using -AB- to denote the oriented segment AB.

-AB- and -AC- will have a common point in (0, 0), so their cross product would be: -AB- * -AC- = det ( xA  xB )
                                                                                                     ( yA  yB )

Geometrically speaking, this cross product will represent the signed area of (0, 0), B(xB, yB), C(xC, yC), and (B+C)(xB+xC, yB+yC).
If the cross product is positive, then -AB- will be oriented clockwise against -AC- => A, B, C will be oriented clockwise.
If it is negative, then -AB- will be oriented counterclockwise against -AC- => A, B, C will be oriented counterclockwise.
If it is 0, they are collinear.

Now, if A != (0, 0), it is sufficient to translate the two segments in order for them to have the origin of the axis as initial extremity.
let O be the origin. So, we should calculate: ()-OB- - -OA-) * (-OC- - -OA) = det ( xB-xA   xC-xA  )
                                                                                  ( yB-yA   yC-yA  )
So, the answer lies in the sign of the determinant above, as presented in the case A = (0, 0).
Although the coordinates in the implementation below are integers, the idea should also work for real numbers.
Test: A(2, 1)
      B(4, 3)
      C(3, 5)

      orientation: clockwise
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
    int det = (B.x - A.x)*(C.y - A.y) - (C.x - A.x)*(B.y - A.y);

    if(det > 0) cout << "orientation: clockwise";
    else if(det < 0) cout << "orientation: counterclockwise";
    else cout << "collinear";
}
