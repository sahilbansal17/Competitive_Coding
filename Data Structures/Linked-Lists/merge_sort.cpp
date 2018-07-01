//Name:Anuj Goyal
//Email:anujg935@gmail.com

//This Program demostrate the mergeSort Algorithm in linkedlist
//In addition to this midpoint of linkedlist and merging 2 sorted LL are also demonstrated

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

//Midpoint Function
//this method is not ordinary one but a fast approach
//this method we maintain two nodes that is fast and slow
//swo increses one by one while fast increses with a gap of one node
//when the fast or fast->next becomes NULL then the slow node is at the mid point of the linkedlist
//I suggest everyone who is reading this function should dryrun this code atleast once
Node* midpointLinkedList(Node *head)
{
	//in this function i maintain 2 variables of Node type
	//slow and fast traverse through list  
	//fast traverse with the gap of 1
	Node *slow = head;
	Node*fast = head->next;
  
	while((fast!=NULL) && (fast->next!=NULL)){
		slow=slow->next;
		fast = fast->next->next;
  	}
  	//returns the midpoint i.e slow
	return slow;
}

//Merging two Sorted linkedList function
Node* mergeTwoLLs(Node *head1, Node *head2) {
	
	//head1 and head2 are the heads of 2 sorted linkelists
	//we maintain 2 extra variables fh and ft to traverse the whole list without loosing any Node
	
	Node *fh = NULL;
  	Node *ft =NULL;
  	
  	//this if-else condition initialize the fh and ft
  	if(head1->data >head2->data){
    	fh = head2;
    	head2=head2->next;
  	}
  	else{
    	fh = head1;
    	head1=head1->next;
  	}
  	ft = fh;
  
  	//this loop runs till the end of either head1 or head2 linkedlist
  	while(head1!=NULL && head2!=NULL){
    	if(head1->data < head2->data){
      		ft->next = head1;
      		ft = head1;
      		head1 = head1->next;  
    	}
  		else{
    		ft->next =head2;
    		ft=head2;
    		head2 = head2->next;
  		}    
  	}
  	
  	//this if-else condition runs when one of two linkedlist are fully traversed
  	//this if-else connects the other linked list which is not fully traversed
  	if(head1 == NULL){
    	ft->next = head2;
  	}
	else{
    	ft->next= head1;
  	}
  	return fh;
}

//MergeSort algorithm
Node* mergeSort(Node *head) {
	
	//base case for recursion
  	if(head ==NULL ||head->next==NULL){
    	return head;
  	}
  	
  	//finding the mid of linkedlist using midpointLinkedList() function
  	Node* mid = midpointLinkedList(head);
  	Node * temp = mid->next;
  	
  	//Breaking a single LL into two LLs one with head and other with temp as starting Node
  	mid->next = NULL;
  	
  	//Calling recursion  on two linked list and storing the heads of sorted LLs in a and b
  	Node* a=mergeSort(head);
  	Node* b=mergeSort(temp);
  	
  	//merging the 2 sorted LLs using mergeTwoLLs() function
  	Node*h=mergeTwoLLs(a,b);
  	
  	//Returning of sorted LL
  	return h;
}	




int main()
{
	//taking the input from the user and storing it's head in head variable
	//this take input function wille take inputs until user enters -1
	
	//we will take two input linkedlist so as to first sort them using mergesort
	//and then Demonstrate the mergeTwoLLs() function
	
	cout<<"Enter the element's of first linkedlist and give -1 to end list: ";
	Node *head1 =takeInput();
	cout<<"Enter the element's of second linkedlist and give -1 to end list: ";
	Node *head2 =takeInput();
	cout<<"Input linkedList is one is : ";
	print (head1);
	cout<<"Input linkedList is two is : ";
	print (head2);
	
	//Demonstrating the midpointLinkedList() function
	//Calling Mid Point Function and printing the midoint element to o/p
	Node *mid1 = midpointLinkedList(head1);
	cout<<"MidPoint Element of input LinkedList one is: "<<mid1->data<<endl;
	
	Node *mid2 = midpointLinkedList(head2);
	cout<<"MidPoint Element of input LinkedList two is: "<<mid2->data<<endl;
	
	//Calling mergeSort on both the linkedLists
	Node* sort1 =mergeSort(head1);
	Node* sort2 =mergeSort(head2);
	
	//printing the sorted linkedLists
	cout<<"Sorted linkeList one is: ";
	print(sort1);
	cout<<"Sorted linkeList two is: ";
	print(sort2);
	
	
	//Demonstrating the mergeTwoLLs() function
	//we will use the above two sorted linkedlist to demonstrate this function
	Node* merge =mergeTwoLLs(sort1,sort2);
	//printing the merged linkedlist
	cout<<"Merged LikedList is :";
	print(merge);
	
	return 0;
}

//Time And Space Complexities--------------------------------------------------------------

//midpointLinkedList() function :-------
	//Time Complexity: O(n) because traversing of linkedlist takes place but it's fast becuse loop runs only n/2 times
	//Space Complexity: O(1) only some constant space is required
//mergeTwoLLs() function :----------
	//Time Complexity: O(n) because 1 while loop is running and some exra constant work 
	//Space Complexity: O(1) only some constant space is required
//mergeSort() function :-----------
	//Time Complexity: O(nlogn) because 1calling recursion on 2 parts of LL anf further merging them
		//the recurrence relation of merge sort is 
		//T(n) = 2T(n/2) + O(n) /this recurrence relation is because in mergeSort() function we call  
		//recursion on two halfs of mergeSort of half of the size of linkeList
		//in additon to that O(n) is because of the we call mergeTwoLLs() function on two sorted Linkedlist
		//whose time complexity is O(n)

	//Space Complexity: O(1) only some constant space is required

