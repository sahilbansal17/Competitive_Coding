#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

// all comments of cout are used for the purpose of debugging the code
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int T, D, len; 
	string s;
	cin >> T;

	for(int caseNo = 0 ; caseNo < T ; caseNo ++){
		cin >> D; // max amount of possible shield
		cin >> s;
		len = s.length();

		int currentDamage = 0, newDamage, pow_2 = 1;
		int steps = 0; // steps is the min swaps required  
		// find the current damage 
		for(int str_ind = 0; str_ind < len ; str_ind ++){
			if(s[str_ind] == 'S')
				currentDamage += pow_2; // S for shoot
			else if(s[str_ind] == 'C')
				pow_2 *= 2; // C for change
		}

		// cout << "Case #" << caseNo + 1 << ": " << currentDamage << "\n";


		newDamage = currentDamage ; // to initialize
		bool done = false; // when the damage of robot is less than equal to D
		if(newDamage <= D)
			done = true; // no need for further computations
		while(!done){
			int countC = 0; // count of C before the 1st S following a C
			int lastS = len;
			// find index of last S following a C so that damage can be reduced significantly
			for(int str_ind = 0 ; str_ind < len - 1 ; str_ind ++){
				if(s[str_ind] == 'C' && s[str_ind + 1] == 'S'){
					countC ++; // crucial line of code
					lastS = str_ind + 1;
					// break; // we need the last S and not the first S
				}
				else if(s[str_ind] == 'C'){
					countC ++ ; // helpful to calculate updated damage value
				}
			}
			// cout << "Case #" << caseNo + 1 << ": " << lastS << "\n";
			if(lastS == len)
				done = true; // no possible swaps 
			else{
				for(int back_trace = lastS - 1; back_trace >= 0; back_trace --){
					if(s[back_trace] == 'S')
						break; // max swaps for this S done 
					else{
						swap(s[back_trace], s[back_trace + 1]); // swap C with following S
						countC --; // one C is now after this S
						newDamage = currentDamage - pow(2, countC); // updated damage
						currentDamage = newDamage ; // crucial line of code
						steps ++;
						// cout << "Case #" << caseNo + 1 << ": " << newDamage << "\n";
					}
					if(newDamage <= D){
						done = true; 
						break;
					}
				}
			}
		}
		// cout << "Case #" << caseNo + 1 << ": " << newDamage << "\n";
	
		// done could be made true either by exhausting all swaps or actually reducing damage to atmost D
		if(newDamage <= D)
			cout << "Case #" << caseNo + 1 << ": " << steps << "\n";		
		else
			cout << "Case #" << caseNo + 1 << ": " << "IMPOSSIBLE" << "\n";
	}
	return 0;
}