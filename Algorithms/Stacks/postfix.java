import java.util.*;
import java.lang.*;
import java.io.*;
class postfix
{
    public static void main(String[] args)
    {
        Scanner s=new Scanner(System.in);
        int testcase=s.nextInt();
        while(testcase>0)
        {
            String str=s.next();
            String ans="";
            Stack<String> st =new Stack<>();
            for(int i=0;i<str.length();i++)
            {
                char ch=str.charAt(i);
                if(ch=='+'||ch=='-'||ch=='+'||ch=='*')
                {
                    String op1=st.peek();
                    st.pop();
                    String op2=st.peek();
                    st.pop();
                    st.push("("+op2+" "+ch+" "+op1+")");
                }
                else
                st.push(str.charAt(i)+"");
            }
            ans=st.peek();
            System.out.println(ans);
            testcase--;
        }
    }
}
