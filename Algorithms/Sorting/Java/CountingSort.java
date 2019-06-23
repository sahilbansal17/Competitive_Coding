//  Counting Sort in java

class CountingSort { 
  static  void sort(char arr[]) 
    { 
        int n = arr.length; 
  
       //Array to store the final sorted array.
        char out[] = new char[n]; 
  
       //A new array to store the number of occurrences of a character.
        int c[] = new int[256]; 
        for (int i = 0; i < 256; ++i) 
            c[i] = 0; 
  
        //Adding the count of each element.
        for (int i = 0; i < n; ++i) 
            ++c[arr[i]]; 
  
       //Stores real position of element.
        for (int i = 1; i <= 255; ++i) 
            c[i] += c[i - 1]; 
  
       //Building the final sorted array.
        for (int i = 0; i < n; ++i) { 
            out[c[arr[i]] - 1] = arr[i]; 

            //Decreasing the count of the element which is positioned correctly.
            --c[arr[i]]; 
        } 
  
       
        for (int i = 0; i < n; ++i) 
           arr[i] = out[i]; 
    } 
  
    // Driver method 
    public static void main(String args[]) 
    { 
       
        char a[] = {'a','f', 'd','j','w','i'}; 
  
        //sort function is called which sorts the array.
        sort(a);
                    
  
        //Printing the sorted array.
        for (int i = 0; i < a.length; i++) 
            System.out.println(a[i]); 
    } 
} 

//Time Complexity -  O(n+k) where n is the number of elements in input array and k is the range of input.

//Space Comlexity: O(n+k)