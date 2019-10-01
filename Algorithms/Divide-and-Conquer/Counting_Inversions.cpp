#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<limits.h>
int mergeAndCountInv(long long int a[],long long int p,long long int q,long long int r)
{
    long long int L[q-p+2], R[r-q+1], i,j;
    for(i=0;i<q-p+1;i++)
    {    L[i] = a[p+i];
         //printf("%lld ", L[i]);
    }
    for(j=0;j<r-q;j++)
        R[j] = a[q+1+j];
    L[q-p+1]=LONG_MAX;
    R[r-q]=LONG_MAX;
    long long int left=0,right=0,inv_count=0;
    for(int i=p;i<=r;i++)
    {
        if(L[left] <= R[right])
        {
            a[i] = L[left];
            left++;
        }
        else{
            a[i] = R[right];
            right++;
            inv_count += q-p-left+1;
        }
    }
    return inv_count;
}

int mgSortAndCountInv(long long int a[], long long int p, long long int r)
{
    if(p<r)
    {
        long long int q = (p+r)/2, l_cnt_inv, r_cnt_inv, cross_inv;
        l_cnt_inv = mgSortAndCountInv(a,p,q);
        r_cnt_inv = mgSortAndCountInv(a,q+1,r);
        cross_inv = mergeAndCountInv(a,p,q,r);
        return (l_cnt_inv + r_cnt_inv + cross_inv);
    }
    else
        return 0;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--)
    {
        long long int n,i;
        scanf("%lld", &n);
        long long int a[n];
        for(i=0;i<n;i++)
        {
            scanf("%lld ", &a[i]);
        }
        printf("%d\n", mgSortAndCountInv(a,0,n-1));
    }
    return 0;
}
