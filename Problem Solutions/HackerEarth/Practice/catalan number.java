/* IMPORTANT: Multiple classes and nested static classes are supported */


// * uncomment this if you want to read input.
//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;

//import for Scanner and other utility classes
import java.util.*;


// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

class TestClass {
   
   
  public static Scanner scn = new Scanner(System.in);
// A dynamic programming based function to find nth  
// Catalan number  
 static long catalan[] = new long[5000 + 2]; 
    static void catalanDP(int n) { 
        // Table to store results of subproblems  
       
  
        // Initialize first two values in table  
        catalan[0] = 1; 
        catalan[1] = 1; 
  
        // Fill entries in catalan[] using recursive formula  
        for (int i = 2; i <= n; i++) { 
            catalan[i] = 0; 
            for (int j = 0; j < i; j++) { 
                catalan[i] += catalan[j] * catalan[i - j - 1]; 
            } 
        } 
  
        // Return last entry  
    } 
  
// Driver code  
    public static void main(String[] args) { 
              
     catalanDP(5000);
       int Q=scn.nextInt();

        for (int i = 0; i < Q; i++) { 
                int x=scn.nextInt();
            System.out.println(catalan[x]); 
        } 
    } 

}
