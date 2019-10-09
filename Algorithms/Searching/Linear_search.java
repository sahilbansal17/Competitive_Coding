//Name: Ayus Das
//Email: ayusdas2000@gmail.com
/*
 * This program searches an array element through linear search algorithm.
 * The array elements and the item to be searches are both taken as user
 * inputs. 
 */
import java.util.Scanner;


public class Linear_search {//function to search the array elements.
	static int linear_Search(int arr[],int total_elements,int item_required)
	{
		for(int i=0;i<total_elements;i++)
		{
			if(arr[i]==item_required)
				return i;			
		}//this loop checks one by one each element
		return -1;
	}
	public static void main(String[] args) {
		int number_of_elements,to_be_searched;
		System.out.println("Enter the number of elements you want to enter:");
		Scanner cin = new Scanner(System.in);
		number_of_elements=cin.nextInt();
		int array_elements[] = new int[number_of_elements];
		System.out.println("Enter the elements in sorted form");
		for(int i=0;i<number_of_elements;i++)
		{
			array_elements[i]=cin.nextInt();
		}
		System.out.println("Enter the item to be searched");
		to_be_searched=cin.nextInt();		
		int result=linear_Search(array_elements,number_of_elements,to_be_searched);
		if(result==-1)
			System.out.println("Item not found");
		else
			System.out.println("Item found at "+result+" index.");
		cin.close();
		
	}

}
