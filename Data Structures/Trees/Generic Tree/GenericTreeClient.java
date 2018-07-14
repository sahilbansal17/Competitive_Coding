//This class implements a simple client for the Generic tree.

public class GenericTreeClient {

	public static void main(String[] args) {
		// sample input for the generic tree - 50 3 40 2 20 0 15 0 80 0 10 1 19 0

		// generic tree declaration
		GenericTree tree = new GenericTree();

		// this method displays the tree
		tree.display();
		System.out.println("*******************************");

		// this method displays the tree in level order
		tree.LevelOrder();
		System.out.println("*******************************");
	}

}
