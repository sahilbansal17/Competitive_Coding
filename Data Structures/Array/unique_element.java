	
public class Dublicateinarray {

	public static void main(String[] args) {
		
		Scanner scn = new Scanner(System.in);
		//Taking input for first array 
		int n = scn.nextInt();
		int arr[] =new int[n];
		for(int i=0;i<n;i++){
			arr[i] = scn.nextInt(); 
		}
		System.out.println(dublicateinarray1(arr)); // method call 
		//Taking input for second array 
		int m = scn.nextInt();
		int arr2[] =new int[m];
		for(int i=0;i<m;i++){
			arr2[i] = scn.nextInt(); 
		}
		dublicateinarray1(arr2);    // method call
		System.out.println(a + "  " + b );
	}

      
        // Input 1 6 8 9 1 8 6 
	//Output 9
	// Here I am using XOR property
	// 1. XOR with same number will give zero ans.
	// 2. All dublicate number will become zero and we are left with one number which is unique.
	private static int dublicateinarray1(int[] arr) {
		int a = arr[0];
		
		for (int i = 1; i < arr.length; i++) {
			a = a ^ arr[i];
		}
		return a;
	}
	
	
	 // Input 1 6 8 9 1 8 7 6 
	 //Output 9 7
	
	//In val1 and val2 are two variable that i will use to store output 
	static int val1 = 0;
	static int val2 = 0;
	
	private static int dublicateinarray2(int[] arr) {
		int a = arr[0];
		int no ;
		for (int i = 1; i < arr.length; i++) {
		
		// Here XOR of all set will give me 9 and 7 XOR which has value 14 
		
			a = a ^ arr[i];
		}
		
		//Here I will find rightmost set bit 
		// Why i am taking rightmost set bit beacuse if i get 0 Its means that two number must have that bit as (0 and 0) or ( 1 and 1) thats means it is has same value.
		// If i get 1 if means it has bit 0 and 1 which i will use to find my solution 
		no = a & ~(a-1);
		
		// Using value of no varible I will divide the array in two subsets 
		// It will divide 7 and 9 in two different subset 
		for (int i = 0; i < arr.length; i++) {
		
		       // In first subset will be of number where array element AND no is non-zero 
			if ((arr[i] & no)) !=0 {
				val1 = val1 ^ arr[i];
			}
			
			// In second subset will be of number where array element AND no is zero 
			else {
				val2 = val2 ^ arr[i];
			}
		}
	}
}
	
	//Time complexity for method one is O(n)
	//Time complexity for method two is O(2n)

