/* For the question refer to this link:
      https://www.codechef.com/LTIME76B/problems/WATCHFB/
*/

package Sept_Lunchtime;

import java.util.Scanner;

public class Main_2 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		StringBuffer sb= new StringBuffer();
		int t= s.nextInt();
		for(int i=0 ; i<t ; ++i) {
			int num= s.nextInt();
			int t1=0;
			int t2=0;
			for(int j=0; j<num; ++j) {
				int f= s.nextInt();
				int n= s.nextInt();
				int m= s.nextInt();
				if(f==1) {
					sb.append("YES"+"\n");
					t1= n;
					t2= m;
				}
				else {
					if(((t1>=n&& t2>=m && t1>=m && t2>=n)|| (t1<=n && t1<=m && t2<=n && t2<=m)) && n!=m)
						sb.append("NO"+"\n");
					else {
						sb.append("YES"+"\n");
						if(n==m) {
							t1=n;
							t2=m;
						}
						
						if(t1<n && t1>m || t1>n && t1<m) {
							if(t1<n&& t1>m) {
								t1=n;
								t2=m;
							}
							else {
								t1=m;
								t2=n;
							}
						}
						else if(t2<n && t2>m || t2>n && t2<m) {
							if(t2<n&& t2>m) {
								t2=n;
								t1=m;
							}
							else {
								t2=m;
								t1=n;
							}
						}
						//sb.append("t1"+ t1+ " "+ "t2"+ t2);
					}
				}
			}
		}
		System.out.print(sb);
	}
}
