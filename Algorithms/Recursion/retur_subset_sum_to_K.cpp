//Name:Anuj Goyal
//Email:anujg935@gmail.com

//This program is to return the subset array to the given array which sums to k
//the subset array which we return is a 2d array 
//the first element of each row of arra contains the size of the array

#include<iostream>
using namespace std;

//Program which returns the number of subset arays which sum to k
//here input[] is th input array
//output[][] is a output 2d array which is filled with subsets
int subsetSumToK(int input[], int n, int output[][50], int k) {
    //Base case of recursion
    //it is executed when the length of input array becomes zero 
	if(n==0){
		//when the sum to br find becomes equal to zero
		// returning 1 means that 1 subset is found
		if(k==0){
	    	output[0][0] = 0;
	    	return 1;
	    }
	    //if n==0 & k!=0 then this means that there is no subset of given array whose sum to k
	    //that's why returning zero
	    else{
	    	return 0;
	    }
	}
	
	int output1[1000][50];
	int output2[1000][50];
	//Now let's find the concept to sove the problem 
	//there are two ways that we can include the first element of input array to contribute to sum to k
	//or to not to contribute
	//both the cases gives the subsets whic we should accounts for
	
	//first element is contributing to sum to k
	int s1 = subsetSumToK(input+1,n-1,output1,k-input[0]);
	//first element is not contributing to sum to k
	int s2= subsetSumToK(input+1,n-1,output2,k);
	
	//in above two lines of codes the outputs are not recorded in given 2d output[][] array
	//they are stored in output1 and output2 local 2d arays
	 
	//the following lines of code will copy tse data in output1 and output2 array to given output array
	//with first element of each row being the size of that corresponding row
	 
	//this loop copies the connent in output array from output2 array 
	for(int i =0;i<s2;i++){      
	    for(int j = 1;j<=output2[i][0];j++){
	    	output[i][j] = output2[i][j];
	    }
	    output[i][0]=output2[i][0];
	}
	
	//this loop copies the connent in output array from output1 array
	//but in this case here is a difference from coppying from output2
	//in this case we also need to append the input[0] in the subset array and increase the size by 1 
	for(int i =0;i<s1;i++){
		//addin input[0] to 2nd element at index 1 of each row
		output[i+s2][1] = input[0];        
	    for(int j = 1;j<=output1[i][0];j++){
	    	output[i+s2][j+1] = output1[i][j];
	    }
	    output[i+s2][0]=output1[i][0]+1;
	  }
	
	//as s1 and s2 are number of subsets
	//so returning the total number of subsets   
	return s1+s2;
}

//Main function that drives the program
int main(){
	
	int number_of_elements;
	cout<<"Enter the number of numbers in array:";
	cin>>number_of_elements;
	int *arr = new int[number_of_elements];
	cout<<"Enter "<<number_of_elements<<" Elements"<<endl;
	for(int i=0;i<number_of_elements;i++){
		cin>>arr[i];
	}
	cout<<"Enter the Sum for which Subsets is to be found:";
	int k;
	cin>>k;
	
	int output[1000][50];
	int x =subsetSumToK(arr,number_of_elements,output,k);
	cout<<"Total number of subsets are : "<<x;
	
	cout<<"Following are the Subsets :"<<endl;
	
	for(int i=0;i<x;i++){
		for(int j=1;j<output[i][0];j++){
			cout<<output[i][j]<<" ";
		}
		cout<<endl;
	}
}
