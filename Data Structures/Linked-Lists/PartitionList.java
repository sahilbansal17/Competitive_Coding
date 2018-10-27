//Write code to partition a linked list around a value x, such that all nodes less than x come
//before all nodes greater than or equal to x. If x is contained within the list, the values of x only need
//to be after the elements less than x (see below). The partition element x can appear anywhere in the
//"right partition"; it does not need to appear between the left and right partitions.
//EXAMPLE :
//Input:
//3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition= 5]
//Output:
//3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8

//		Author - Aastha Aneja (Github handle - Aashu24)
//		Email - anejaaastha@gmail.com

import java.util.Scanner;

public class PartitionList {

	public static void main(String[] args) {

		// scanner
		Scanner in = new Scanner(System.in);

		// object of this class
		PartitionList obj = new PartitionList();

		// object of linked list
		linkedlist list = obj.new linkedlist();

		System.out.println("Enter number of elements you want to add in linked list:");

		// number of elements user wants to enter in the list
		int n = in.nextInt();

		// user input
		for (int i = 0; i < n; ++i) {
			System.out.println("Enter element:");
			list.addLast(in.nextInt());
		}

		System.out.println("Enter partition point:");

		// data for partitioning
		int partition = in.nextInt();

		// required function call
		linkedlist partitioned = list.partitionList(partition);

		System.out.println("List after partitioning:");

		// displaying list after partitioning
		partitioned.display();

	}

	private class linkedlist {

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

		// This function returns the list after partitioning is done
		public linkedlist partitionList(int partition) {

			// if head is null, it means that the list is empty
			if (this.head == null) {
				System.out.println("List is empty");
				// so our answer is also null
				return null;
			}

			// we create two separate linked lists
			// the list named lesser will store all elements lesser than the partition
			// element
			linkedlist lesser = new linkedlist();

			// the list named greater will store all elements greater than or equal to the
			// partition element
			linkedlist greater = new linkedlist();

			// we start traversing this list from its head
			Node node = this.head;

			// and we traverse it until its end
			while (node != null) {

				// if a node's data is lesser than partition data, we add it to lesser list
				if (node.data < partition) {
					lesser.addLast(node.data);
				}

				// if a node's data is greater than or equal to the partition data, we add it to
				// lesser list
				else {
					greater.addLast(node.data);
				}
				node = node.next;
			}

			// now we merge these two linked lists by making lesser's tail point to
			// greater's head
			lesser.tail.next = greater.head;

			// and finally making lesser's tail point at the right tail of the merged linked
			// list
			lesser.tail = greater.tail;

			// then we return the partitioned list stored in lesser list
			return lesser;
		}

	}

}

// Time complexity analysis -

// The Partitioning Algorithm takes O(n) time where n is the number of
// nodes in the linked list. This is so because it traverses the list only once.

// Space complexity analysis -

// The Partition Algorithm takes O(n) extra space as it makes two
// linked lists namely lesser and greater and in the end the sum of their sized
// will be n.