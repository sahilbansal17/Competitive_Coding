#include<bits/stdc++.h>
using namespace std;

int main()
{
	// distinct points given as input
	int n;
	// the x and y coordinates
       	int x, y;
	// count variable which keep count of number of points on each side.
       	int side1 = 0, side2 = 0;
	// taking number of distinct points
	cin >> n;
	while(n--)
	{
		// taking coordinates as input
		cin >> x >> y;
		// checking on which side it lies and then incrementing the counter.
		if(x>0)
			side1++;
		else
			side2++;
	}
	// if number of points on both sides >1 then we cannot have all points on same side after removing maximum 1 point.
	if( side1 > 1 && side2 > 1 )
		cout << "No";
	else
		cout << "Yes";
	return 0;
}
