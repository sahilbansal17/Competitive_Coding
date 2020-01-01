/* For the question refer to this link:
      https://www.codechef.com/LTIME76B/problems/PAIRSUM2
*/
package Sept_Lunchtime;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main_3 {
	static class FastReader 
    { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
  
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    } 
	public static void main(String[] args) {
		FastReader s=new FastReader(); 
		StringBuffer sb= new StringBuffer();
		int t= s.nextInt();
		for(int i=0 ; i<t ; ++i) {
			int n= s.nextInt();
			int q= s.nextInt();
			long arr[]= new long[n];
			long ansa[]= new long[n];
			int f=0;
			for(int j=1; j<n; ++j) {
				arr[j]= s.nextLong();
				if(f%2==0) 
					ansa[j]=ansa[j-1]+arr[j];
				else
					ansa[j]=ansa[j-1]-arr[j];
				f++;
			}
			for(int times=1; times<=q; ++times) {
				int p1=s.nextInt();
				int p2= s.nextInt();
			
				if(Math.abs(p1-p2)%2==0)
					sb.append("UNKNOWN"+ "\n");
				else {
					long ans=0;
					int start= Math.min(p1, p2);
					int end= Math.max(p1, p2);
					if(start%2==0) {
						ans= 0-ansa[end-1]+ansa[start-1];
					}
					else {
						ans= ansa[end-1]-ansa[start-1];
					}
					sb.append(ans+"\n");
					}
				}
			}
			System.out.println(sb);
		}
	}