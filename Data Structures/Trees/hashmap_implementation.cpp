//  Name: Bhawana
//  Email_id: bhawana053@gmail.com

//  Hashmap Implementation: This program focuses on how insertion, searching and deletion works in a hashmap internally. 

#include <string>
#include<iostream>
using namespace std;
// user can specify the data type(V) of value 
template <typename V>
class MapNode {
	public:
		string key;
		V value;
		MapNode* next;

		MapNode(string key, V value) {
			this->key = key;
			this->value = value;
			next = NULL;
		}

		~MapNode() {
			delete next;
		}
};

template <typename V>
class OurMap {

//  MapNode Object to hold key-value pairs
	MapNode<V>** buckets;

//gives the size of hashmap (number of key-value pair present in the map)
	int count; 

	 //define capacity of buckets
	int num_buckets;

	public:

	OurMap() {
	 //initially no key value pair is present
		count = 0;

		// creating a Buckets of size 5 ( you can change the size)
		num_buckets = 5; 

		buckets = new MapNode<V>*[num_buckets]; 

		for (int i = 0; i < num_buckets; i++) {
		  //Dynamically initializing buckets to NULL 
			buckets[i] = NULL;                  
		}
	}

	~OurMap() {
	// Destructor for freeing the memory after we are done 

		for (int i = 0; i < num_buckets; i++) { 
			delete buckets[i];
		}
		delete [] buckets;
	}

	//function to return size of our hashmap
	int size() {   
		return count;
	}
	private:
	//function to find bucket_Index for a key
	int getbucket_Index(string key) {   
		int hash_code = 0;


		//for any number/string of the form "abc" its hash_code is calculated using formula : a*p^2 + b*p+ c*p^0. 
		//where p is any prime number. (prime number is chosen so as to have a good distribution)
		//to avoid overflow in hash_code we will use compression function which is simply (a*p^2 + b*p+ c*p^0)%bucket size.
		//And we know that (a*b*c)%n =((a%n)*(b%n)*(c%n))%n;


		int current_coeff = 1;
		for (int i = key.length() - 1; i >= 0; i--) {
			hash_code += key[i] * current_coeff;

			//compress so that hash_code may not exceed range of int
			hash_code = hash_code % num_buckets; 

			//37 is the chosen prime number here. u can choose any other 

			current_coeff *= 37;              
			//compress  so that current_coeff may not exceed range of int

			current_coeff = current_coeff % num_buckets; 
		}
		 //compression function so that result may not exceed range of int
		return hash_code % num_buckets;   
	}
	public:

	//function to get value of a key
	V getValue(string key) {       
		int bucket_Index = getbucket_Index(key);
		MapNode<V>* head = buckets[bucket_Index];

		while (head != NULL) {
			if (head->key == key) {
				return head->value;
			}
			head = head->next;
		}

		return 0;
	}
	 //function to insert a key-value pair
	void insert(string key, V value) {       
		int bucket_Index = getbucket_Index( key);
		MapNode<V>* head = buckets[bucket_Index];
		while (head != NULL) {
			if (head->key == key) {
				head->value = value;
				return;
			}
			head = head->next;
		}
		head = buckets[bucket_Index];
		MapNode<V>* node = new MapNode<V>(key, value);
		node->next = head;
		buckets[bucket_Index] = node;

		//increment count after inserting a key-value pair
		count++;                      
	}

	//function for removing a key and returning its value
	V remove(string key) {                   
		int bucket_Index = getbucket_Index(
			key);
		MapNode<V>* head = buckets[bucket_Index]; 
		MapNode<V>* prev = NULL;
		while (head != NULL) {

    //move head until required key is not found		
				if (head->key == key) {               
				if (prev == NULL) {
					buckets[bucket_Index] = head->next;
				} else {
					prev->next = head->next;
				}
				V value = head->value;
				head->next = NULL;
				delete head;
	  //decrement size of hash map	
		count--;       
				return value;
			}
			prev = head;
			head = head->next;
		}
		return 0;
	}

};
int main()
{

	OurMap<int> mp;
			 mp.insert("abc",1);
			 mp.insert("def",2);
			 mp.insert("xyz",67);
			cout<<"size of map is "<<mp.size()<<"\n";
			cout<<"value of string abc is "<<mp.getValue("abc")<<"\n";
			cout<<"Removing key abc from the map and printing value of removed key "<<mp.remove("abc")<<"\n";
			cout<<"After removal size of map is "<<mp.size();
	return 0;
}
	
	
	
	
	
	
// Time and space Complexity

	//FOR INSERTION
//From the above code, it is clear that, insert operation in hashmap requires :

//Step 1. Computing hashcode of key, 

//Step 2. Calculating array index/bucket from hashcode which takes O(l) time where l is length of key and then, 

// Step 3. With the help of index calculated, directly jump to that index/bucket. 

//Step 4. Now, each and every element in the bucket is scanned sequentially to see, is there any 
 //         key-value pair present, which has the same key we are trying to put in. 
   //          If key-value pair is found, which has same key then instead of storing 
   //            new entry / key-value pair, it simply replace value stored against key.

         //        If no matching key is found then it will go till end of the list and create a new key-value
            //      pair at the end. {O(n) time }

//So, ONLY COSTLY OPERATION WHAT WE SEE HERE IS ITERATING THE LINKED LIST AFTER GETTING THE BUCKET OR ARRAY INDEX.
 
//SO Complexity of Hashmap insert is :

//1. O(1)[BEST CASE] with assumption that key-value pairs are well distributed across the buckets.It means hashcode implemented is good.
//2. O(n) [WORST CASE] if all pairs are placed in one bucket,because insert operation has to scan each key inside the bucket.


// FOR SEARCH AND DELETE
// Hashmap search requires:
//Step 1. Calculating array index/bucket from hashcode which takes O(l) time where l is length of key and then, 
// Step 3. With the help of index calculated, directly jump to that index/bucket. 
//Step 4. Now, a linear search will be performed for Key look-up.

//So, ONLY COSTLY OPERATION WHAT WE SEE HERE IS ITERATING THE LINKED LIST AFTER GETTING THE BUCKET OR ARRAY INDEX.
 
//Complexity of Hashmap search/delete:

//1. O(1)[BEST CASE] with assumption that key-value pairs are well distributed across the buckets.
//2. O(n) [WORST CASE] if all pairs are placed in one bucket, because search/delete operation has to do linear search in bucket for Key look up,
//since all key-value pair are placed in one bucket

//Now talking about AVERAGE CASE
//Hahmap is said to be O(1) average and amortized case compleixty because:
//1.It is very rare that many items will be hashed to the same key [if you chose a good hash function ].
//2.The rehash operation, which is O(n), can at most happen after n/2 operations, which are all assumed O(1): Thus when you sum the average time
// per operation, you get : (n*O(1) + O(n)) / n) = O(1)

// Note 1:
// Rehashing is:
//Build a second table twice as large {generally} as the original 
//and rehash there all the keys of the original table. 

// Note 2:
//HASHMAP INSERT,SEARCH,DELETE ARE "AMORTIZED" O(1) AND NOT REAL O(1) because
//It's impossible to know in advance how many collisions you will get with your hash function, as well as things like needing to resize.
//This can add an element of unpredictability to the performance of a hash table, making it not true O(1) 


//Space Complexity : O(n) where n is size of hashmap
	

