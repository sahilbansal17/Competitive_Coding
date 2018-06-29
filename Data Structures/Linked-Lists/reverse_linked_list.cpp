// Name: Anuj Goyal	
// Email-id: anujg935@gmail.com
// This program describes the 4 ways of revesing the linkedList
//3 are the recursive ways and 1 is iterative way
#include<iostream>
using namespace std;
//Node class defines the structure of linkedList
class Node{
	public:
		int data;
		Node * next;
		Node(int data){
			this->data = data;
			this->next=NULL;
		}
};
//take inputs from the user until user enters -1
//returns the head of the linkedList
Node* takeInput(){
	int data;
	cin>>data;
	Node *head =NULL;
	Node*tail =NULL;
	while(data!=-1){
		Node*n=new Node(data);
		if(head==NULL){
			head = n;
			tail = n;
		}	
		else{
			tail->next =n;
			tail = tail->next;	
		}	
		cin>>data;
	}
	return head;
} 
//This function prints the linkedList
void print(Node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
   }
   cout<<endl;
}
//Recursive approaches :-----------------------------------------------------------------------------------------------
//This is the 1st recursive approach to reverse LL----------------------------------------------------
Node *reverseLinkedListRecSimple(Node *head)
{
	//BaseCase for Recursion
	if(head ==NULL || head->next ==NULL){
	    return head;
	}
	//Calling Recursion On smaller Input
	//storing the head of reversed LL in small
	Node *small=reverseLinkedListRecSimple(head->next);
	//Now traversing through the linked list using temp
	//This traversing is to to attach the first element with 
	//the obtained answer from the recursion 
	Node*temp = small;
	while(temp->next!=NULL){
	    temp=temp->next;
	}
	head->next =NULL;
	temp->next = head; 
	//returning the head of reversed linked list  
    return small;
}
//This is the 2nd recursive approach to reverse LL---------------------------------------------------------
//This is a complicated One but will get idea of many concepts
//This is a double node method
//Pair Class is defined to maintain both the head and tha tail of the linkedlist
//this will reduce the time complexity
class Pair{
	public:
		Node *head;
		Node *tail;
};
//This a helper function to reverseLinkedListRecUsingPairClass Function
//this returns the object of Pair class
Pair reverseLinkedListRecUsingPairClassHelper(Node *head)
{
	//BaseCase for Recursion
    if(head ==NULL || head->next ==NULL){
    	Pair ans;
    	ans.head = head;
    	ans.tail =head;
    	return ans;
	}	
    //Calling Recursion On smaller Input
	//storing the head of reversed LL in small
	Pair small=reverseLinkedListRecUsingPairClassHelper(head->next);
    //attach the first element with 
	//the obtained answer from the recursion
	small.tail->next =head;
	head->next =NULL;
	//Making an object of Pair class to return that
	Pair ans;
	ans.head = small.head;
	ans.tail = head;
	return ans;
}
//Function that takes head of linkedList 
//Gives that head to the helper function 
Node* reverseLinkedListRecUsingPairClass(Node* head){
	Pair a =reverseLinkedListRecUsingPairClassHelper(head);
	//returns only the head of the linked list
	return a.head;
}
////This is the 3rd recursive approach to reverse LL -----------------------------------------------
//This easiest of above 2 approaches 
Node *reverseLinkedListRecBest(Node *head)
{
	//BaseCase for Recursion
    if(head ==NULL || head->next ==NULL){
    	return head;
    }  
    //Calling Recursion On smaller Input
	//storing the head of reversed LL in small
    Node *small=reverseLinkedListRecBest(head->next);  	
	//I above 2 methods there we find the need of finding 
	//address of the end of the reversed linked list 
	//but that address of the first element of the original ll
	//is stored in the head .So no need to traverse it .	
    Node*tail = head->next;
    tail->next = head;
    head->next =NULL;  
    return small;
}
//Iterative approach :-----------------------------------------------------------------------------------------------
//This is 4th approach to reverse linked lisr ---------------------------- 
Node* reverseLinkedListIterative(Node* head)
{
	//current node stores the current while traversing
	//prev node stores the previos node then current
	//nexto node stores 1 node above the current node	
	Node* current = head;
	Node* prev = NULL;
	Node* nexto =current->next;	
	//traversing through the list and making the current node points
	//to the previous node without loosing the address of any node
	//this loop breaks when the current gets equal to NULL
	//means that already the whole list is reversed	
	while(current!=NULL){
		current->next = prev;
	    prev = current;
	    current = nexto;
	    if(nexto!=NULL)
	      nexto = nexto->next;
	    else
	       break;
	}
	//prev stores the address of first element of reversed list 
	return prev;
}
int main(){	
	//takeInput() function takes the input from the user until user enters -1
	cout<<"Enter the linked list and give -1 to end list: ";
	Node *head =takeInput();
	cout<<"Input linkedList is : ";
	print (head);	
	//1st approach
	Node*a =reverseLinkedListRecSimple(head);
	cout<<"Reversed LL by 1st approach :";
	print (a);	
	//2nd approach
	Node *b =reverseLinkedListRecUsingPairClass(a);
	cout<<"Reversed LL by 2nd approach :";
	print(b);	
	//3rd Approach
	Node*c = reverseLinkedListRecBest(b);
	cout<<"Reversed LL by 3rd approach :";
	print(c);	
	//4th approach
	Node*d = reverseLinkedListIterative(c);
	cout<<"Reversed LL by 4th approach :";
	print(d);
	//above i reversed the same lnked list again and again
	//i.e reversed the list reversed by first aprroach and so on
	return 0;
}
//Approach 1----------
	//time complexity: O(n^2) because recursion take O(n) and traversing the list again takes O(n) therefore int total O(n^2)
	//Space Compleaxity:O(1)	
//Approach 2----------
	//time complexity: O(n) because recursion take O(n) and there is no need of traversing the list as in st approach
	//Space Compleaxity:O(1)
//Approach 3----------
	//time complexity: O(n) because recursion take O(n) and other than that some constant work is done only
	//Space Compleaxity:O(1)
//Approach 4----------
	//time complexity: O(n) because we are iteration only once throught the whle list
	//Space Compleaxity:O(1)
