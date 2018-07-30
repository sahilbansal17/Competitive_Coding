// Name : Shivam Singhal
// Email ID : shivamsinghal0610@gmail.com

// Cuckoo hashing algorithm to improve worst case time for lookup in a table
// based on multiple-choice hashing and relocation hashing

#include <iostream>
using namespace std;

int indexTable[2];
int n = 10;

// function declaring hash functions that we use to calculate 2 location choices for keys
int hashChoice(int val, int key, int maxval)
{
	if(val == 1)
		return key % maxval;
	else
		return (key / maxval) % maxval;
}

void insertHash(int key, int tableID, int count, int cuckooTable[][11]){
	// condition for cycle detection 
	if (count == n)
    		return;
	// checking if key is already present at any of the positions
	for (int i = 0; i < 2; i++){
		indexTable[i] = hashChoice(i+1, key, n + 1);
		if (cuckooTable[i][indexTable[i]] == key)
			return;
		}
	// now we check if an old key is placed at this position. We use relocation hashing
	// in case old key is present, i.e., we place the new key here and relocate the old key 
	// to a vacant position
	if (cuckooTable[tableID][indexTable[tableID]] != 0){
    		// temporarily storing old key
		int old = cuckooTable[tableID][indexTable[tableID]];
		// placing new key at this position
		cuckooTable[tableID][indexTable[tableID]] = key;
		// relocating old key
		insertHash(old, (tableID+1) % 2, count + 1, cuckooTable);
	}
	else
    		//placing the new key in its position 
    		cuckooTable[tableID][indexTable[tableID]] = key;
}

void cuckooHashing(int a[], int cuckooTable[][11]){
	int count = 0;
	// we place each element in the first hash table using a hash function 
	for (int i = 0; i < n; i++){
		insertHash(a[i], 0, count, cuckooTable);
		count = 0;
	}
}

int main(){
	cout << "Number of elements : " << n << endl;
	cout << "Please enter elements." << endl;
	int a[n];
	// declaring cuckooTable for storing elements and initialising to 0
	int cuckooTable[2][11] = {0};
	for(int i = 0; i < n; i++)
		cin >> a[i];
	cout << "Array elements are : " << endl;
	for(int i = 0; i < n; i++)
		cout << a[i] << " "; 
	cout << endl;
	// function to implement cuckoo hashing
	cuckooHashing(a, cuckooTable);
	cout << "Cuckoo Hash tables : " << endl;
	for (int i=0; i < 2; i++){
		for (int j = 0; j <= n; j++){
        			if (cuckooTable[i][j] == 0)
            			cout << "_" << " ";
            		else
            			cout << cuckooTable[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

// In cuckoo hashing technique, we give a key two choices where it can be stored. (multiple-choice hashing)
// Now, it may happen that both these choices are already pre-occupied so we use the cuckoo technique of 
// relocation and insert the new key into the table while pushing the previous keys to a different location.

// Worst case time complexity for lookup : O(1)