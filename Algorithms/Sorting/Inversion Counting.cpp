#include <bits/stdc++.h>
using namespace std;
int mergesort(int arr[],int temp[],int low,int high);
int merge(int arr[],int temp[],int low,int mid,int high);
void inversions(int arr[],int n)
{
    int temp[n];
    int count=mergesort(arr,temp,0,n-1);
    cout<<"No of inversions: "<<count<<endl;
}

int mergesort(int arr[],int temp[],int low,int high)
{
    int count =0;
    if(low<high)
    {
    int mid=(low+high)/2;
    count=mergesort(arr,temp,low,mid);
    count+=mergesort(arr,temp,mid+1,high);
     count +=merge(arr,temp,low,mid,high);
    } 
return count;
}

int merge(int arr[],int temp[],int low,int mid,int high)
{
    int count=0;
    int i=low;
    int j=mid+1;
    int k=low;
    while(i<=mid&&j<=high)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++]; 
        }
        else
        {
            temp[k++]=arr[j++];
            count+=mid-i+1;
    
        }
    }
    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }
    while(j<=high)
    {
        temp[k++]=arr[j++];
    }
for(int a=low;a<=high;a++)
{
  arr[a]=temp[a];
}

     return count;
}

int main() {
    int arr[] = { 1, 20, 6, 4, 5 }; 
   int len =sizeof(arr)/sizeof(arr[0]);
   inversions(arr,len);
   //sorted array
   cout<<"sorted array:"<<endl;
   for(int i=0;i<len;i++)
   cout<<arr[i]<<" ";
   return 0;
}
