//This code finds the maximum absolute difference between 
//nearest left and right smaller element of every element in an array
import java.util.*;
import java.io.*;
class maxdiff
{
    public static void main(String args[])
    {
        Scanner s=new Scanner(System.in);
        int testcase=s.nextInt();
        while(testcase>0)
        {
            int n=s.nextInt();
            int[] a=new int[n];
            for(int i=0;i<n;i++)
            {
                a[i]=s.nextInt();
            }
            int ans=getDiff(a,a.length);
            //function to get maximum difference 
            System.out.println(ans);
            testcase--;
        }
    }
    public static int getDiff(int a[], int n)
    {
        ArrayList<Integer> left=getarray(a,n);
        //Arraylist consisting of nearest left smaller element 
        int[] b=reverse(a);
        //b is an array which is reverse of original array
        //a is reversed to get the nearest right smaller element of each element in an array
        ArrayList<Integer> right=getarray(b,n);
        int t=right.size();
        int ans=Integer.MIN_VALUE;
        for(int i=0;i<t;i++)
        {
            int ch=Math.abs(right.get(i)-left.get(t-1-i));
            //get absolute difference between right and left smaller elements
            ans=Math.max(ans,ch);
        }
        return ans;
    }
    //function to get an arraylist consisting of left smaller elements
    public static ArrayList<Integer> getarray(int a[],int n)
  {
        Stack<Integer> st=new Stack<>();
        ArrayList<Integer> arr=new ArrayList<>();
        int j=0;
        for(int i=0;i<n;i++)
        {
            while(!st.isEmpty()&&st.peek()>=a[i])
            st.pop();
         
            if(st.isEmpty())
            arr.add(0);
            //for the element at extreme left the smallest left element is 0
            else
            arr.add(st.peek());
            
            st.push(a[i]);
        }
        return arr;
  }
  //function to reverse the original array
  public static int[] reverse(int a[])
  {
        int[] arr=new int[a.length];
        int k=0;
        for(int i=arr.length-1;i>=0;i--)
        {
            arr[k++]=a[i];
        }
        return arr;
  }
}
