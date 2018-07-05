//Name:Anuj Goyal
//Email:anujg935@gmail.com

//This program is to implement Stack data structure using arrays 
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

//Stack class
class Stack{
	//head node of linkedList
	Node<T>*head;
	//size of stack
	int size;
	public:
		//constructor that initializes head and size
		Stack(){
			head =NULL;
			size=0;
		}
		
		//insert element
		void push(T element){
			//creates  a  newNode with data = element
			Node <T>*newNode = new Node<T>(element); 
			//pointing head to newNode
			newNode->next=head;
			head = newNode;	
			//increasing the size of stack as element is inserted
			size++;
		}
		
		//checks if stack is empty or not
		bool isEmpty(){	
			return size==0;
		}
		
		//access the element
		//returns the top element of stack
		T top(){
			if(isEmpty()){
				cout<<"Stack is empty"<<endl;
				return 0;
			}
			else
				return head->data;
		}
		
		//delete the element
		T pop(){
			if(isEmpty()){
				cout<<"Stack is empty"<<endl;
				return 0;
			}
			else{
				T temp = head->data;
				Node<T> *temp1 = head;
				head = head->next;
				delete temp1;
				size--;
				return temp;
				
			}
			
		}
		
		//return the number of elements present in my stack
		int getSize(){
			return size;
		}
		
		
};

//main function that drives the program
int main()
{
//created stack s
	Stack<int> s;
	//pushing 5 elements to stack
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	
	//getting the top element of stack i.e 50
	cout<<s.top()<<endl;
	
	//deletes the top 3 elements i.e 50,40,30
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	
	//returns the size of stack which is 2
	cout<<s.getSize()<<endl;
	
	//isEmpty() function returns 0 for false
	cout<<s.isEmpty()<<endl;
	
	return 0;
}
