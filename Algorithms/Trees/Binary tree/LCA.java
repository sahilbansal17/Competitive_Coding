
//Let T be a rooted tree. The lowest common ancestor between two nodes n1 and n2 is 
//defined as the lowest node in T that has both n1 and n2 as descendants (where we 
//allow a node to be a descendant of itself). The problem is to determine the lowest 
//common ancestor of two elements in a binary tree such that both the nodes are 
//present in the tree.

//		Author - Aastha Aneja (Github handle - Aashu24)
//		Email - anejaaastha@gmail.com

import java.util.*;

public class LCA {

	// scanner
	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {

		// object of LCA class
		LCA m = new LCA();

		// Binary Tree
		BinaryTree bt = m.new BinaryTree();

		System.out.println("Enter data 1:");

		// input for data1
		int data1 = scn.nextInt();

		System.out.println("Enter data 2:");

		// input for data2
		int data2 = scn.nextInt();

		// This is the function call for the required question
		System.out.println("LCA is " + bt.LCA(data1, data2));

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

		// This function finds the LCA of two given data in the binary tree
		public int LCA(int data1, int data2) {

			// call to private function
			Node lca = LCA(this.root, data1, data2);

			// if lca is not null
			if (lca != null) {
				return lca.data;
			}

			// if lca is null
			return -1;
		}

		private Node LCA(Node node, int data1, int data2) {

			// if root is null, we can't find the LCA
			if (node == null) {
				return null;
			}

			// if the data of root is same as either first data or second data then that
			// node will be the LCA
			if (node.data == data1 || node.data == data2) {
				return node;
			}

			// left recursive call
			Node leftLCA = LCA(node.left, data1, data2);

			// right recursive call
			Node rightLCA = LCA(node.right, data1, data2);

			// if left recursive call and right recursive call both return not null, this
			// means that one node is in the left subtree and the other one is in the right
			// subtree, so the current node is the LCA
			if (leftLCA != null && rightLCA != null) {
				return node;
			}

			// if only leftLCA is not null, this means that our answer is the leftLCA
			if (leftLCA != null) {
				return leftLCA;
			}
			// if only rightLCA is not null, this means that our answer is the rightLCA
			return rightLCA;
		}
	}

}

// Time complexity analysis -

// The function LCA will make at maximum two calls further, one for the
// left child and another for its right child, so, its time complexity will be
// O(2^n) where n is the number of levels in the binary tree.

// Space complexity analysis -

// The function LCA takes O(1) extra space and some extra space for the
// recursive calls.