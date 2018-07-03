//Name:Anuj Goyal
//Email:anujg935@gmail.com

//This program is to implement Stack data structure using arrays 
#include <iostream>
#include <climits>
using namespace std;

//template for generic program 
template <typename T>

//Stack class 
class Stack{
	//data of stack
	T *data;
	//stores the next index
	int nextIndex;
	//initial capacity of dtack
	int capacity;
	public:
		//constructor initializes private data members
		Stack(){
			capacity = 4;
			data = new T[capacity];
			nextIndex =0;
			
		}
		//return the number of elements present in my stack
		int size(){
			return nextIndex;
		}
		
		//checks if stack is empty or not
		bool isEmpty(){
			return nextIndex ==0;
		}
		
		//insert element
		void push(T element){
			//if capacity is full then allocate the array of double size
			//so there is no complication of size of stack
			if(nextIndex == capacity){
				int *newData = new T[capacity*2];
				for(int i=0;i<capacity;i++){
					newData[i]= data[i];
				}
				capacity *=2;
				delete []data;
				data = newData;
				data[nextIndex] = element;
				nextIndex++;
			}
			else{
				data[nextIndex] = element;
				nextIndex++;
			}
			
		}
		
		//delete the element
		T pop(){
			if(isEmpty()){
				cout<<"Stack is empty"<<endl;
				return 0;
			}
			nextIndex--;
			return data[nextIndex];
		}
		
		//access the element
		//returns the top element of stack
		T top(){
			if(isEmpty()){
				cout<<"Stack is empty"<<endl;
				return 0;
			}
			return data[nextIndex-1];
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
	cout<<s.size()<<endl;
	
	//isEmpty() function returns 0 for false
	cout<<s.isEmpty()<<endl;
	
	return 0;
}
