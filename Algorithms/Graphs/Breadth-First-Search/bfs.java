import java.util.Scanner;
import java.util.*;
public class Solution {

    
    public static void print_bfs(int [][] mat){
       Queue<Integer> q = new LinkedList<>(); 
        boolean [] visited= new boolean[mat.length];
        q.add(0);
                visited[0]=true;
               while(!q.isEmpty()){
                   int t=q.remove();
                   System.out.print(t+ " ");
                   for(int j=0; j<mat.length; ++j){
                       if(mat[t][j]==1 && !visited[j]){
                          q.add(j);
                           visited[j]=true;
                       }
                           
                   }
               }
            }
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int V = s.nextInt();
		int E = s.nextInt();

		int mat[][]= new int[V][V];
        for(int i=0; i<E; ++i){
            int fv=s.nextInt();
            int sv= s.nextInt();
            mat[fv][sv]=1;
            mat[sv][fv]=1;
        }
        print_bfs(mat);
	}
}