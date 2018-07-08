//Name:Anuj Goyal
//Email:anujg935@gmail.com

//This program is to implement Queue data structure using arrays 
#include<iostream>
using namespace std;

//template for generic program 
template <typename T>

//Queue class
class Quee{
	//data of the queue of type T
	T * data;
	//maintains the current size of the queue
	int size;
	//stores the next index on which element is to be inserted
	int nextIndex;
	//stores the first index from which the Queue starts
	int firstIndex;
	//initial capacity of the array
	int capacity;
	public:
		//constructor that initailizes the values of private data types
		Quee(){
			capacity =5;
			data = new T[capacity];
			firstIndex =-1;
			nextIndex = 0;
			size =0;
		}
		//returns the size of the queue
		int getSize(){
			return size;
		}
		//checks if the queue is empty or not
		bool isEmpty(){
			return size==0;
		}
		
		// enters the element to queue
		void enqueue(T element){
			//chexks if the existing array which makes the queue is full or not
			//if fount to be full then make another queue of double size 
			if(size == capacity){
				//made another array of twice size of prev array
				T *newData = new T[2*capacity];
				int j=0;
				//copied the existing elemnts to new array
				for(int i= firstIndex;i<capacity;i++){
					newData[j]=data[i];
					j++;
				}
				for(int i=0;i<firstIndex;i++){
					newData[j]=data[i];
					j++;
				}
				//deletes the previous array
				delete []data;
				//points data to new array
				data =newData;
				firstIndex= 0;
				nextIndex = capacity;
				//doubles the capacity
				capacity *=2;
				
			}
			//if queue is not full than entering element to queue
			data[nextIndex]=element;
			nextIndex = (nextIndex + 1) % capacity;
			if(firstIndex == -1){
				firstIndex =0;
			}
			size++;
		}
		//access the element
		//returns the element which is pushed first
		T front(){
			if(isEmpty()){
				cout<<"Queue is empty"<<endl;
				return 0;
			}
			else{
				return data[firstIndex];	
			}
			 
		}
		//Deletes the element from Queue
		T dequeue(){
			//cheks for if the Queue is empty
			if(isEmpty()){
				cout<<"Queue is empty"<<endl;
				return 0;
			}
			else{
				T temp = data[firstIndex];
				firstIndex = (firstIndex+1)%capacity;
				size--;
				if(size==0){
					firstIndex = -1;
					nextIndex = 0;
				}
				//returning the data of elemnt which is deleted
				return temp;
			}
			
		}
};

//main function that drives the program
int main()
{
	//created Queue q
	Quee<int> q;
	
	//Entering 6 elements into the queue i.e 10,20,30,40,50,60
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);
	
	//getting the element of queue i.e 10
	cout << q.front() << endl;
	
	//deletes 3 elements from the queue i.e 10,20,30
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	
	//returns the size of the queue i.e 3
	cout << q.getSize() << endl;
	
	//checks if the queue is empty or not returns 0 for false
	cout << q.isEmpty() << endl;
	return 0;
}
//Time And Space Complexities

//Time complexity of enqueue() function:-
		//the time complexity is O(n) when the array is allready full then there is complete copying of whole existing array.
		// also time complexity is O(1) when the array is not full.
//Space Complexity of enqueue() function:-
		//Space complexity is O(n) as we are allocating an array of double size in case of the array is full.

