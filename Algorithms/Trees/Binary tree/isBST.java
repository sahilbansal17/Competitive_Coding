
//A binary search tree (BST) is a node based binary tree data structure which has the following properties.
//• The left subtree of a node contains only nodes with keys less than the node’s key.
//• The right subtree of a node contains only nodes with keys greater than the node’s key.
//• Both the left and right subtrees must also be binary search trees.
//
//The problem is to check if a given binary tree is a binary search tree.

//		Author - Aastha Aneja (Github handle - Aashu24)
//		Email - anejaaastha@gmail.com

import java.util.*;

public class isBST {

	// scanner
	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {

		// object of LCA class
		isBST m = new isBST();

		// Binary Tree
		BinaryTree bt = m.new BinaryTree();

		System.out.println("Enter data 1:");

		// input for data1
		int data1 = scn.nextInt();

		System.out.println("Enter data 2:");

		// input for data2
		int data2 = scn.nextInt();

		// This is the function call for the required question
		if (bt.isBST()) {
			System.out.println("The given binary tree is a binary search tree.");
		} else {
			System.out.println("The given binary tree is not a binary search tree.");
		}

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

		// This function checks if the given binary tree is a Binary Search tree
		public boolean isBST() {
			return this.isBST(this.root, Integer.MIN_VALUE, Integer.MAX_VALUE);
		}

		// private function to check if the given binary tree is a binary search tree
		private boolean isBST(Node node, int min, int max) {

			// if the root of the tree is null then it is a binary search tree so we return
			// true
			if (node == null) {
				return true;
			}

			// otherwise we check if the node's data is greater than max (value on right) or
			// less than min (value on left) and return false if it is so
			if (node.data < min || node.data > max) {
				return false;
			}

			// we check if the left subtree is a BST by taking current node's value as max
			// for the left subtree as all nodes on left subtree should be less than this
			// node for it to be a BST
			else if (!isBST(node.left, min, node.data)) {
				return false;
			}

			// we check if the right subtree is a BST by taking current node's value as min
			// for the right subtree as all nodes on right subtree should be greater than
			// this node for it to be a BST
			else if (!isBST(node.right, node.data, max)) {
				return false;
			}

			// in the end if the tree is a BST, we return true
			return true;
		}

	}

}

// Time complexity analysis -

// The function isBST will make at maximum two calls further, one for the
// left child and another for its right child, so, its time complexity will be
// O(2^n) where n is the number of levels in the binary tree.

// Space complexity analysis -

// The function isBST takes O(1) extra space and some extra space for the
// recursive calls.