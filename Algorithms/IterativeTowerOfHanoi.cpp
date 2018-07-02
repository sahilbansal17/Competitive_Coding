//Name:Anuj Goyal
//Email:anujg935@gmail.com

//This program is to solve Tower Of Hanoi Iteratively
//This iterative program is using stack
#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdio.h>

using namespace std;

//This function checks if a given value is even, that is if the
//remainder is 0 then it is even, otherwise it is odd
bool checkEven(int n) {	
	bool x = false;
	if (n % 2 == 0) {
		x = true;
	}
	return x;
}

int diskcheck(int i, int d) {	
	int check;
	int begin = 1, up = 2;
	int totalmoves = (pow(2,d))-1;
	for (int k = 1; k<= d; k++) {
		for (int l = begin; l<=totalmoves; l = l + up) {
			if (i == l) {
				check = k;
			}
		}
		begin = begin * 2;
		up = up * 2;
	}
	return check;
}

//Return the peg we are on depending on the number of total moves remaining.
int number(int i, int disk, int totaldisks) {
 
	int w = 0;
	int up = 2;
	int begin = 1;
	for (int k = 1; k <=totaldisks;k++) {
		if (k==disk) {
			for (int x = begin; x<=i;x = x + up) {
				w++;
				if ((w == 3) && x != i) {
					w = 0;
				}
			}
		}
	begin = begin * 2;
	up = up * 2;
	}
	return w;
}

//This function will move a single disk from the
//top of the source stack passed in and move to the a destination stack (can be either of the remaining
//2 stacks)
void moveOne(char source, char destination) {	
	cout<<"Move from "<<source<<" to "<<destination<<endl;
}


void solveTower(int n, int moves, char source, char spare, char destination) {
	bool z = checkEven(n);	
	//If the number of disks is not even, this portion will run
	if (!z) {	
		//Run a for loop between 1 and total number of moves
		for (int i1 = 1; i1 <=moves;i1++) {	
			int check = diskcheck(i1,n);	
			int check1 = number(i1,check,n);
			bool x;
			x = checkEven(check);
			//Depending on the check1 values, if check1 is 1 this refers to peg A and so on. 
			//If the x is false then the corresponding if statements will run. If it is false this means
			//that a middle size disk is on top and we want to move that to the spare peg. Otherwise if
			//x is even then that means the bigger disk is on top and we want to move that to the
			//destination peg from peg A
			if (check1 == 1) {
				if (!x) {
					moveOne(source,destination);
				}
				else {
					moveOne(source,spare);
				}
			}
			if (check1 == 2) {
				//If x is false then move from spare peg (B) to destination peg because this means
				//a larger size disk on top of the spare
				if (!x) {
					moveOne(destination,spare);
				}
				//Otherwise we move from destination to spare because a smaller disk than the larger
				//disk is on the bottom
				else {
					moveOne(spare,destination);
				}
			}
			if (check1 == 3) {
				if (!x) {
					moveOne(spare,source);
				}
				else {
					moveOne(destination,source);
				}
			}
		}
	}
	//This portion runs if x is true, meaning it is even
	else {
		for (int i1 = 1; i1 <= moves; i1++) {
			int temp = diskcheck(i1,n);
			int check2 = number(i1,temp,n);
			bool x1 = checkEven(temp);
			if (check2 == 1) {
				//Smaller disk on top of source and bigger exists underneath so move
				//topmost disk to spare peg
				if(!x1) {
				moveOne(source,spare);
				}
				//Otherwise the largest disk is on top or a smaller disk exists under it
				//so we move to destination peg
				else {
				moveOne(source,destination);
				}
			}
			if (check2 == 2) {
				if(!x1) {
					moveOne(spare,destination);
				}
				else {
					moveOne(destination,spare);
				}
			}
			if(check2 == 3) {
				moveOne(destination,source);
			}
			else {
				moveOne(spare,source);
			}
		}
	}

}

//Main function that drives the program
int main() {
	bool q = true;
	int n;
	cout<<"Enter the number of disks: ";
	cin>>n;

	int totalmoves = (pow(2,n))-1;
	//Compared to the recursive version of the code, we need to have an extra parameter for the 
	//iterative code because we want the iteration to run for as many moves we have based on the number
	//of disks entered in the by user. With recursion the number of moves will decrement by 1 when 
	//a recursive call is made and will eventually reach a base case. The moves can be
	// calculated by the formula 2^n -1 where n is the number of disks entered by the user
	
	//Uses the last peg, peg C as the destination peg and this
	//assumes that the source peg is the first one, specifically peg A
	solveTower(n,totalmoves,'A','B','C');	
	return 0;
}
