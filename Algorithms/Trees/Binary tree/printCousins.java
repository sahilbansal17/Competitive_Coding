
//The problem is to print all cousins of a node in a binary tree. The cousins of a node 
//will be all nodes on the same level that are not the node's siblings(a sibling is a node 
//that has the same parent).

//		Author - Aastha Aneja (Github handle - Aashu24)
//		Email - anejaaastha@gmail.com

import java.util.*;

public class printCousins {

	// scanner
	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {

		// object of printCousins class
		printCousins m = new printCousins();

		// Binary Tree
		BinaryTree bt = m.new BinaryTree();

		System.out.println("Enter data to find cousins of:");

		// input for data
		int data = scn.nextInt();

		// This is the function call for the required question
		bt.cousins(data);

	}

	// Implementation of Binary Tree
	private class BinaryTree {

		// Node class of the Binary tree
		private class Node {

			// data of node
			int data;

			// pointer to left child
			Node left;

			// pointer to right child
			Node right;
		}

		// root of the tree
		private Node root;

		// size=no. of nodes in the tree
		private int size;

		// constructor
		public BinaryTree() {

			// takeInput will take input for the binary tree and return its root
			this.root = this.takeInput(null, false);
		}

		// display function displays the binary tree
		public void display() {
			this.display(this.root);
		}

		// private display that accepts root initially
		private void display(Node node) {
			if (node.left != null) {
				System.out.print(node.left.data + "=>");
			} else {
				System.out.print("END=>");
			}

			System.out.print(node.data);
			if (node.right != null) {
				System.out.print("<=" + node.right.data);
			} else {
				System.out.print("<=END");
			}

			System.out.println();

			if (node.left != null) {
				this.display(node.left);
			}
			if (node.right != null) {
				this.display(node.right);
			}

		}

		// This takes input for the Binary tree (ilc=is Left child)
		public Node takeInput(Node parent, boolean ilc) {

			System.out.println("Enter data:");

			int cdata = scn.nextInt();
			Node child = new Node();
			child.data = cdata;
			this.size++;

			System.out.println("Does " + child.data + " have a left child (true/false):");
			// left
			boolean hlc = scn.nextBoolean();

			if (hlc) {
				child.left = this.takeInput(child, true);

			}

			System.out.println("Does " + child.data + " have a right child (true/false):");
			// right
			boolean hrc = scn.nextBoolean();

			if (hrc) {
				child.right = this.takeInput(child, false);

			}

			// return
			return child;
		}

		// This function prints all the cousin nodes of a given node
		public void cousins(int data) {

			// if the tree is empty
			if (this.root == null) {
				System.out.println("The tree is empty.");
				return;
			}

			// if the user wants to find cousins of root
			if (this.root.data == data) {
				System.out.println("The given data is of root and hence has no cousins");
				return;
			}

			// we initially take a found flag to be false to denote that we haven't yet
			// found the given node
			boolean found = false;

			// we also take a queue to traverse the tree in level order
			LinkedList<Node> queue = new LinkedList<>();

			// The first node in the queue will be the root (level 0 node)
			queue.addLast(this.root);

			// Now we loop until either we have traversed all nodes or we have found the
			// given node
			while (!queue.isEmpty() && !found) {

				// this variable stores the current size of the queue (nodes on one level)
				int sizeofQueue = queue.size();

				// while this size doesn't become 0
				while (sizeofQueue-- > 0) {

					// we remove one node from the queue
					Node node = queue.removeFirst();

					// and we check if its left or right child is the node we are looking for, if we
					// find the node, we don't push its siblings to the queue
					if ((node.left != null && node.left.data == data)
							|| (node.right != null && node.right.data == data)) {
						found = true;
					}
					// if the node's left or right child isn't the node we are looking for then we
					// push them into the queue
					else {
						if (node.left != null) {
							queue.addLast(node.left);
						}
						if (node.right != null) {
							queue.addLast(node.right);
						}
					}
				}
			}

			// if we found the node in the tree, we print its cousins (present in the queue)
			if (found) {
				System.out.println("Cousins:");
				while (!queue.isEmpty()) {
					System.out.println(queue.removeFirst().data);
				}
			}
			// if we didn't find the node in the tree
			else {
				System.out.println("Node not found in the tree");
			}
		}

	}

}

// Time complexity analysis -

// The function cousins will runs a while loop to traverse all the nodes of the
// tree in a level order traversal which means that in the worst case when the
// given node is not present in the tree, it will traverse the whole tree node
// by node, so it's time complexity becomes O(n) where n is the number of nodes
// in the tree.

// Space complexity analysis -

// The function cousins takes O(n) extra space to store the nodes in the queue.