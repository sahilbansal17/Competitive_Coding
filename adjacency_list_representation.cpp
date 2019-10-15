/* 
** Author :- Divyesh Srivastava
** Institute :- National Institute of Technology Meghalaya
*/

/*            <--- Adjacency List representation of Graph using STL --->                   */ 


// Adjacency list representation of a graph

 #include<iostream>
 #include<vector>
 using namespace std;
 
 int i;
 
 void add(vector<int>a[], int u, int v) // Function to add edges for an undirected graph
 {
     a[u].push_back(v);                 // Adding edge btw vertex u and v
     a[v].push_back(u);                 // Adding edge btw vertex v and u
 }
 
 int main()
 {
      int v;                            // No. of vertices
     
     cout<<"Enter no. of vertices"<<endl;
      cin>>v;
     
      vector<int>a[v];                 // array of list for graph representation
      
      for(i=0;i<v;i++)
      {
          int x,y;                    
           cin>>x>>y;
           
            add(a,x,y);               // Passing edge x and y to function add to create an edge btw them
      }
      
       for(i=0;i<v;i++)              // Printing all Adjacency list for vertex i
      {
          cout<<i<<" "<<"->";
          
          for(auto x:a[i])
           cout<<x<<" ";
           
           cout<<endl;
      }
 }
 
 /*                    Time Complexity :- O (V) // where v is no. of vertex
                       Space Complexity :- O (V)+O(E) // where E is no. of edges
*/
