//Program to find number of ways to reach a particular value by existing coins
import java.util.*;
import java.io.*;
class coin_change
{
    public static void main(String args[])
    {
        Scanner s=new Scanner(System.in);
        int testcase=s.nextInt();
        while(testcase>0)
        {
            int value=s.nextInt();
            //total value to be reached
            int n=s.nextInt();
            //number of coins
            int[] coins=new int[n];
            //array consisting of values of coins
            int i,j;
            for(i=0;i<n;i++)
            {
                coins[i]=s.nextInt();
            }
            int[][] table=new int[coins.length+1][value+1];
            //construct a 2D array to store the result
            for(i=0;i<=coins.length;i++)
            {
                table[i][0]=1;
            }
            //base case if value is 0
            for(i=0;i<=value;i++)
            {
                table[0][i]=0;
            }
            for(i=1;i<=coins.length;i++)
            {
                for(j=1;j<=value;j++)
                {
                    if(j>=coins[i-1])
                    table[i][j]=table[i-1][j]+table[i][j-coins[i-1]];
                    else
                    table[i][j]=table[i-1][j];
                }
            }
            System.out.println(table[coins.length][value]);
            testcase--;
        }
    }
}
//Time Complexity of the above code is O(mn) where m=value n=number of coins