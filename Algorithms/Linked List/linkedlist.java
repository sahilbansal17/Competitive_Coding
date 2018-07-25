
//A linked list is said to contain a cycle if any node is visited more than once while 
//traversing the list. The problem is to determine if a given Linked list contains a 
//cycle or not. (Floyd’s Cycle-Finding Algorithm)

//		Author - Aastha Aneja (Github handle - Aashu24)
//		Email - anejaaastha@gmail.com

// This class implements a Linked List with some basic methods

import java.util.Scanner;

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

	// This function makes the next of the node at start point to the node at end
	public void createCycle(int start, int end) throws Exception {
		Node startNode = this.getNodeAt(start);
		Node endNode = this.getNodeAt(end);
		startNode.next = endNode;
	}

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub

		Scanner in = new Scanner(System.in);

		// declaring a linked list
		linkedlist list = new linkedlist();

		System.out.println("Enter number of elements you want to add in the linked list:");
		int n = in.nextInt();

		// adding elements in the list
		for (int i = 0; i < n; ++i) {
			System.out.println("Enter element:");
			list.addLast(in.nextInt());
		}

		System.out.println("Do you want to add a cycle in the linked list? (true/false)");
		boolean flag = in.nextBoolean();

		// creating a cycle
		if (flag) {
			System.out.println("Enter index of first node for cycle (0-based indexing) :");
			int start = in.nextInt();
			System.out.println("Enter index of second node for cycle (0-based indexing) :");
			int end = in.nextInt();

			list.createCycle(start, end);
		}

		// function call
		if (list.hasCycle()) {
			System.out.println("The linked list has a cycle");
		} else {
			System.out.println("The list doesn't have a cycle");
		}
	}

}

// Time complexity analysis -

// The Floyd’s Cycle-Finding Algorithm takes O(n) time where n is the number of
// nodes in the linked list. This is so because if the list doesn't contain a
// cycle, it just traverses the whole linked list once and then returns false
// and if the linked list contains a cycle, then as we traverse the list using
// two pointers namely slow and fast, slow and fast come to the same pointer in
// almost one traversal.

// Space complexity analysis -

// The Floyd’s Cycle-Finding Algorithm takes O(1) extra space as only two
// pointers namely slow and fast are declared to traverse the list.