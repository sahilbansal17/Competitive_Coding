#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(void){

	cout<<"Decreasing Order in Priority Queue (default case)"<<endl;
	// Declaring a priority queue which stores integers.
	priority_queue<int> q;
	/* By default the elements in priority queues are sorted in 
	   decreasing order and thus making it possible to find and remove the largest
	   element in the queue.
	*/
	// Insertion takes O(logn) time.

	// Let's add some elements to the priority queue
	q.push(3);
	q.push(5);
	q.push(7);
	q.push(2);

	// top() function returns the topmost (on the head) of queue
	// top function takes O(1) time.
	cout<<q.top()<<endl;

	// pop() function is used to Dequeue an element and
	// Removal takes O(logn) time as well.
	q.pop();
	cout<<q.top()<<endl;
	q.pop();
	cout<<q.top()<<endl;
	q.pop();
	q.push(6);
	cout<<q.top()<<endl;
	q.pop();
	cout<<q.top()<<endl;

	// Enqueuing some more elements
	q.push(9);
	q.push(17);
	q.push(7);

	cout<<"Current size of our Queue is"<<endl;
	cout<<q.size()<<endl;

	cout<<endl;
	// Similarly Let's demonstarte for Priority Queue in increasing order
	// Note as said above the default is decreasing order but you can change it
	// by changing the declaration of our priority_queue

	cout<<"Increasing Order in Priority Queue"<<endl;

	priority_queue<int, vector<int>, greater<int> > pq;

	// All the functions and time complexities are same.
	//Let's add some elements!
	pq.push(2);
	pq.push(1);
	pq.push(4);

	// Let's print the topmost value (on the head)
	cout<<pq.top()<<endl;

	// pop function removes the element
	pq.pop();
	cout<<pq.top()<<endl;
	pq.pop();
	cout<<pq.top()<<endl;
	pq.pop();
	pq.push(6);

	cout<<"Current size of our queue is\n";
	cout<<pq.size()<<endl;

	return 0;
}
