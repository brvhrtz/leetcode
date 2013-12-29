#define pMax  0x7fffffff
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {

         int i, j; 
         int M, N; 
         int dc, rc; // down path cost, right path cost
         
         if(grid.size() ==0) return 0; 
         
         M = grid.size(); 
         N = grid[0].size(); 
         for(j = N-1; j>=0; j--){
             for(i = M-1; i>=0; i--){
                 dc = pMax; rc = pMax;  
                 if(i == M-1 && j == N-1) continue;
                 if(i+1 <= M-1) dc = grid[i+1][j];
                 if(j+1 <= N-1) rc = grid[i][j+1];
                 grid[i][j] = grid[i][j] + std::min(dc, rc);
             }
         } 
         return grid[0][0];
    }
};
