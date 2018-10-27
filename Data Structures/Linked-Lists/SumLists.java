//You have two numbers represented by a linked list, where each node contains a single
//digit. The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a
//function that adds the two numbers and returns the sum as a linked list.
//EXAMPLE
//Input: (7-> 1 -> 6) + (5 -> 9 -> 2).That is,617 + 295.
//Output: 2 -> 1 -> 9. That is, 912.

//		Author - Aastha Aneja (Github handle - Aashu24)
//		Email - anejaaastha@gmail.com

import java.util.Scanner;

public class SumLists {

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

		// this functions finds the sum of two linked lists
		public linkedlist.Node findSum(linkedlist.Node node1, linkedlist.Node node2, int carry) {

			// if both lists are empty and carry is also 0
			if (node1 == null && node2 == null && carry == 0) {
				return null;
			}

			// otherwise, we make a new node
			linkedlist.Node result = new linkedlist.Node(0, null);

			// this value will be put in the new node
			int value = carry;

			// if node1 is present, we add its data to value
			if (node1 != null) {
				value += node1.data;
			}

			// if node2 is present, we add its data to value
			if (node2 != null) {
				value += node2.data;
			}

			// we will be storing only one digit in one node
			result.data = value % 10;

			// now we make a recursive call for the next nodes
			if (node1 != null || node2 != null) {
				// list1's next node
				linkedlist.Node next1 = null;
				if (node1 != null) {
					next1 = node1.next;
				}

				// list2's next node
				linkedlist.Node next2 = null;
				if (node2 != null) {
					next2 = node2.next;
				}

				// recursive call
				linkedlist.Node more = findSum(next1, next2, value / 10);

				// now we join this new node to our list
				result.next = more;
			}

			// and finally we return head of the new list
			return result;
		}

	}

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);

		// main class object
		SumLists obj = new SumLists();

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

		// required function call
		linkedlist.Node node = list1.findSum(list1.head, list2.head, 0);

		// now we iterate from node to null to print the ans
		linkedlist.Node ans = node;

		// iteration
		while (ans != null) {
			System.out.print(ans.data + "=>");
			ans = ans.next;
		}
		System.out.print("END");
	}

}

// Time complexity analysis -

// This algorithm will take O(n) time where n is the length of the longer list
// as we are just traversing both the lists.

// Space complexity analysis -

// This algorithm will take O(n) extra space as we are a new linked list to make
// sum of lists with some extra space for recursion.