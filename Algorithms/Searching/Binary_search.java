//Name: Ayus Das
//Email: ayusdas2000@gmail.com

/*This program searches an array item. The array elements and the item 
 * to be searched are both taken as user input. The search algorithm 
 * used here is the binary searhc.*/
import java.util.Scanner;


public class Binary_search{//function to search the item through binary search
	static int binary_Search(int arr[],int first_index,int last_index,int item_required)
	{
		while (first_index <= last_index)
		{ 
	        int middle = (first_index + last_index) / 2; 
	  
	        // Check if x is present at mid 
	        if (arr[middle] == item_required)
	        	return middle;
	        
	             
	  
	        // If x greater, ignore left half 
	        if (arr[middle] < item_required) 
	           	first_index = middle + 1;
	        
	            
	  
	        // If x is smaller, ignore right half 
	        else
	            last_index = middle - 1; 
	    } 
	  
	    // if we reach here, then element was 
	    // not present 
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
		}//takes the input of array element through loop
		System.out.println("Enter the item to be searched");
		to_be_searched=cin.nextInt();
		int result=binary_Search(array_elements,0,number_of_elements - 1,to_be_searched);
		if(result==-1)
			System.out.println("Item not found");
		else
			System.out.println("Item found at "+result+" index.");
		cin.close();
		
		
	}

}
