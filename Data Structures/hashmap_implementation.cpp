//Name:Anuj Goyal
//Email:anujg935@gmail.com

//This program is to implement hashmap
#include<iostream>
#include<string>
using namespace std;

//MapNode class contains a string key which is the key of the hashmap
//and a value of type V and also the address of next MapNode
template <typename V> 
class MapNode{
	public:	
		string key;
		V value;
		MapNode *next;
		
		//constructor that initializes the value
		MapNode(string key,V value){
			this->key = key;
			this->value = value;
			next = NULL;
		}
		
		//destructor that deletes the entire map
		~MapNode(){
			delete next;
		}
};

//ourmap class that contains all the functions that we need to implement hashmap 
template <typename V> 
class ourmap{
	//MapNode<V>** buckets is a bucket pointer
	MapNode<V>** buckets;
	//count is the size of the each bucket
	int count;
	//numBuckets is the number of buckets
	int numBuckets;
	
	//below are the private tye functions that are the type of functions used by other public function
	private:
		//getBucketIndex() function takes the string as the input parameters 
		//and returns the index on which we need to insert the the element 
		//this is the function in which we need to find hashcode 
		int getBucketIndex(string key){
			//initialize the variable hashcode with zero and currentCode with one
			int hashCode=0;
			int currentCoeff =1;
			//iterating over the length of string to use the ascii value and find the hashcode 
			for(int i=key.length()-1;i>=0;i--){
				
				hashCode += key[i] * currentCoeff;
				hashCode =hashCode %numBuckets;
				//multiplying the currentCoeff with 37 which is a prime number for better homogenity of hashcode
				currentCoeff *= 37;
				currentCoeff = currentCoeff % numBuckets;
			}
			
			//returns hashCode % numBuckets to return the the hashcode with is a limits
			return hashCode % numBuckets;
		}
		
		//rehash function is used in collision handelling in the hashmap for better time complexity
		void rehash(){
			//a temp variable that points to the buckets
			MapNode<V>** temp = buckets;
			//expandng the size of the buckets to double size
			buckets = new MapNode<V>*[2*numBuckets];
			
			//initializing all elements of the buckets with NULL
			for(int i=0;i<2*numBuckets;i++){
				buckets[i] =NULL;
			}
			
			//oldBucketCount stores the size of old buckets
			int oldBucketCount = numBuckets;
			//reinitialize the count to 0
			count =0;
			//changing the numbuckets to double as the we increased the nmber of buckets
			numBuckets =  2*numBuckets;
			
			//in this for loop we are inserting each existing value in the new buckets of double size
			//we are accesing the old values from the temp in which we stored old buckets
			for(int i=0;i<oldBucketCount;i++){
				MapNode<V>* head = temp[i];
				while(head!=NULL){
					string key = head->key;
					V value = head->value;
					insert(key,value);
					head=head->next;
				}
			}
			
			//the following code is to delete the entire old hashmap
			for(int i=0;i<oldBucketCount;i++){
				MapNode<V>* head = temp[i];
				delete head;
			}
			delete [] temp;
		}
	public:
		
		//constructor that initializes all the variables 
		//initialy the count is 5
		//and all the elements in buckets in NULL
		ourmap(){
			count= 0;
			numBuckets =5;
			buckets = new MapNode<V>*[numBuckets];
			for(int i=0;i<numBuckets;i++){
				buckets[i] =NULL;
			}
		}
		//destructor that deletes the the entire hashmap
		~ourmap(){
			for(int i=0;i<numBuckets;i++){
				delete buckets[i];
			}
			delete [] buckets;
		}
		
		//size() function returns the size of hashmap
		int size(){
			return count;
		}
		
		//isEmpty() function is used to know if the hashmap is empty or not
		bool isEmpty(){
			return count==0;
		}
		
		//insert() function inserts the new element in the hashmap
		void insert(string key,V value){
			//getting the bucketIndex on which  we need to add new element using getBucketIndex() function
			int bucketIndex = getBucketIndex(key);
			//creating a head pointer that points buckets array 
			MapNode<V>* head = buckets[bucketIndex];
			
			//this while loop travers over the linked list to find if the element already exisit in the bucket or not
			//if no that gives the ened of the linked list where we can insert new node
			while(head!=NULL){
				if(head->key ==key){
					head->value = value;
					return;
				}
				head = head->next;
			}
			//inserting new elenment at the end of linkedList
			head = buckets[bucketIndex];
			MapNode<V>* node = new MapNode<V>(key,value);
			node->next = head;
			buckets[bucketIndex] = node;
			count++;
			
			//checks if the load factor is greater than 0.7 this means that if the more than 70% of buckets are filled
			//then we need to rehash to handle the collisions
			double loadFactor = (1.0)*count/numBuckets;
			
			if(loadFactor >0.7){
				rehash();
			}
		}
		
		//getValue() returns the value at given key of type string
		V getValue(string key){
			//getting the bucket index on which the element is present
			int bucketIndex = getBucketIndex(key);
			//head that points to a bucket of the bucketIndex
			MapNode<V>* head = buckets[bucketIndex];
			
			//iterating over entire linked list of the bucket to find the corresponding key
			while(head!=NULL){
				if(head->key ==key){
					//returns the value of the given key
					return head->value;
				}
				head = head->next;
			}
			//returns 0 if the element is not found
			return 0;
		}
		
		//remove() function removes the the element of given key
		V remove(string key){
			////getting the bucket index on which the element is present
			int bucketIndex = getBucketIndex(key);
			//head that points to a bucket of the bucketIndex
			MapNode<V>* head = buckets[bucketIndex];
			//a prev variable which is used in iteration of linkedList initializes to NULL
			MapNode<V>* prev = NULL;
			
			//iterating on entire linked list corresponds to a bucket 
			while(head!=NULL){
				//if the key is found
				if(head->key ==key){
					//if the key is at the staring or the first element of the linkedList
					//than buckets ponts to null as there is no elelent present in corresponding bucket
					if(prev=NULL){
						buckets[bucketIndex] = head->next;
					}
					//if the key is not at the starting of the linkedList than  next of previos node poins to the head->next
					//in this way deleting the the element
					//and break the loop as the element id already deleted
					else{
						prev->next = head->next;
						break;
					}
					
					//saving the value in value variable to be returned and deleted
					V value = head->value;
					//pointing the next to NULL as we made the destructor recursively 
					//if we don't do it than the entire linkeList will be destroyed
					head->next = NULL;
					//deleting the node from memeory
					delete head;
					//decreasing the value of the count
					count--;
					//returning the value of deleted node
					return value;
				}
				//iterating to next ext element if the key is not found
				prev = head;
				head = head->next;
			}
			
			//returns 0 if element is not found
			return 0;
		}
};
//main function that drives the program
int main()
{
	//creating a map of ourmap class of type ineger i.e the value of the hashmap is of type integer
	ourmap<int> map;
	
	//with this loop inserting 10 element in the the hashmap map
	//the element inserted are abc0,abc1,abc2,abc3 and so on upto abc9
	for(int i=0;i<10;i++){
		char c = '0' + i;
		string key = "abc";
		key = key +c;
		int value = i+1;
		map.insert(key,value);
	}
	
	cout<<"Size of hashmap is:"<<map.size()<<endl;
	cout<<map.isEmpty()<<endl;
	
	
}
