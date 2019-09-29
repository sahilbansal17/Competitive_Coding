#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

// all comments of cout are used for the purpose of debugging the code
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T, N, v;
	cin >> T;

	for(int caseNo = 0 ; caseNo < T ; caseNo ++){
		cin >> N;

		// make a vector of pairs, first of pair is the value,
		// and second tells whether its index is odd or even
		bool even = true; // 1st index is 0, which is even

		vector < pair< int, int> > V; 
		for(int index = 0 ; index < N ; index ++){
			cin >> v;
			V.push_back(make_pair(v, even));
			even = !even; 
		}

		// sort this vector of pair
		sort(V.begin(), V.end());

		/*
		for(int index = 0 ; index < N ; index ++){
			cout << V[index].first << " " << V[index].second << "\n";
		}
		*/
		
		// now find the first element whose index's parity (odd/even) is not matching 
		// with its actual parity in the sorted vector 

		int firstUnmatchedIndex = -1;
		bool ok = true; 

		even = true; // starting from 0th index 
		for(int index = 0 ; index < N ; index ++){
			int increment = 0; // all those elements which have same value
			int countZero = 0, countOne = 0;
			while(index + increment < N && V[index + increment].first == V[index].first){
				if(V[index + increment].second == 0)
					countZero ++;
				else
					countOne ++;
				increment ++;
			}
			// case when no elements with the same value 
			if(increment == 1){
				if(V[index].second != even){
					ok = false;
					firstUnmatchedIndex = index;
					break; 
				}
				even = !even;
			}
			else{
				// cout << "I:" << increment << "\n";
				// cout << "even: " << even << "\n";
				// case 1 - need to match an even index value now
				if(even){
					// cout << "E:" << countZero << " " << countOne << "\n";
					// 3 cases when some changes occur
					if(countZero > countOne){
						// some zeroes remain unmatched 
						ok = false;
						firstUnmatchedIndex = index + 2*countOne;
						// even index value was expected at this index
						break;
					}
					else if(countZero < countOne - 1){
						// some ones remain unmatched
						ok = false;
						firstUnmatchedIndex = index + 2*countZero + 1;
						// odd index value was expected  
						break;
					}
					else if(countZero == countOne - 1){
						// prefect match, but need to accept odd index value next
						even = !even;
					}
				}
				else{
					// cout << "O:" << countZero << " " << countOne << "\n";
					// case 2 - need to match an odd index value now
					if(countOne < countZero - 1){
						ok = false;
						firstUnmatchedIndex = index + 2*countOne + 1;
						break;
					}
					else if(countOne == countZero - 1){
						even = !even;
					}
					else if(countOne > countZero){
						ok = false;
						firstUnmatchedIndex = index + 2*countZero ;
						break;
					}
				}
				index += increment - 1; // -1 since automatically incremented once by loop
			}
			// cout << "\n" << index;
		}

		// update index accordingly
		if(ok)
			cout << "Case #" << caseNo + 1 << ": " << "OK" << "\n";		
		else
			cout << "Case #" << caseNo + 1 << ": " << firstUnmatchedIndex << "\n";
		
	}
	return 0;
}