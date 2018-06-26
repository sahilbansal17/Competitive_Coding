#include <bits/stdc++.h>
#include <vector>
#include<stdio.h>
#define ll long long int
using namespace std;
void sumsub(vector< vector<ll> > &A, vector< vector<ll> > &B, vector< vector<ll> > &C, ll m, char s) {
    ll i, j;
    if(s=='-'){
        for (i = 0; i < m; i++) {
            for (j = 0; j < m; j++) {
                C[i][j] = A[i][j] - B[i][j];
            }
        }
    }
    else{
        for (i = 0; i < m; i++) {
            for (j = 0; j < m; j++) {
                C[i][j] = A[i][j] + B[i][j];
            }
        }   
    }      
}

void product(vector< vector<ll> > A, vector< vector<ll> > B, vector< vector<ll> > &C, ll n) {
    ll i, j, k;
    C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
}
void spilt(vector< vector<ll> > &a11, vector< vector<ll> > &a12, vector< vector<ll> > &a21, vector< vector<ll> > &a22, vector< vector<ll> > &A, ll s){
    ll i, j;
    for (i = 0; i < s; i++) {
            for (j = 0; j < s; j++) {
                a11[i][j] = A[i][j];
                a12[i][j] = A[i][j + s];
                a21[i][j] = A[i + s][j];
                a22[i][j] = A[i + s][j + s];
        }
    }    
}
void join(vector< vector<ll> > &a11, vector< vector<ll> > &a12, vector< vector<ll> > &a21, vector< vector<ll> > &a22, vector< vector<ll> > &A, ll s){
    ll i, j;
    for (i = 0; i < s ; i++) {
            for (j = 0 ; j < s ; j++) {
                A[i][j] = a11[i][j];
                A[i][j + s] = a12[i][j];
                A[i + s][j] = a21[i][j];
                A[i + s][j + s] = a22[i][j];
            }
        }
}
void SM(vector< vector<ll> > &A, vector< vector<ll> > &B, vector< vector<ll> > &C, ll m) {
    if (m <= 2) {
        product(A, B, C, m);
        return;
    }
    ll s= m/2;
    vector<ll> n (s);
    vector< vector<ll> > a11(s,n), a12(s,n), a21(s,n), a22(s,n), b11(s,n), b12(s,n), b21(s,n), b22(s,n),c11(s,n), c12(s,n), c21(s,n), c22(s,n), p1(s,n), p2(s,n), p3(s,n), p4(s,n), p5(s,n), p6(s,n), p7(s,n), A1(s,n), B1(s,n);
 
        ll i, j;
        spilt(a11,a12,a21,a22,A,s);
        spilt(b11,b12,b21,b22,B,s);

        sumsub(a11, a22, A1, s, '+');
        sumsub(b11, b22, B1, s, '+');
        SM(A1, B1, p1, s);

        sumsub(a21, a22, A1, s, '+');
        SM(A1, b11, p2, s);
        sumsub(b12, b22, B1, s, '-');
        SM(a11, B1, p3, s);

        sumsub(b21, b11, B1, s, '-');
        SM(a22, B1, p4, s);
        sumsub(a11, a12, A1, s, '+');
        SM(A1, b22, p5, s);   
 
        sumsub(a21, a11, A1, s, '-');
        sumsub(b11, b12, B1, s, '+');
        SM(A1, B1, p6, s);

        sumsub(a12, a22, A1, s, '-');
        sumsub(b21, b22, B1, s, '+');
        SM(A1, B1, p7, s);
    
 
        sumsub(p3, p5, c12, s, '+');
        sumsub(p2, p4, c21, s, '+');
 
        sumsub(p1, p4, A1, s, '+');
        sumsub(A1, p7, B1, s, '+');
        sumsub(B1, p5, c11, s, '-');
 
        sumsub(p1, p3, A1, s, '+');
        sumsub(A1, p6, B1, s, '+');
        sumsub(B1, p2, c22, s, '-');
 
        join(c11, c12, c21, c22, C ,s);
    }
    
int main(){
    ll t ,i ,j ,k, q ,n;
    cin>>t;
    for(k=0;k<t;k++){
        scanf("%lld",&n);
        vector<ll> x (n);
        vector< vector<ll> > A(n, x), B(n, x), C(n, x);
        
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%lld",&q);
                A[i][j]=q;
            }
        }
        
        SM(A, A, C, n);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cout<<C[i][j]<<" ";
            }
            cout<<endl;
        }

    }
return 0;
}
//From Master's Theorem, time complexity is O(N^Log7) which is approximately O(N^2.8074)