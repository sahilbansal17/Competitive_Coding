
//Given a binary tree, a target node in the binary tree, and an integer value k, 
//print all the nodes that are at a distance k from the given target node. No 
//parent pointers are available.

//		Author - Aastha Aneja (Github handle - Aashu24)
//		Email - anejaaastha@gmail.com

import java.util.*;

public class KFar {

	// scanner
	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {

		// object of KFar class
		KFar m = new KFar();

		// Binary Tree
		BinaryTree bt = m.new BinaryTree();

		System.out.println("Enter data of node from which you want to print all nodes at a distance k:");

		// node's data
		int data = scn.nextInt();

		System.out.println("Enter value of k:");

		// value of k
		int k = scn.nextInt();

		// This is the function call for the required question
		bt.printKFar(data, k);

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

		// this returns a path from root to a particular node in the form of an
		// arraylist
		private ArrayList<Node> RootToNode(Node node, int data) {

			// if node is null
			if (node == null) {
				return new ArrayList<>();
			}

			// if we have found the node
			if (node.data == data) {
				// we make a new arraylist
				ArrayList<Node> path = new ArrayList<>();

				// and add this node to the arraylist
				path.add(node);
				return path;
			}

			// if the current node is not equal to the given node, it checks its left
			// subtree for a path
			ArrayList<Node> leftPath = RootToNode(node.left, data);

			// if left subtree found a path
			if (leftPath.size() > 0) {
				// current node is added to the path
				leftPath.add(node);
				return leftPath;
			}

			// if the current node is not equal to the given node and there is not path on
			// left, it checks its right subtree for a path
			ArrayList<Node> rightPath = RootToNode(node.right, data);

			// if right subtree found a path
			if (rightPath.size() > 0) {
				// current node is added to the path
				rightPath.add(node);
				return rightPath;
			}

			// if there was no path found, we return an empty arraylist
			return new ArrayList<>();
		}

		// This function prints all elements that are at a k distance down from a
		// particular node
		private void printKDown(Node node, int k) {

			// if k is negative or node is null
			if (k < 0 || node == null) {
				return;
			}

			// if k is 0 then we have found a node at k distance down and we print it
			if (k == 0) {
				System.out.println(node.data);
				return;
			}

			// we check the left subtree for nodes at distance k-1
			printKDown(node.left, k - 1);

			// we check the right subtree for nodes at distance k-1
			printKDown(node.right, k - 1);
		}

		// this functions prints all nodes at a distance k from a given node
		public void printKFar(int data, int k) {

			// first we get the path from root to the given node using the function
			// RootToNode
			ArrayList<Node> path = RootToNode(this.root, data);

			// now we iterate over this path until either we have traversed the whole path
			// or we have traversed it till distance k
			for (int i = 0; i < path.size() && i <= k; ++i) {

				// if i is 0, we print k down nodes using function printKDown
				if (i == 0) {
					// we get the current node
					Node node = path.get(i);

					// and call printKDown function on it
					printKDown(node, k);
				}
				// if i is k, we just print the current node's data
				else if (i == k) {
					System.out.println(path.get(i).data);
				}
				// otherwise we compare it with previous node and make a call accordingly
				else {

					// we get the current node
					Node curr = path.get(i);

					// we get the previous node
					Node prev = path.get(i - 1);

					// if previous node is current node's left child, we make a call for right
					// subtree
					if (curr.left == prev) {

						// we print all nodes at a distance k-1 from the other side of current node
						printKDown(curr.right, k - i - 1);
					}
					// if previous node is current node's right child, we make a call for left
					// subtree
					else {

						// we print all nodes at a distance k-1 from the other side of current node
						printKDown(curr.left, k - i - 1);
					}
				}
			}
		}

	}

}

// Time complexity analysis -

// The function printKFar contains a for loop that will run once for every
// node in the path from root to that particular node. This will make one call
// to printKDown which further makes two calls for left and right subtree.
// Therefore, it will have a time complexity of O(n.2^n) where n is the number
// of nodes in the path from root to that particular node.

// Space complexity analysis -

// The function printKFar takes O(n) extra space for the arraylist that stores a
// path from root node to the given node.