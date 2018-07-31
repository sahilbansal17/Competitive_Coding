class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
  		int rows = A.size();
  		int cols = A[0].size();

  		vector <vector <int > > a_transpose(cols, vector <int> (rows));
  		for(int i = 0; i < rows; i ++){
  			for(int j = 0; j < cols; j ++){
  				a_transpose[j][i] = A[i][j];
  			}
  		}      

  		return a_transpose;
    }
};