/* For the question refer to this link:
      https://www.codechef.com/LTIME76B/problems/CATFEED
*/

package Sept_Lunchtime;

import java.util.Scanner;

public class Main_1{
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		StringBuffer sb= new StringBuffer();
		int t= s.nextInt();
		for(int i=0 ; i<t ; ++i) {
				int n= s.nextInt();
				int m= s.nextInt();
				int min=0;
				int arr[]= new int[n+1];
				int f=0;
				int flag=0;
				for(int j=1; j<=m ; ++j) {
					int tem= s.nextInt();
						if(arr[tem]>min&& flag==0) {
							sb.append("NO"+"\n");
							flag=1;
						}
						else {
							arr[tem]++;
							f++;
							if(f%n==0) {
								min++;
							}
						}
				}
				if(flag==0) 
					sb.append("YES"+"\n");
		}
		System.out.print(sb);
	}
}
