#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	int num_pieces, height_iso_tri;
	cin >> num_pieces >> height_iso_tri;

	/*
		To get num_pieces, we need to make (num_pieces - 1) cuts
		parallel to x-axis. 
		Let the length of cuts between the triangle's sides be 
		b(1), b(2), ..., b(n-1)
		and the Heights from apex to the cuts be 
		h(1), h(2), ..., h(n-1)
		Then, we get the relation
		h(i) = b(i)*height_of_triangle

		Now, height of each of the isosceles triangles from the apex
		can be found out by taking their ratio with the height of bigger
		triangle,

		i.e. 

		0.5 * b(i) * h(i) = (i/n) * (h/2)

		giving us b(i) = (i * h)/(n * h(i))
	
		Thus, (h(i))^2 = (i * h^2)/n

		i.e. h(i) = sqrt(i/n) * h
	*/

	double reciprocal_sqrt_n = 1.0/sqrt(num_pieces);
	double h_times_reci_sqrt_n = height_iso_tri * reciprocal_sqrt_n;
	
	for(int cut_num = 1; cut_num < num_pieces; cut_num ++){
		double height_at_cut_num = sqrt(cut_num) * h_times_reci_sqrt_n;
		cout << setprecision(7);
		cout << fixed << height_at_cut_num << " ";
	}
}