//Name:Anuj Goyal
//Email:anujg935@gmail.com

//This program is to min_priority queue
#include<iostream>
#include<vector>
using namespace std;

//Min priority queue class
class PriorityQueue {
	//vector of type integer pq
	vector<int> pq;

	public :
	
	//getSize() function Return the size of priorityQueue - no of elements present
	int getSize() {
		return pq.size();
	}
	
	//isEmpty() function returns boolean value if the queue is empty or not
	bool isEmpty() {
		//pq.size() ==0 returns true and false accordingly
		return pq.size() == 0;
	}
	
	//getMin() function returns the element of minimum priority
	int getMin() {
		//if Priority Queue is empty return 0
		if(isEmpty()) {
			return 0;		
		}
		return pq[0];
	}
	
	//insert() function inserts the element in the queue
	void insert(int element) {
		//enters the element in the vector pq
		pq.push_back(element);
		
		// getting the child index i.e last index
		int childIndex = pq.size() - 1;
	
		//loop to iterate over and set the element to its correct position
		//i.e the minimum value element to first place
		while(childIndex > 0) {
			//getting the child index from parent index 
			//for e.g if i is the parent-index than child-index = 2*i+1
			int parentIndex = (childIndex - 1) / 2;
			
			//if the element at childIndex is less than element at parentIndex
			//than swp the values of elements at parent and child Index
			if(pq[childIndex] < pq[parentIndex]) {
				int temp = pq[childIndex];
				pq[childIndex] = pq[parentIndex];
				pq[parentIndex] = temp;
			}
			//if the above is not the case than the element is at the correct position
			//so break the loop
			else {
				break;
			}
			//updating the childIndex to parentIndex for further iteration until the element is at correct position
			childIndex = parentIndex;
		}

	}
	
	//returns the element to be removed from the queue
	//and removes the element with the least priority as it's minPriority queue
	int removeMin() {
		
		// if Priority Queue is empty than return 0
		if(isEmpty()) {
			return 0;		
		}
		
		//the element to be deleted is at the first index of pq
		//so saving the value in ans value so as to return it
		int ans = pq[0];
		
		//putting the last element of the vector pq to the 0th index
		pq[0] = pq[pq.size() - 1];
		//deleting the element that we have put on the 0th index 
		pq.pop_back();

		// down-heapify
		//initialy parent index is 0
		int parentIndex = 0;
		
		//finding the left and right child index from parent index
		//for e.g if 0th is the parentIndex than 1 is leftChilIndex and 2 is rightChildIndex
		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndx = 2 * parentIndex + 2;
		
		//loop to iterate over and set the element to its correct position
		//i.e  the element that we put on the 0th index to it correct position
		while(leftChildIndex < pq.size()) {
			
			//minIndex element that is to be put on correct position
			int minIndex = parentIndex;
			
			//in below 2 if statement we find the minimum of the 3 elements i.e minimum of left,right an th parent index
			//and get the value of the min element in minIndex
			if(pq[minIndex] > pq[leftChildIndex]) {
				minIndex = leftChildIndex;
			}
			if(rightChildIndx < pq.size() && pq[rightChildIndx] < pq[minIndex]) {
				minIndex = rightChildIndx;
			}
			//if minIndex is equal to parenIndex than there is no need of shifting the element 
			// therefore break the loop
			if(minIndex == parentIndex) {
				break;
			}
			
			//in below 3 lines of code swap the element at minIndex with the parentIndex
			int temp = pq[minIndex];
			pq[minIndex] = pq[parentIndex];
			pq[parentIndex] = temp;
			
			
			//in the below 3 lines of code updating the parentIndex ,leftChildIndex,and rightChildIndex 
			//for next iteration of the loop 
			parentIndex = minIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndx = 2 * parentIndex + 2;
		}
		return ans;
	}

};

//main function that drives the program
int main()
{
	
	//creates min-priority queue p
	PriorityQueue p;
	
	//insert 6 element in the priority queue
	p.insert(100);
	p.insert(10);
	p.insert(15);
	p.insert(4);
	p.insert(17);
	p.insert(21);
	p.insert(67);
	
	cout<<"Size of priority queue is :"<<p.getSize()<<endl;
	cout<<"Minimum Element is :"<<p.getMin()<<endl;
	
	while(!p.isEmpty()){
		cout<<"Deleted : "<<p.removeMin()<<endl;
	}
	
	cout<<"Size of priority queue after deleting every element is : "<<p.getSize()<<endl;
}
