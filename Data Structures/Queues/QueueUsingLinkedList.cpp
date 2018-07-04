//Name:Anuj Goyal
//Email:anujg935@gmail.com

//This program is to implement Queue data structure using arrays 
#include<iostream>
using namespace std;

//template for generic program 
template <typename T>

//Node class for linkedList
class Node{
	public:
		T data;
		Node<T>*next;
		
		Node(T data){
			this->data = data;
			this->next = NULL;
		}
	
};

//template for generic program 
template <typename T>

//Queue class
class Quee{
	//head node of linkedList
	Node<T>*head;
	//tail node of linkedList
	Node<T>*tail;
	//maintains the size of queue
	int size;

	public:
		//Constructor that initializes the valures of private datatypes
		Quee(){
			head = NULL;
			tail = NULL;
			size =0;
		}
		//getSize() function return the size of the Queue
		int getSize(){
			return size;
		}
		//Checks for if the the Queue is empty or not
		bool isEmpty(){
			return size==0;
		}
		
		//inserts an element into the queue
		void enqueue(T element){
			//creates  a  newNode with data = element
			Node<T>*newNode = new Node<T>(element);
			//checks if the queue is empty or not
			if(size == 0){
				head = newNode;
				tail = newNode;	
			}
			else{
				tail->next = newNode;
				tail = newNode;
			}
			size++;
		}
		
		//access the element
		//returns the end element of queue
		T front(){
			if(isEmpty()){
				cout<<"Queue is empty"<<endl;
				return 0;
			}
			else{
				return head->data;	
			}
			 
		}
		//Deletes the last element from Queue
		T dequeue(){
			//cheks for if the Queue is empty
			if(isEmpty()){
				cout<<"Queue is empty"<<endl;
				return 0;
			}
			else{
				Node<T> *temp = head;
				T d = temp->data;
				head = head->next;
				delete temp;
				size--;
				//returning the data of end elemnt which is deleted
				return d;
			}
			
		}
};
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
	
	//getting the last element of queue i.e 60
	cout << q.front() << endl;
	
	//deletes last 3 elements from the queue i.e 40,50,60
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	
	//returns the size of the queue i.e 3
	cout << q.getSize() << endl;
	
	//checks if the queue is empty or not returns 0 for false
	cout << q.isEmpty() << endl;
	return 0;
}
