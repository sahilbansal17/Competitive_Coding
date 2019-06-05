 // this code computes the next largest element of each element in an array
 // if the next largest element does not exist print -1 for the corresponding element
import java.util.*;
import java.lang.*;
import java.io.*;
class next_greater
 {
	public static void main (String[] args)throws IOException
	{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        int testcase = Integer.parseInt(br.readLine()); 
        while(testcase>0)
        {
            int n = Integer.parseInt(br.readLine()); 
            long arr[] = new long[n]; 
            String line = br.readLine(); 
            String[] strs = line.trim().split("\\s+"); 
            for (int i = 0; i < n; i++) 
                arr[i] = Long.parseLong(strs[i]); 
           Stack<Integer> st=new Stack<>();
	    int i;
	    long[] ans=new long[n];
	    for(i=0;i<n;i++)
	    {
	         ans[i]=-1;//initialise all the elements by -1
	    }
	    for(i=0;i<n;i++)
	    {
	        while(!st.isEmpty()&&arr[i]>arr[st.peek()])
            //if the element at the current position is greater than the position of element in stack
            //it is the next greatest element 
	        {
	            int t=st.peek();
	            st.pop();
	            ans[t]=arr[i];
	        }
	        st.push(i);//push the index of current element
	    }
	    for(i=0;i<n;i++)
	    {
	        System.out.print(ans[i]+" ");
	    }
            System.out.println();
            testcase--;
        }
	}
}
