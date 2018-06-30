#include<iostream>
#include<vector>

using namespace std;

vector<int> maxSubArray(const vector<int> &A)
{
    int maxx=INT_MIN,sum=0,i,l=0,r=0,dif=INT_MAX,low_index;
    if(A.size()==1)
        maxx=A[0];
    else
    {
        int n=A.size();
        int c=0;
        //check if all elements are negative
        for(i=0;i<n;i++)
        {
            if(A[i]>0)break;
            else c++;
        }
        //if all elements are negative,maximum sum is the maximum number in the array
        if(c==n)
        {
            maxx=A[0];l=0;r=0;
            for(i=1;i<n;i++)
            {
                if(A[i]>maxx)
                {
                     maxx=A[i];
                    l=i;
                    r=i;
                }
            }
        }
        else
        { int start;
            //iterate through all elements
            for(i=0;i<n;i++)
            {
                 // initialize sum
                 if(sum+A[i]<=0)
                 {
                     sum=0;
                     l=i+1;
                 }
                 // add if the sum is positive
                else if(sum+A[i]>0)
                 {
                    sum+=A[i];
                    //update max sum if it is less than current sum
                    if(maxx<sum)
                    {
                        maxx=sum;
                        r=i;
                        start=l;
                        //storing subarray length and lower index
                        dif=r-l;
                    }
                    // choosing smaller segment length if more than one subarrays have maximum sum
                    else if(maxx==sum)
                    {
                        if(i-l<dif)
                        {
                            r=i;
                            start=l;
                            dif=i-l;
                        }
                        //choosing lowest index if subarray lengths are same.
                        else if((i-l)==dif)
                        {
                            if(l<start)
                            {
                                r=i;
                                start=l;
                                dif=i-l;
                            }
                        }
                    }
                }
            }
             l=start;
        }
    }
    vector<int> ret;
    ret.push_back(l);
    ret.push_back(r);
    ret.push_back(maxx);
    return ret;
}
int main()
{
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    vector <int> a(n);
    cout<<"Enter elements"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<int> res=maxSubArray(a);
    cout<<"Maximum contiguous subarray sum is "<<res[2]<<" between indices "<<res[0]<<" and "<<res[1];

}
//Time complexity: O(n) since the algorithm involves only one can of the array
