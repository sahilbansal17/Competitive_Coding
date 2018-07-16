//Name:Anuj Goyal
//Email:anujg935@gmail.com

//This program is to print the subset of given array whose sum is given

#include<iostream>

using namespace std;


//printSubsets() is a helper function 
//this function breaks the input array in two parts 
//i.e including the 1st element of array in the sum and excluding it from the sum
void printSubsets(int input[],int n, int output[],int m,int k){
	//base case for recursive function
	//checks if the size of infput array is empty or not
	if(n==0){
		//checks if the sum is reduced to zero or not
    	if(k==0){
    		//ifthe input array is empty and the sum is zero 
    		//then we need to print the subset which is stored in output[] array
      		for(int i=0;i<m;i++){
      			cout<<output[i]<<" ";
      		}
      		cout<<endl;
      		return;
    	}
    	//this else is for the condition when the input array is empty 
		//but the sum to be computed is still not zero
		//in that case we need to return zero as in that case we don't get any subset for given sum
    	else{
    		return;
    	}
  	}	
  	
  	//recursive call to the input array by excluding first element of input array and same value of k
  	//this means that we are not including the first element of input array to compute the given sum k
	printSubsets(input+1,n-1,output,m,k);
  	
  	//creating the temporary array of size m+1
	int newarr[m+1];
	
	//putting the existing values of output array in temporary newarr[] array
	for(int i=0;i<m;i++){
    	newarr[i]= output[i];
  	}
  	//putting the 1st element of the input array in the newarr[] array
	newarr[m] = input[0];
	
	//recursive call to small input array i.e 1 element less with less sum to be computed 
	//i.e included the lement zero in the sum
	printSubsets(input+1,n-1,newarr,m+1,k-input[0]);
}

//printSubsetSumToK () function takes input parameters and 
//calls another helper function with additional parameter of output array
//output array helps in the printng of the subset which is temporary memory
void printSubsetSumToK(int input[], int size, int k) {
	
  	//temporary arra which stores the temporary subset of the array of summ equal to k
  	//this array helps ijn printing of subsets
	int output[size];
	//Calls the helper function
	printSubsets(input, size, output, 0,k);
	return;
}

//Main function that drives the program
int main()
{
	int number_of_elements;
	cout<<"Enter the number of numbers in array:";
	cin>>number_of_elements;
	//input array
	int *arr = new int[number_of_elements];
	cout<<"Enter "<<number_of_elements<<" Elements"<<endl;
	for(int i=0;i<number_of_elements;i++){
		cin>>arr[i];
	}
	//Ask User for the value of k i.e whose sum is to be computer
	int k;
	cout<<"Enter the value of k :";
	cin>>k;
	//calling ths function with 3 parameters 
	//1st parameter is array 2nd is the size of array and 3rd is the sum for which the subsets are to be printed
	printSubsetSumToK(arr, number_of_elements, k);
}


//Time complexity
	//the time complexity of this program is O(2^n) because for every element of the array, we have 2 kinds of options, either to include it or to exclude it.
