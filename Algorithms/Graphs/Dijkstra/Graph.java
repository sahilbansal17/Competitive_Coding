
//		Author - Aastha Aneja (Github handle - Aashu24)
//		Email - anejaaastha@gmail.com

import java.util.HashMap;
import java.util.Set;

//This is the implementation of class Graph
public class Graph {
	// This is a class created to store information about each vertex in the graph
	private class Vertex {

		// name stores the name of the vertex
		String name;

		// This hash map will store all the neighbors of a vertex mapped to the cost of
		// their edges
		HashMap<Vertex, Integer> neighbors;

		// Constructor
		public Vertex(String name) {
			// TODO Auto-generated constructor stub
			this.name = name;
			this.neighbors = new HashMap<>();
		}

		// We have to overwrite the equals method so that two vertices are compared on
		// the basis of their name strings
		public boolean equals(Object other) {
			Vertex ov = (Vertex) other;
			return this.name.equals(ov.name);
		}

		// We have to overwrite the hash code method so that it returns the hash of a
		// vertex's name
		public int hashCode() {
			return this.name.hashCode();
		}

		// this function displays a vertex alongwith all its neighbors
		public void display() {

			// rv stands for return value
			String rv = "";

			rv = rv + this.name + "=>";

			// the set nbrs contains all neighbors of a vertex
			Set<Vertex> nbrs = this.neighbors.keySet();

			// this for each loop iterates over the nbrs set and adds each neighbor to the
			// rv
			for (Vertex nbr : nbrs) {
				rv = rv + nbr.name + "(" + this.neighbors.get(nbr) + "),";
			}
			rv = rv + "END";

			// This prints the vertex and its neighbors
			System.out.println(rv);
		}

	}

	// This hash map is used to map the name of each vertex to its vertex object
	// which in turn stores all the neighbors of that vertex
	private HashMap<String, Vertex> vertices;

	// constructor of Graph class
	public Graph() {
		// TODO Auto-generated constructor stub
		this.vertices = new HashMap<>();
	}

	// function to return the number of vertices in the graph
	public int numVertices() {
		return this.vertices.size();
	}

	// function to add a vertex in the graph
	public void addVertex(String name) {

		// if the vertex already exists
		if (this.vertices.containsKey(name)) {
			return;
		}

		// If the vertex does not already exist in the graph, we create a new Vertex
		// object and add it to the vertices Hash map
		Vertex obj = new Vertex(name);
		this.vertices.put(name, obj);

	}

	// function to add an edge in the graph
	public void addEdge(String name1, String name2, int cost) {

		// gets the source vertex
		Vertex v1 = this.vertices.get(name1);

		// gets the destination vertex
		Vertex v2 = this.vertices.get(name2);

		// if even one of the vertices is not present in the graph or if an edge is
		// already present between the two vertices, we do not add the edge again
		if (v1 == null || v2 == null || v1.neighbors.containsKey(v2)) {
			return;
		}

		// this adds v2 to the neighbors of v1 and v1 to the neighbors of v2
		v1.neighbors.put(v2, cost);
		v2.neighbors.put(v1, cost);
	}

	// function to display the graph
	public void display() {

		// names of all vertices of the graph
		Set<String> vertices = this.vertices.keySet();

		// we call display function for each vertex in the graph
		for (String vtc : vertices) {
			Vertex vtx = this.vertices.get(vtc);
			vtx.display();
		}
	}

	// This class is made for Dijkstra'a algorithm. It stores the name of a vertex
	// and its minimum distance
	class MinVertex {
		String vertex;
		int distance;

		// constructor
		public MinVertex(String vertex_name, int dist) {
			// TODO Auto-generated constructor stub
			this.vertex = vertex_name;
			this.distance = dist;
		}
	}

	// This function returns the vertex that has minimum distance from the source at
	// the moment and has not yet been included in the minimum spanning tree for
	// Dijkstra's algorithm. This function takes as arguments, the minimum_distances
	// hash map as well as the included_vertices hash map to compute the minimum
	// vertex
	public MinVertex minimumDistanceVertex(HashMap<String, Integer> minimum_distances,
			HashMap<String, Boolean> included_vertices) {

		// Initially, we assume that the minimum distance is infinity
		int distance = Integer.MAX_VALUE;
		String name = "";

		// For each vertex in the included_vertices hash map
		for (String vertex : included_vertices.keySet()) {

			// if that vertex has not yet been included in MST
			if (included_vertices.get(vertex) == false) {

				// if its distance is less than the minimum distance already computed, we update
				// the values of distance and name
				if (minimum_distances.get(vertex) < distance) {
					distance = minimum_distances.get(vertex);
					name = vertex;
				}
			}
		}

		// Now that we have computed the minimum vertex, we make an object for it and
		// return it
		MinVertex vertex_object = new MinVertex(name, distance);
		return vertex_object;
	}

	// This is the function that implements the Dijkstra's algorithm by using the
	// function minimumDistanceVertex()
	public void dijkstraAlgorithm(String source_vertex) {

		// a hash map to store the minimum distances of all vertices from source_vertex
		HashMap<String, Integer> minimum_distances = new HashMap<>();

		// a hash map to store if a vertex has yet been added in the minimum spanning
		// tree or not
		HashMap<String, Boolean> included_vertices = new HashMap<>();

		// Initially, we set minimum distance for each vertex to be Infinity and map it
		// to false in included_vertices hash map as no vertex has yet been added to the
		// minimum spanning tree
		for (String vertex : this.vertices.keySet()) {
			minimum_distances.put(vertex, Integer.MAX_VALUE);
			included_vertices.put(vertex, false);
		}

		// As the distance of source_vertex from itself is 0, we update the Hash map
		// minimum_distances to store 0 for the source_vertex
		minimum_distances.put(source_vertex, 0);

		// For every vertex (until every vertex is included in the minimum spanning
		// tree of the graph)
		for (int count = 0; count < this.vertices.size() - 1; count++) {

			// this fetches the vertex that has the minimum value for distance from source
			// and has not yet been included in the MST (minimum spanning tree)
			MinVertex vertex = minimumDistanceVertex(minimum_distances, included_vertices);

			// Now as we are going to include this vertex in the MST, we map it to true in
			// included_vertices hash map
			included_vertices.put(vertex.vertex, true);

			// for every vertex in the graph
			for (String v : this.vertices.keySet()) {

				// if we find the vertex that is same as the vertex returned from the
				// minimumDistanceVertex function
				if (v.equals(vertex.vertex)) {

					// We fetch that Vertex object in v
					Vertex ver = this.vertices.get(v);

					// For all the neighbors of v
					for (Vertex nbr : ver.neighbors.keySet()) {

						// If that neighbor has not already been included in the MST
						if (included_vertices.get(nbr.name) == false) {

							// we calculate its distance from the source vertex by adding the distance of
							// returned vertex with cost of edge between the neighbor and the returned
							// vertex
							int d = ver.neighbors.get(nbr) + minimum_distances.get(vertex.vertex);

							// if this new distance d is less than the already existing distance in
							// minimum_distances hash map, we update its value
							if (d < minimum_distances.get(nbr.name))
								minimum_distances.put(nbr.name, d);
						}
					}
				}
			}
		}

		// After all the iterations, we print the minimum_distances hash map that gives
		// the minimum distance of all vertices from the given source vertexs
		System.out.println(minimum_distances);

	}

}
