/*
 * Unique path from top-left corner to bottom-right corner
 * This commit include both the recursive and the DP version 
 *
 * Gotcha: 
      - the recursive version is correct but not optimized, so there is redundant computation there
      - the DP version is good, note that the sweeping sequence has to be    bottom up and then left and then bottom up
        otherwise DP might have un-settled parent node. 
 */

class Solution {
public:
    int helper(int left, int top, int m, int n)
    {
        if(left == n && top == m) return 1; // termination 
        if(left > n || top > m) return 0; // out of bound
        
        int gright, gdown;
        gright = gdown = 0; 
        gright = helper(left+1, top, m, n);
        gdown = helper(left, top+1, m, n);
        return gright+gdown; 
    }
    int uniquePaths(int m, int n) {
        if(m ==0 || n == 0) return 0;
        
        int npath[m][n]; 
        memset(npath, 0, sizeof(int)*m*n);
        
    //    npath[m-1][n-1] = 1;
        int i, j; 
        for(j = n-1; j>=0; j--){
            for(i = m-1; i>=0; i--){
                if(i==m-1 && j==n-1) npath[i][j] = 1; 
                if(i+1 <m && j+1 <n) npath[i][j] = npath[i+1][j] + npath[i][j+1];
                if(i+1 <m && j+1 >=n) npath[i][j] = npath[i+1][j];
                if(i+1 >=m && j+1 <n) npath[i][j] = npath[i][j+1];
            }
        }
        return npath[0][0];
        // return helper(0, 0, m-1, n-1);
    }
};
