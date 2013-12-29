/*
 * Word search in Matrix
 * Algorighm: 
      1. a complex but still straightfoward backtracking
      2. The jump of faith happens when I found that I can reuse board itself as an visited matrix
         2.1 To achieve this, set it to '\0' after visit and revert it back if things don't work out 
      3. To reduce conditioning convolution 
         3.1 only make decision concerning current position 
         3.2 only do mem check conditioning before going to next step 
         3.3 leave all decision concerning next pos to the next step  
 */


#define VISITED '\0'
class Solution {
public:
    bool backtrack(vector< vector<char> > &board, string word, int k, int M, int N, int i, int j)
    { // backtracking from (i, j)
       char temp; 
       
       if(i>M-1 || j>N-1 || board[i][j] != word[k]) return false; 
       if(k==word.size()-1 && board[i][j] == word[k]) return true; 
       // right
       if(j+1 <=N-1){
           temp = board[i][j]; board[i][j] = VISITED;  
           if(backtrack(board, word, k+1, M, N, i, j+1)) return true;
           else board[i][j] = temp; 
       }
       // down
       if(i+1 <= N-1){
           temp = board[i][j]; board[i][j] = VISITED;  
           if(backtrack(board, word, k+1, M, N, i+1, j)) return true;
           else board[i][j] = temp; 
       }
       // left
       if(j-1 >= 0){
           temp = board[i][j]; board[i][j] = VISITED;  
           if(backtrack(board, word, k+1, M, N, i, j-1)) return true;
           else board[i][j] = temp; 
       }
       // up
       if(i-1 >= 0){
           temp = board[i][j]; board[i][j] = VISITED;  
           if(backtrack(board, word, k+1, M, N, i-1, j)) return true;
           else board[i][j] = temp; 
       }
       return false;  // tried all direction and failed;
    }
    
    bool exist(vector<vector<char> > &board, string word) {
        int M, N; //bound
        int i, j; // numerical iters
        
        if(board.size() ==0) return false; 
        M = board.size();    // rows
        N = board[0].size(); // cols
        
        bool visited[M][N];
        for(i = 0; i<M; i++)
        {
            for(j = 0; j<N; j++)
            {
                if(backtrack(board, word, 0, M, N, i, j)) return true; 
            }
        }
        return false; // tried all positions 
    }
};
