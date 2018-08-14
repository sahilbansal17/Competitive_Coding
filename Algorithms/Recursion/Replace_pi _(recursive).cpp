//Name:Anuj Goyal
//Email:anujg935@gmail.com

//the problem statement of this program is as follows:-
//Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

#include<iostream>

using namespace std;

// helper function of replacePi() function with additional length parameter
void replace(char input[],int len){
	//base case if length is less than or equal to one than no need to do anuthing just return
	if(len<=1)
    	return;
	
	//checking for the condition if "pi" is in the string  
	if(input[0]=='p'&&input[1]=='i'){
		//shifting the array with 2 for adding 3.14 in array
    	for(int i =len;i>=2;i--){
      		input[i+2]= input[i];
    	}
    	
    	//putting the values 3.14 
    	input[0]='3';
    	input[1]='.';
    	input[2]='1';
    	input[3]='4';
    	//calling recursion
    	replace(input+1,len+1);
  	}
  	//calling recursion
  	replace(input+1,len-1);
}

//replacePi() function takes the char array and replaces every "pi" with 3.14 
void replacePi(char input[]) {
	
	int len = 0;
    int i =0;
    //using while loop getting the length of the string
    while(input[i] !='\0'){
      len++;
      i++;
    }
    //calling helper function with length paramaeter
    replace(input,len);
}

int main()
{
	//for taking string xpix as demo for testing
	char input[1000] = "xpix";
	replacePi(input);
	int i=0;
	while(input[i] !='\0'){
      cout<<input[i];
      i++;
    }
	cout<<endl;
}
