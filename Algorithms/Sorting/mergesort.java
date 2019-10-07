import java.util.Scanner;

public class mergsort {
	@SuppressWarnings("resource")
	public static int[] takeInput() {
		Scanner s = new Scanner(System.in);
		int size = s.nextInt();
		int arr[] = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = s.nextInt();
		}
		return arr;
	}
	
	public static void printArray(int input[]) {
		for(int i = 0; i < input.length; i++) {
			System.out.print(input[i] + " ");
		}
	}
	
	public static void main(String[] args) {
		int[] input = takeInput();
		mergeSort(input);
		printArray(input);
	}
/*********************************************/
public static void merge(int[] input,int s,int m,int e){  
         int i,j;
         int l=m-s+1;
         int p=e-m;
         int arr[]=new int[l];
         int arr2[]=new int [p];
        
        for(i=0;i<l;i++){
            arr[i]=input[s+i];
        }
        for(i=0;i<p;i++){
            arr2[i]=input[m+1+i];
        }
        i=0;
        j=0;
        int k=s;
        while(i<l&&j<p){
             if(arr[i]<=arr2[j]){
                input[k]=arr[i];
                i++;
             }
           else{
               input[k]=arr2[j];
               j++;
        }k++;
    }
         while (i < l) 
    { 
        input[k] = arr[i]; 
        i++; 
        k++; 
    } 
  
       while (j < p) 
    { 
        input[k]=arr2[j]; 
        j++; 
        k++; 
    } 
        
} 
            
   public static void sort(int[] input,int s,int e){
		if(s>=e){
            return ;
         }   
             int m=(s+e)/2;
               sort(input,s,m);
               sort(input,m+1,e);
               merge(input,s,m,e);
	}

    
	public static void mergeSort(int[] input){
		   sort(input , 0 ,input.length-1);
         }
}
