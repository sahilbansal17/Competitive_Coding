import  java.io.*;
import  java.lang.*;
{
class  delete

{
	public static void main(String[] args) {
	    int n=0,x=0;
	Scanner sc=new Scanner(System.in);
	System.out.println("enter the no. of elements in an array");
	n=sc.nextLine();
	int arr[]=new int[n];
	for(int i=0;i<n;i++)
	{System.out.println("enter an array element");
	    arr[i]=sc.nextLine();}
	System.out.println("enter the position from which the element is to be removed");
	x=sc.nextLine();
	for(int i=x-1;i<n-1;i++)
	{
	    arr[i]=arr[i+1];
	    
	}
	System.out.println("modified array");
	printArray(arr,n-1);
	}
	public static void printArray(int arr[] ,int n )
	{
	    for(int i=0;i<n;i++)
	    {System.out.println(+arr[i]);
	    }
}}

