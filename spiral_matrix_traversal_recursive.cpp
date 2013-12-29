/*
 * Spiral matrix traversal
 * 
 * Algorithm: 
 *    again algorithm is straightfoward, however, use visited matrix is memory intensive
 *    - note that we actually know exactly where to go at each step. 
      - follow the pattern we don't need to keep track of visited node
      - if you think this problem as a recursive one, it is immediately became obvious that no visited matrix is needed
 * Gain:
      - forward/backward linear sweep  -> 
        DP ->
        divide and conquer -> 
        backtracking -> 
        recursive->
        brutal force but with a lot of conditions
 */


#include <iostream>
#include <vector> 
#include <cstring>

using namespace std;

class Solution {
public:
    void spiral(vector< vector<int> > &matrix, vector<int> &res, int x0, int y0, int M, int N)
    {
      // x, y is the upper-left coordinate
      // m, n is row and columns
      // res is where the returned value will be stored
      int i, j;
      if(M <= 0 || N <= 0) return; 
      if(M == 1){
          for(j = y0; j< y0+N; j++) res.push_back(matrix[x0][j]);
          return; 
      }
      if(N == 1){
          for(i = x0; i < x0+M; i++) res.push_back(matrix[i][y0]);
          return; 
      }
      for(j = y0; j <= y0+N-1; j++) {// 0 to N-1 at row 
          res.push_back(matrix[x0][j]);
      }
      for(i = x0+1; i <= x0+M-1; i++){// 1 to M-1 at col N-1
          res.push_back(matrix[i][y0+N-1]);
      }
      for(j = y0+N-2; j >= y0; j--){ // M-2 to 0 at row 
          res.push_back(matrix[x0+M-1][j]);
      }
      for(i = x0+M-2; i >= x0+1; i--){
          res.push_back(matrix[i][y0]);
      }
      spiral(matrix, res, x0+1, y0+1, M-2, N-2);
      return; 
    }
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
      // 4 boundary 
      // no need to mark visited node as at every pos, you know exactly where next step should be
      // This problem if you think it as a recursive problem, you will get more comfortable 
      // This algorithm is actually a unwrapped recursive approach
      vector<int> res; 
      if(matrix.size() == 0) return res;
      
      int M; 
      M = matrix.size(); 
      int N;  
      N = matrix[0].size();
      spiral(matrix, res, 0, 0, M, N); 
      
    }
};

int main()
{
   cout << "Hello World" << endl; 
   vector< vector<int> > a; 
   a[0][0] = 5;
   
   Solution sol; 
   sol.spiralOrder(a);
   return 0;
}
