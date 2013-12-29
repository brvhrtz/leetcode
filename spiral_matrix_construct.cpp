/*
 *  Spiral Matrix Construction 
 *
 * Algorithm:  Four-boundary algorithm 
               - keep track of boundaries only instead of keep track of visited nodes
   Gotcha: 
            1. the symetric way of fill [0 n-2] each time will leave a hole when there is only 1 element left
            2. the asymetric way of filling will have not this issue. 
 */

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        int left, right, top, bottom; // keep track of boundaries
        vector< vector<int> > res;
        vector<int> temp; 
        int i, j; 
        
        temp.clear(); 
        for(i = 0; i < n; i++)
        {
            for(j = 0; j<n; j++)
            {
                temp.push_back(0);
            }
            res.push_back(temp);
            temp.clear(); 
        }
        
        if(n <= 0) return res; 
        if(n == 1){
            res[0][0] = 1; 
            return res; 
        }
        
        left = 0; right = n-1; top = 0; bottom = n-1;
        int count=1; 
        
        // >
     while(left <= right && top <= bottom){
        for(j = left; j <= right; j++){
            res[top][j] = count++; 
        }
        // v
        for(i = top+1; i <= bottom; i++){
            res[i][right] = count++;
        }
        // <
        for(j = right-1; j>=left; j--){
            res[bottom][j] = count++;
        }
        // ^
        for(i = bottom-1; i>=top+1; i--){
            res[i][left] = count++; 
        }
        
        left = left+1; 
        right = right -1; 
        top = top +1;
        bottom = bottom -1; 
    }
    }
};
