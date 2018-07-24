#include<bits/stdc++.h>
using namespace std;

void PowerSet(string array, int index = -1, string subset = ""){
	
	// base case
	if(index == array.size())
		return;

	cout<<"{"<<subset<<"}"<<endl;
	
	for(int i = index + 1; i < array.size(); i ++){
		subset = subset + array[i];
		// calling the PowerSet function with current value of i in outer for loop
		// as index and thus this will call recursion upto n levels. (depth of recursion)
		PowerSet(array, i, subset);
		// now when the subsets begining with current element (so we are in the last recursive call)
		// in the outer loop are printed
		// due to recursive calls, we will delete the last character (element) so as to generate 
		// other subsets with another element as prefix set.
		subset.erase(subset.size()-1);
	}
	return;
}

int main(void){
	int n;
	cout<<"Enter the number of elements\n";
	cin>>n;
	int array[n];
	cout<<"Enter the array elements\n";
	for(int i = 0; i < n; i++) cin>>array[i];
	//using string stream to convert the array to string to ease the appending operations.
	ostringstream os;
	for(int i : array)
		os << i;
	string str(os.str());

	PowerSet(str);
	return 0;
}
/*
Time complexity for above algorithm is O(2^n).
We are doubling the number of operations everytime we split at a particular indfex value.
Also, since in the subset we can include an element or not and we have thus 2 choices for each
and thus the time complexity wll be 2*2*2*2.....*2 = 2^n;
*/