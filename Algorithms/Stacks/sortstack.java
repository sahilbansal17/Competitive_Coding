// this code sorts the contents of a stack
import java.util.*;
import java.lang.*;
import java.io.*;
class sortstack
{
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        int testcase = s.nextInt();
        Stack<Integer> st=new Stack<>();
        while(testcase>0)
        {
            int n = s.nextInt();
            for(int i=0;i<n;i++)
            {
                st.push(s.nextInt());
            }
            Stack<Integer> sorted = getsorted(st);
            print(sorted);
            testcase--;
        }
    }
    // function to get sorted stack
    public static Stack<Integer> getsorted(Stack<Integer> s)
    {
        Stack<Integer> st = new Stack<>();
        while(!s.isEmpty())
        {
            // if stack is not empty store the top element and compare with the contents of stack
            int temp=s.pop();
            while(!st.isEmpty()&&st.peek()<temp)
            {
                s.push(st.pop());
            }
            st.push(temp);
        }
        return st;
    }
    // function to print the sorted stack
    public static void print(Stack<Integer> st)
    {
        while(!st.isEmpty())
        {
            System.out.print(st.pop()+" ");
        }
        System.out.println();
    }
}
