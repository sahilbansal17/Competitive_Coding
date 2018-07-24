
//Given a binary tree and a number k, print out all root to leaf paths where the 
//sum of all nodes value is same as the given number.

//		Author - Aastha Aneja (Github handle - Aashu24)
//		Email - anejaaastha@gmail.com

import java.util.*;

public class RootToLeaf {

	// scanner
	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {

		// object of RootToLeaf class
		RootToLeaf m = new RootToLeaf();

		// Binary Tree
		BinaryTree bt = m.new BinaryTree();

		System.out.println("Enter the required sum from root to leaf:");

		// input for sum
		int sum = scn.nextInt();

		// This is the function call for the required question
		bt.root_leaves(sum);
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

			System.out.println("Edter data:");

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

		// this calls the private root to leaf function
		public void root_leaves(int targetSum) {
			root_leaves(this.root, targetSum, 0, "");
		}

		// This recursively checks if a path is found from root to leaf with the given
		// targetSum and prints it
		private void root_leaves(Node node, int targetSum, int sum, String str) {

			// If the node is a leaf node
			if (node.left == null && node.right == null) {

				// and if we have reached the targetSum by including the leaf's value in the
				// present sum i.e. sum
				if (sum + node.data == targetSum) {

					// The path is printed
					System.out.println(str + " " + node.data);
				}
				return;
			}

			// If the left child of this node doesn't exist, we don't make a recursive call
			// for it
			if (node.left != null)
				root_leaves(node.left, targetSum, sum + node.data, str + " " + node.data);

			// If the right child of this node doesn't exist, we don't make a recursive call
			// for it
			if (node.right != null)
				root_leaves(node.right, targetSum, sum + node.data, str + " " + node.data);

		}
	}

}

// Time complexity analysis -

// The function root to leaf will make at maximum two calls further, one for the
// left child and another for its right child, so, its time complexity will be
// O(2^n) where n is the number of levels in the binary tree.

// Space complexity analysis -

// The function root to leaf takes O(1) extra space and some extra space for the
// recursive calls.