#include<bits/stdc++.h>
using namespace std;

float calculateSquareRoot(int num,int p){
    //square root of a number can be minimum 0 and maximum be number itself(i.e 1)

    float ans;
    // firstly computing the integer part
    //computing integer part by applying binary search
    int start = 0, end = num;

    while(start <= end){
        int mid = (start + end)/2;
        if((mid * mid) == num){
            ans = mid;
            break;
        }
        else if((mid * mid) < num){
            // storing ans so that any change later will be updated if any number greater than current mid
            // such next greater square is still less than number
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }

    // computing the fractional part
    // because a fractional part for every level of precision ranges from .1 to .9 or .01 to .09 etc
    float inc = 0.1;
    // looping over the no of precision
    for(int i = 0; i < p; i++){
        ans += inc;
        // for each level of precision checking the ans
        while((ans * ans) <= num){
            ans += inc;
        }
        // to remove the extra increment for which ans*ans > num
        ans -= inc;
        inc = inc/10;
    }

    return ans;
}

int main(){
    // input the number and precision
    int num,p;
    cout << "Enter the number and the no of precision to which you want to compute square root" << endl;
    cin >> num >> p;

    //calling the function
    cout << "The square root of " << num << " upto "<< p <<" precision is " << calculateSquareRoot(num,p) << endl;
    return 0;
}

/*Time Complexity of the above code is calcluated 
  Total time = time to compute integer part + time to compute fractional part
             = O(log n) + time to compute fractional part
  for integer part as it is a binary search therefore complexity is O(logn)
  for fractional part for computing each precision we require a constant time
  therefore for p precision we require k*p time where k is a constant
  So total time = O(log n) + k*p 
  but k is constant and p is limited upto 8 to 9 in case of storage capacity inside machine
  so therefore overall the term will be constant and which can be ignored therefore
  the complexity can be considered to be O(log n)
*/
