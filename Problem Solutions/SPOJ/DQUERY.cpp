
// Reference : https://qr.ae/TWK5WY

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const ll N=1e6;

struct node{
    int l=0,r=0,data=0; 
} seg[N];

int num=1,n,a[N],head_num=0;

// head_num denotes the head (root) node, for different versions of persistent seg tree
// update converts the given leaf index to zero 
// add creates new persistent seg tree with new head and rightmost element

void add(int prev,int head_num,int l,int r,int up){
    // prev: node at the same level in previous version of seg tree
    // haed_num : current node
    // up : (update point) index of leaf to be added

    // don't forget to update before returning
    ll mid = (l+r)/2;
    if(mid==l && up==l){
        // if left child of current node is the leaf child that needs to be added
        seg[head_num].r = seg[prev].r;
        seg[head_num].l = num++;
        seg[num-1].data = 1;
    }
    else if(mid+1==r && up==r){
        seg[head_num].l = seg[prev].l;
        seg[head_num].r = num++;
        seg[num-1].data = 1;
    }
    else if(up<=mid){
        // if the index to be updated lies in left subtree, the right subtree will be same as the previous version, so recursively build the left subtree.
        seg[head_num].r = seg[prev].r;
        seg[head_num].l = num++;
        add(seg[prev].l,seg[head_num].l,l,mid,up);
    }
    else{
        seg[head_num].l = seg[prev].l;
        seg[head_num].r = num++;
        add(seg[prev].r,seg[head_num].r,mid+1,r,up);
    }
        int left = seg[head_num].l,right = seg[head_num].r;
        seg[head_num].data = seg[left].data + seg[right].data;
}

void update(int head_num,int l,int r,int up){
    // haed_num : current node
    // up index of leaf to be deleted

    ll mid = (l+r)/2;
    if(mid==l && up==l){
        // if left child of current node is the leaf child that needs to be added, create a new node
        seg[head_num].l = num++;
        seg[num-1].data = 0;
    }
    else if(mid+1==r && up==r){
        seg[head_num].r = num++;
        seg[num-1].data = 0;
    }
    else if(up<=mid){
        // if the leaf node to be added will be found in left subtree, build it (note that changing just the leaf node won't help as some part of left subtree might be dependent on previous version, changing the leaf of which would affect the older version)
        seg[num] = seg[seg[head_num].l];
        seg[head_num].l = num++;

        // perform recursive update on left subtree.
        update(seg[head_num].l,l,mid,up);
    }
    else{
        seg[num] = seg[seg[head_num].r];
        seg[head_num].r = num++;

        update(seg[head_num].r,mid+1,r,up);

    }
        int left = seg[head_num].l,right = seg[head_num].r;
        seg[head_num].data = seg[left].data + seg[right].data;
}

ll query(int head_num,int l,int r,int ql,int qr){
    // classical seg tree query
    if(ql>r || qr<l)
        return 0;
    else if(ql<=l && qr>=r)
        return seg[head_num].data;
    ll mid = (l+r)/2;
    return query(seg[head_num].l,l,mid,ql,qr)+query(seg[head_num].r,mid+1,r,ql,qr);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n; map<int,int> _map;
    num = n+1;  // index 1 to n are for tree heads for versions from 1 to n
    for(int i=1;i<=n;i++){
        cin>>a[i];
        // in the head (head_num+1) that contains data from index range 0,n included, update the value of leaf index i to 1 using the segment tree with head (head_num)
        add(head_num, head_num+1,0,n,i);
        // in the head (head_num+1) that contains data from index range 0,n included, update the value of leaf index _map[a[i]] (i.e. the index of previous occurence of a[i]) to 0 using the segment tree with head (head_num)
        update(head_num+1,0,n,_map[a[i]]);
        //new head for later addition/updates
        head_num++;
        // change the index of last occurence of a[i]
        _map[a[i]] = i;
    }

    int q;  cin>>q;
    while(q--){
        int left, right;
        cin>>left>>right;
        // answer the query from the version 'right' which contains data for index range 0,n
        cout<<query(right,0,n,left,right)<<"\n";
    }

    return 0;
}
