import java.util.*;
import java.lang.*;
import java.io.*;
class prefix
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
            for(int i=str.length()-1;i>=0;i--)
            {
                char ch=str.charAt(i);
                //check if the character is operator or an operand 
                //if character is operator pop the top two elements and 
                //store the resultant string in stack
                if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
                {
                    String op1=st.peek();
                    st.pop();
                    String op2=st.peek();
                    st.pop();
                    st.push("("+op1+" "+ch+" "+op2+")");
                }
                else
               //if character is an operand push it in stack
                st.push(ch+"");
            }
            ans=st.peek();
            //the ans would be the last element of the stack
            System.out.println(ans);
            testcase--;
        }
    }
}
