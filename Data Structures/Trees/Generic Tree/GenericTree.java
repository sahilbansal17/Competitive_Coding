
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

//This class implements the Generic Tree
public class GenericTree {

	// class to implement a node of generic tree
	private class Node {

		// this is the data of a node
		int data;

		// this array list stores all the children of this node
		ArrayList<Node> children;

		// constructor
		Node(int data) {
			this.data = data;
			this.children = new ArrayList<>();
		}
	}

	// root of the generic tree
	Node root;

	// size of the generic tree = number of nodes in it
	int size = 0;

	// constructor for the tree
	GenericTree() {
		Scanner s = new Scanner(System.in);
		this.root = takeInput(s, null, 0);
	}

	// this method returns the size of the generic tree
	public int size() {
		return this.size;
	}

	// this method takes input to construct the generic tree
	private Node takeInput(Scanner s, Node parent, int ithchild) {

		// at first, when root=null, we take input data for root node
		if (parent == null) {
			System.out.println("Enter the data for root node");
		} else {

			// if parent!=null, we are taking input for the i th child of the node
			System.out.println("Enter the data for " + ithchild + " of " + parent.data);
		}

		// input data of node
		int nodedata = s.nextInt();

		// this constructs a new node in the memory with input data
		Node node = new Node(nodedata);

		// as a new node is added, we increase the size of the generic tree
		this.size++;

		// now we take input for the node's children
		System.out.println("Enter the number of children for " + node.data);

		// this stores number of children for a particular node
		int children = s.nextInt();

		// now for each child, we make a recursive call to the takeInput function that
		// takes input for the child node
		for (int i = 0; i < children; i++) {
			Node child = takeInput(s, node, i);

			// here we add the child to parent node's arraylist of its children
			node.children.add(child);
		}

		// this finally returns the current parent node or the root of the whole generic
		// tree when the last call is wiped off of the stack
		return node;
	}

	// method to display the generic tree
	public void display() {
		display(this.root);
	}

	// this method is called by display() method and takes the root of the generic
	// tree and recursively displays each node and its children
	private void display(Node node) {

		// we first print the parent node
		System.out.print(node.data + "=>");

		// then we print each of its children
		for (int i = 0; i < node.children.size(); i++) {
			System.out.print(node.children.get(i).data + ", ");
		}
		System.out.println("END");

		// now we call display method for each child
		for (int i = 0; i < node.children.size(); i++) {
			this.display(node.children.get(i));
		}
	}

	// this method prints the level order traversal of the generic tree
	public void LevelOrder() {

		// first we create a new queue
		LinkedList<Node> queue = new LinkedList<>();

		// we add the root of the generic tree to the queue
		queue.addLast(this.root);

		// now while the queue is not empty, we remove one node from the queue, print
		// its data and add all its children to the queue
		while (!queue.isEmpty()) {

			// remove one node from the queue
			Node temp = queue.removeFirst();

			// print the removed node's data
			System.out.println(temp.data);

			// add all the children of node in the queue
			for (int i = 0; i < temp.children.size(); i++) {
				queue.addLast(temp.children.get(i));
			}
		}
	}

}

// Time complexity analysis -

// The takeInput() method takes O(n) time for where n is the size of the generic
// tree. This is because it is called once for each node in the generic tree.
// Similar is the case with the display() method. The level order traversal also
// takes O(n) time as it inserts every node in the queue once and then displays
// it.

// Space complexity analysis -

// The level order traversal takes O(n) extra space where n is the number of
// nodes on the generic tree. This is because the queue will store at maximum n
// nodes at a time.