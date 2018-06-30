#include<bits/stdc++.h>
using namespace std;

void ReversePriorityQueue(priority_queue<int> );

int main(void){

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

	cout<<"The size of our queue now is"<<endl;
	cout<<q.size()<<endl;

	cout<<endl;
	return 0;
}
