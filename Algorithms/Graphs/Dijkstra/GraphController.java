//The problem is to determine the shortest path from a source vertex in a graph to all the other vertices.

// Dijkstra's algorithm solves this problem by creating a minimum spanning tree for the graph 
// by every time adding the vertex that has the smallest distance from the source vertex and 
// updating the distance of all the neighbors of this vertex. The first vertex always selected 
// is the source vertex as the distance of source vertex from itself is obviously zero. 
// After this, all subsequent vertices are selected on the basis of their distances from the source vertex.

//		Author - Aastha Aneja (Github handle - Aashu24)
//		Email - anejaaastha@gmail.com

import java.util.Scanner;

//A class that declares an object of the class Graph and takes as input, its vertices and edges 
//and then calls the Dijkstra's algorithm on it.
public class GraphController {

	public static void main(String[] args) {

		// Scanner declaration
		Scanner in = new Scanner(System.in);

		// Object of class Graph
		Graph g = new Graph();

		System.out.println("Enter number of vertices:");

		// n stores the number of vertices in the graph
		int n = in.nextInt();

		// Loop to take input of all graph vertices
		for (int i = 1; i <= n; i++) {
			System.out.println("Enter vertex name:");
			// this function adds a vertex to the graph
			g.addVertex(in.next());
		}

		System.out.println("Enter number of edges:");

		// Now, n stores the number of edges in the graph
		n = in.nextInt();

		// Loop to take input of all graph edges
		for (int i = 1; i <= n; i++) {

			System.out.println("Enter source vertex name:");
			String src = in.next();

			System.out.println("Enter destination vertex name:");
			String dest = in.next();

			System.out.println("Enter distance between vertices (cost of edge) :");
			int dist = in.nextInt();

			// this function adds an edge in the graph between source and destination vertex
			g.addEdge(src, dest, dist);
		}

		System.out.println("Enter source vertex for Dijkstra's algorithm :");

		// input of source vertex for Dijkstra's algorithm (vertex from which we wish to
		// calculate shortest paths for all other vertices in the graph
		String source_vertex = in.next();

		// function to implement Dijkstra's algorithm
		g.dijkstraAlgorithm(source_vertex);

		in.close();
	}

}

// Time complexity analysis

// This approach takes O(n^2) time complexity where n is the number of vertices.
// This is so because the function iterates over all the vertices as many times
// as the number of vertices in the graph i.e. for each vertex in the graph, it
// iterates over the vertices list and compares it with the returned vertex.

// Space complexity analysis

// This approach takes O(n) extra space where n is the number of vertices in
// the graph. This is so because we take two hash maps each of size n, one that
// stores the minimum distances of each vertex from the source vertex and one
// that stores if the vertex has or has not been included in the minimum
// spanning tree of the graph. This amounts to O(2n) extra space which is equal
// to O(n).