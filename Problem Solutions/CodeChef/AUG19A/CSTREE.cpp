/*
 * https://www.codechef.com/AUG19A/problems/CSTREE
 * Subtask 1:
 * Reference 1: https://www.geeksforgeeks.org/total-number-spanning-trees-graph/
 * Reference 2: https://www.geeksforgeeks.org/adjoint-inverse-matrix/
 * Reference 3: https://www.geeksforgeeks.org/determinant-of-a-matrix/
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

const ll MOD = 998244353;
template<typename T>
T power(T x, T y, ll m = MOD) {
  T ans = 1;
  x %= m;
  while (y > 0) {
    if (y & 1LL) {
      ans = (ans * x) % m;
    }
    y >>= 1LL;
    x = (x * x) % m;
  }
  return (ans % m);
}

class Solution {
 private:
  // Function to get cofactor of A[p][q] in temp[][]. n is current
  // dimension of A[][] 
  void getCofactor(vector<vector<ll>> A, 
                  vector<vector<ll>> &temp, 
                  int p, int q, int n) {
    int i = 0, j = 0;

    // Looping for each element of the matrix 
    for (int row = 0; row < n; row++) {
      for (int col = 0; col < n; col++) {
        //  Copying into temporary matrix only those element 
        //  which are not in given row and column 
        if (row != p && col != q) {
          temp[i][j++] = A[row][col];

          // Row is filled, so increase row index and 
          // reset col index 
          if (j == n - 1) {
            j = 0;
            i++;
          }
        }
      }
    }
  }
  ll determinantOfMatrix(vector<vector<ll>> mat, int n) {
    ll num1, num2, det = 1, index, total = 1; // Initialize result   

    // temporary array for storing row   
    ll temp[n + 1];

    //loop for traversing the diagonal elements  
    for (int i = 0; i < n; i++) {
      index = i; // intialize the index   

      //finding the index which has non zero value   
      while (mat[index][i] == 0 && index < n) {
        index++;

      }
      if (index == n) // if there is non zero element   
      {
        // the determinat of matrix as zero   
        continue;

      }
      if (index != i) {
        //loop for swaping the diagonal element row and index row   
        for (int j = 0; j < n; j++) {
          swap(mat[index][j], mat[i][j]);
        }
        //determinant sign changes when we shift rows   
        //go through determinant properties   
        det = det * pow(-1, index - i);
      }

      //storing the values of diagonal row elements   
      for (int j = 0; j < n; j++) {
        temp[j] = mat[i][j];

      }
      //traversing every row below the diagonal element   
      for (int j = i + 1; j < n; j++) {
        num1 = temp[i]; //value of diagonal element   
        num2 = mat[j][i]; //value of next row element   

        //traversing every column of row   
        // and multiplying to every row   
        for (int k = 0; k < n; k++) {
          //multiplying to make the diagonal   
          // element and next row element equal   
          mat[j][k] = ((num1 * mat[j][k]) % MOD - (num2 * temp[k]) % MOD + MOD) % MOD;

        }
        total = (total * num1) % MOD; // Det(kA)=kDet(A);   
      }

    }

    //mulitplying the diagonal elements to get determinant   
    for (int i = 0; i < n; i++) {
      det = (det * mat[i][i]) % MOD;
    }
    // return (det / total); //Det(kA)/k=Det(A);   
    return (det * power(total, MOD - 2)) % MOD;
  }
  // Function to get adjoint of A[0][0] 
  ll adjoint(vector<vector<ll>> A, int n) {
    if (n == 1) {
      return 1;
    }

    // temp is used to store cofactors of A[][] 
    int sign = 1;
    vector<vector<ll>> temp(n, vector<ll>(n));

    // Get cofactor of A[i][j] 
    getCofactor(A, temp, 0, 0, n);

    // sign of adj[j][i] positive if sum of row 
    // and column indexes is even. 
    sign = ((0 + 0) % 2 == 0) ? 1 : -1;

    // Interchanging rows and columns to get the 
    // transpose of the cofactor matrix 
    return (sign) * (determinantOfMatrix(temp, n - 1));
  }

 public:
  ll solve(int n, int m, int K, vector<vector<ll>> adj) {
    // subtask 1: k <= 10
    vector<vector<ll>> h(K*n, vector<ll>(K*n, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        h[i][j] = adj[i][j];
        if (h[i][j] == 1) {
          for (int k = 0; k < K; ++k) {
            int u = i + k*n;
            int v = j + k*n;
            h[u][v] = 1;
          }
        }
      }
    }
    // complement
    for (int i = 0; i < K*n; ++i) {
      for (int j = 0; j < K*n; ++j) {
        if (h[i][j] == 1) {
          h[i][j] = 0;
        } else {
          h[i][j] = 1;
        }
      }
    }

    // replace all diagonal entries by degree of nodes
    for (int i = 0; i < K*n; ++i) {
      int cnt = 0;
      for (int j = 0; j < K*n; ++j) {
        if (i == j) {
          continue;
        }
        if (h[i][j] == 1) {
          ++cnt;
        }
      }
      h[i][i] = cnt;
    }
    // replace all non-diagonal ones by -1
    for (int i = 0; i < K*n; ++i) {
      for (int j = 0; j < K*n; ++j) {
        if (i != j && h[i][j] == 1) {
          h[i][j] = -1;
        }
      }
    }

    /*/
    for (int i = 1; i < K*n; ++i) {
      for (int j = 1; j < K*n; ++j) {
        cerr << h[i][j] << " ";
      }
      cerr << endl;
    }
    cerr << endl;
    //*/

    // calculate cofactor of (0, 0)
    ll cofactor = adjoint(h, K*n);
    // cerr << cofactor << endl;
    return cofactor;
  }
};

int main() {
  FAST_IO;
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n, m, k;
    cin >> n >> m >> k;

    int a, b;
    vector<vector<ll>> adj(n, vector<ll>(n, 0));
    for (int j = 0; j < m; ++j) {
      cin >> a >> b;
      --a;
      --b;
      adj[a][b] = 1;
      adj[b][a] = 1;
    }

    Solution solver;
    cout << solver.solve(n, m, k, adj) << endl;
  }
  
  return 0;
}