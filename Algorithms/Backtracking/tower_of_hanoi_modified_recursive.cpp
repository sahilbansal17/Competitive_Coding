//Name:Anuj Goyal
//Email:anujg935@gmail.com

//This program is to solve Tower Of Hanoi recursively
//also with added recursion that there 
//can be no direct move from Source to destination

//Rules 
//1. Only one disk can be moved at a time.
//2. No disk may be placed on top of a smaller disk.
//3. The output should contain the necessary moves.
//4. The total number of disks may be even or odd.
//5. Implementation should be recursive.
//6. No direct movement from source to destination without using auxiliary peg

#include <iostream>
using namespace std;

//this function returns the total number of steps tthat takes place
int numOfMoves( int num_disks )
{
	//base case for recursion
    if( num_disks == 1 ) 
		return 2 ;
	//recursion is called
    else 
		return 3 * numOfMoves( num_disks-1 ) + 2 ;
}

// C recursive function to solve tower of hanoi puzzle
//in this program nn direct move is made from source to destination
//in this towerOfHanoi() function there are 4 parameters
//first is number of disks,2nd ,3rd and 4th are source,destination and auxiliary respectively. 

//The solution involves the following steps:
//1.Move n-1 disks from peg 1 to peg 3 (requires Sn-1 steps)
//2.Move the nth disk from peg 1 to peg 2 (requires 1 step)
//3.Move n-1 disks from peg 3 to peg 1 (requires Sn-1 steps)
//4.Move the nth disk from peg 2 to peg 3 (requires 1 step)
//5.Now it takes Sn-1 steps to move the remaining disks from peg 1 to peg 3.

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    //base case for recursion
    //i.e when the number of disks is zero there is no move required
    if (n == 0)
	{
		return;
	}
	//recursion call on n-1 disks to move from source to destination
    towerOfHanoi(n-1, from_rod, to_rod, aux_rod);
    //move n'th disk from source to auxiliary peg
    cout<<" Move disk from rod "<<from_rod <<" to rod "<< aux_rod<<endl;
    //recursion call on n-1 disk's to move from destination to source peg
    towerOfHanoi(n-1, to_rod, from_rod, aux_rod);
    //move n'th disk from auxiliary to destination peg
    cout<<" Move disk from rod "<<aux_rod <<" to rod "<< to_rod<<endl;
    //recursion call on n-1 disk's to move from source to destination peg
    towerOfHanoi(n-1, to_rod, from_rod, aux_rod);
}

int main()
{
	int n = 3; // Number of disks
	towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
	
	cout<<"Total number of moves that takes place:"<<numOfMoves(3)<<endl;
	return 0;
}

//Time and Space Complexity

	//Time Complexity:-
		//for above towerOfHanoi() function we have to call 3 recursive calls and some constant amount of work 
		//so we get the following reccurrence relation i.e T(n) = 3T(n-1) +k 
		//and reom above recurrnce relation after solving this we get a time complexity of 3^n(i.e 3 to the power of n).
		
	//Space Complexity:-
		//it requires constant amount of space 
		//therefore,space complexity is O(1).

