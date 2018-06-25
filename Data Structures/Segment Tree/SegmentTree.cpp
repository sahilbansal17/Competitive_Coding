/*Segment tree is used for storing different intervals of an array.
It involves three functions - build ,update and query.
For example- to get sum of a given range of an array segment tree is used.*/

#include<bits/stdc++.h>
using namespace std;

void build(int a[],int tree[],int start,int end,int node){
  
  //base case
  if(start==end){
      tree[node]=a[start];
      return;
  }
  //dividing into intervals
  int mid=(start+end)/2;
  //recursive call for left subtree(2*node) and right subtree(2*node+1)
  build(a,tree,start,mid,2*node);
  build(a,tree,mid+1,end,2*node+1);
  //Internal node will have the sum of both of its children
  tree[node]=tree[2*node]+tree[2*node+1];
}


void update(int tree[],int a[],int start,int end,int indx,int node){
    
    //updating value of the node which contains the value of a[indx] whose value has been changed
    if(start==end){
        tree[node]=a[start];
    }
    else{
        int mid=(start+end)/2;
        if(start<=indx and indx<=mid) {
            //if indx is in the left subtree, recurse on left subtree
            update(tree,a,start,mid,indx,2*node);
        }
        else{
            //if indx is in the right subtree, recurse on right subtree
            update(tree,a,mid+1,end,indx,2*node+1);
        }
        //Internal node will have the sum of both of its children
        tree[node] = tree[2*node]+tree[2*node+1];
    }
    
}

int query(int tree[],int start,int end,int l,int r,int node){
    
    //no overlap of asked range and node range 
    if(r<start || end<l){
        return 0;
    }
    if(l<=start && end<=r){
    //complete overlap of asked range and node range
        return tree[node];
    }
    //partial overlap of asked range and node range
    int mid=(start+end)/2;
    int s1=query(tree,start,mid,l,r,2*node);
    int s2=query(tree,mid+1,end,l,r,2*node+1);
    return (s1+s2);

}
    
int main(){ 
  //n for size of array and l,r for range interval whose sum is to be found
  //the tree array will have n leaf nodes which will have the array elements when l=r and n-1 internal nodes so its size is 2n-1
  int n;
  cin>>n;
  int a[n+1],tree[2*n],l,r;
  for(int i=1;i<=n;i++)
    cin>>a[i];
 
  //recursive function to build the tree with all array elements(1 to n) starting with first node
  build(a,tree,1,n,1);
 
  //indx for index of the array whose new value is updated to val
  int indx,val;
  cin>>indx>>val;
  a[indx]=val;
  update(tree,a,1,n,indx,1);
  
  cin>>l>>r;
  //sum of given range
  int ans=query(tree,1,n,l,r,1);
  cout<<ans;
  return 0;
}
/*
Time complexity:
  build function-since it is needed to assign values to all the 2n-1 nodes of the tree it has O(2n-1) i.e O(n) complexity.
  update function-the required index is either in left subtree or right subtree so at each level the search is reduced by two resulting in O(logn) complexity
  query function- at each level the range is reduced by 2 using mid making the overall worst case complexity to O(logn) 
*/
