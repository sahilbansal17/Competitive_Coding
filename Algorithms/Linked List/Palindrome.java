//Implement a function to check if a linked list is a palindrome.
//Implement this iteratively without reversing the linked 
//list in O(n).

//		Author - Aastha Aneja (Github handle - Aashu24)
//		Email - anejaaastha@gmail.com

import java.util.Scanner;
import java.util.Stack;

public class Palindrome {

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
		Palindrome obj = new Palindrome();

		// first linked list
		linkedlist list = obj.new linkedlist();

		System.out.println("Enter no. of elements in first linked list:");

		// no. of elements in list1
		int n = in.nextInt();

		System.out.println("Enter elements:");

		// input for elements of list1
		for (int i = 0; i < n; ++i) {
			list.addLast(in.nextInt());
		}

		// required function call
		boolean flag = isPalindrome(list.head);

		// if it is a palindrome
		if (flag) {
			System.out.println("The linked list is a palindrome.");
		}
		// if it is not a palindrome
		else {
			System.out.println("The linked list is not a palindrome.");
		}
	}

	// This function returns true if the given linked list is a palindrome
	public static boolean isPalindrome(linkedlist.Node node) {

		// if the list is empty
		if (node == null) {
			return true;
		}

		// we use the runner technique to iterate through the linked list using two
		// pointers fast and slow
		linkedlist.Node fast = node;
		linkedlist.Node slow = node;

		// This stack will store the first half the linked list
		Stack<Integer> stack = new Stack<>();

		// until we have traversed the whole linked list using fast pointer, we will
		// move slow ahead by one node and fast by two nodes ahead
		while (fast != null && fast.next != null) {

			// we push slow's data to the stack
			stack.push(slow.data);

			// move slow one node ahead
			slow = slow.next;

			// and move fast two nodes ahead
			fast = fast.next.next;
		}

		// if the linked list has odd no. of elements, we skip the middle element of the
		// list
		if (fast != null) {
			slow = slow.next;
		}

		// now while we have not traversed the linked list completely with slow
		while (slow != null) {

			// we pop one element from the stack
			int tos = stack.pop();

			// compare it with slow's data
			if (tos != slow.data) {

				// and if they are not equal, we return false
				return false;
			}

			// we move slow ahead by one node
			slow = slow.next;
		}

		// and return true if all elements are equal
		return true;
	}

}

// Time complexity analysis -

// This algorithm will take O(n) time as we just traverse the linked list using
// runner technique by using two pointers fast and slow.

// Space complexity analysis -

// This algorithm will take O(n) extra space as we are using a stack to store
// half the elements of the list.