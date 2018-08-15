//Given two (singly) linked lists, determine if the two lists intersect. Return the
//intersecting node. Note that the intersection is defined based on reference, not value. That is, if the
//kth node of the first linked list is the exact same node (by reference) as the jth node of the second
//linked list, then they are intersecting. 

//		Author - Aastha Aneja (Github handle - Aashu24)
//		Email - anejaaastha@gmail.com

import java.util.Scanner;

public class Intersection {

	public class linkedlist {

		// implementation of class Node (a node of the linked list)
		private class Node {

			// data of a node
			int data;

			// pointer to next node
			Node next;

			// constructor
			private Node(int data, Node next) {
				this.data = data;
				this.next = next;
			}
		}

		// head of linked list
		private Node head;

		// tail of linked list
		private Node tail;

		// size of linked list = no. of nodes in linked list
		private int size;

		// constructor
		linkedlist() {
			this.head = null;
			this.tail = null;
			this.size = 0;
		}

		// this function returns true if the linked list is empty
		public boolean isEmpty() {
			return this.size == 0;
		}

		// this function returns the size of the linked list
		public int size() {
			return this.size;
		}

		// this function adds a node in the beginning of the linked list
		public void addFirst(int data) {

			// declaring node to be added
			Node node = new Node(data, this.head);

			// this makes head of the linked list point to the new node
			this.head = node;

			// if the linked list is empty, we change the tail pointer as well
			if (this.isEmpty()) {
				this.tail = node;
			}

			// and increase the size of the linked list
			this.size++;
		}

		// this function adds a node in the end of the linked list
		public void addLast(int data) {

			// declaring node to be added
			Node node = new Node(data, null);

			// if the linked list is empty, we change head and tail both
			if (this.isEmpty()) {
				this.head = node;
				this.tail = node;
			} else {
				// if linked list is not empty, we change only tail pointer
				this.tail.next = node;
				this.tail = node;
			}

			// and increase the size of the linked list
			this.size++;
		}

		// This function displays the linked list
		public void display() {

			// we start traversing the list from head
			Node temp = this.head;

			// and until this temp node becomes null
			while (temp != null) {

				// we print it's data
				System.out.print(temp.data + "=>");

				// and move the temp pointer forward
				temp = temp.next;
			}

			System.out.println("END");

		}

		public boolean hasCycle() {
			return this.hasCycle(this.head);
		}

		// Floyd’s Cycle-Finding Algorithm
		// This function returns true if there is a cycle in the linked list
		private boolean hasCycle(Node head) {

			// if there are no nodes in a linked list, there can't be any cycle present
			if (head == null) {
				return false;
			}

			// we take two pointers slow and fast and start traversing the list, initially
			// both point at head
			Node slow = head;
			Node fast = head;

			// If there is no cycle present, then slow or fast or fast.next will become null
			// at some point of time
			while (slow != null && fast != null && fast.next != null) {

				// in every iteration, slow moves ahead by one node
				slow = slow.next;

				// and fast moves ahead by two nodes
				fast = fast.next.next;

				// if slow and fast reach the same node, then there is a cycle present, so we
				// return true
				if (slow == fast) {
					return true;
				}
			}

			// if there is no cycle present and we have traversed the whole linked list, we
			// return false
			return false;
		}

		// This function returns the node at a particular index in the linked list
		private Node getNodeAt(int index) throws Exception {

			// If the index entered by user is invalid
			if (index < 0 || index >= this.size) {
				throw new Exception("Invalid index");
			}

			// We take a counter to keep track of the index of the node we are at
			int counter = 0;

			// and we start traversing the list from its head
			Node temp = this.head;

			// we traverse the list until we have reached the required node
			while (counter < index) {

				// this is done by moving temp pointer to the next node
				temp = temp.next;

				// and increasing the value of counter
				counter++;
			}

			// finally, we return the required node
			return temp;
		}

	}

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);

		// main class object
		Intersection obj = new Intersection();

		// first linked list
		linkedlist list1 = obj.new linkedlist();

		System.out.println("Enter no. of elements in first linked list:");

		// no. of elements in list1
		int n = in.nextInt();

		System.out.println("Enter elements:");

		// input for elements of list1
		for (int i = 0; i < n; ++i) {
			list1.addLast(in.nextInt());
		}

		// second linked list
		linkedlist list2 = obj.new linkedlist();

		System.out.println("Enter no. of elements in second linked list:");

		// no. of elements in list2
		n = in.nextInt();

		System.out.println("Enter elements:");

		// input for elements of list2
		for (int i = 0; i < n; ++i) {
			list2.addLast(in.nextInt());
		}

		// for simplicity, I have here made the lists intersect manually
		list1.tail.next = list2.getNodeAt(2);
		list1.tail = list2.tail;
		list1.size = list1.size + (list2.size - 2);

		// required function call
		linkedlist.Node node = findIntersection(list1, list2);

		if (node != null) {
			System.out.println(node.data);
		} else {
			System.out.println("Lists don't intersect");
		}
	}

	// This function takes two linked lists and finds their intersection point
	public static linkedlist.Node findIntersection(linkedlist list1, linkedlist list2) throws Exception {

		// if one of the lists is empty
		if (list1 == null || list2 == null) {
			return null;
		}

		// if their tails are not at same pointer, then lists don't intersect
		if (list1.tail != list2.tail) {
			return null;
		}

		// this will traverse the shorter list
		linkedlist.Node shorter = null;

		// this will traverse the longer list
		linkedlist.Node longer = null;

		// if list2 is longer
		if (list1.size < list2.size) {
			shorter = list1.head;
			// we do this to maintain a gap of (list1.size-list2.size) between the lists
			longer = list2.getNodeAt(list2.size - list1.size);
		}
		// if list1 is longer
		else {
			shorter = list2.head;
			// we do this to maintain a gap of (list1.size-list2.size) between the lists
			longer = list1.getNodeAt(list1.size - list2.size);
		}

		// now until the shorter and longer pointers don't intersect
		while (shorter != longer) {
			// we move shorter to next node
			shorter = shorter.next;
			// we move longer to next node
			longer = longer.next;
		}

		// now we return either shorter or longer as both will be pointing to the
		// intersection of the lists
		return longer;

	}
}

// Time complexity analysis -

// This algorithm will take O(n) time where n is the length of the longer list
// as we are just traversing both the lists.

// Space complexity analysis -

// This algorithm will take O(1) extra space as we are only using two pointers
// to traverse the lists.