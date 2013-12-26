/*
 * Leetcode: Sudokku Soler 
 * 
 * Gain:
      1. first backtracking mission completed. Good start to brush over this important genre of algorithm
      2. Backtracking seems essentially is a traveral of all possible solution with O(N) space complexity 
      3. Backtrack has the same complexity of a brutal-force Test-N-Go  algorithm
      4. Intelligently define boundary/checkers can save some computation by return early.
      5. the basic structure of a backtracking algorithm is 
         -In each possible 1st bracket filler test if the 2nd bracket will be cool 
          where all possible fillers for the second filler will be tested agains the 3rd
          and so on
          
        solved
        {
          (test if a complete solution is reached)
          if yes return true; 
          if not
          {
            find_next_empty_bracket
            test each possible fillers for the found bracket
            {
              test if "solved" with the chosen filler
              if yes return true; 
              if not return false and reset and give the upper point a chance to test another filler; 
            }
          }
        }
      6. Remember the following fan-out graph
         -The worst complexity is   9 * 9 ... *9 = 9^(N*N) as each bracket can have 9 possiblility and has to be checked
          which is as worst as it can get
          
      -> (0,0) = 1   ->  (0,1) = 1  -> (0,2) = 1
                                             ...
                                             = 9
                               ...
                               = 9  -> (0,2) = 1
                                             ...
                                             = 9        
               ...
               = 9   ->  (0,1) = 1  -> (0,2) = 1
                                             ...
                                             = 9
                               ...
                               = 9  -> (0,2) = 1
                                             ...
                                             = 9
             
      
      
 */
class Solution {
public:
    bool isValid(vector<vector<char> > &board, char tc, int row, int col)
    {
        int i, j;

        // clear row
        for(j = 0; j < 9; j++)
        {
          if(board[row][j] == tc) return false; 
        }  
        
        // clear col
        for(i = 0; i < 9; i++)
        {
            if(board[i][col] == tc) return false; 
        }
        
        // clear square
        int x0 = (row/3)*3; // x origin
        int y0 = (col/3)*3; // y origin
        for(i = x0; i < x0+3; i++)
          for(j = y0; j < y0+3; j++)
          {
              if(board[i][j] == tc) return false;
          }
          
        // all clear return true; 
        return true; 
    }
    
    
    bool solved(vector< vector<char> > &board)
    {
        int i, j;
        char tc;  // test char for empty spaces
      
      for(i = 0; i < 9; i++)
      {
          for(j = 0; j < 9; j++)
          {// found next eampty bracket
              if(board[i][j] == '.')
              {
                  for(tc = '1'; tc <'9'+1; tc++)
                  {
                      
                      if(!isValid(board, tc, i, j)) continue;
                      board[i][j] = tc;
                      if(solved(board)) return true;
                  }
              board[i][j] = '.';  // back tracking 
              return false; 
              }
          }
      }
      return true; // full board, solution arrived
    }
    
    void solveSudoku(vector<vector<char> > &board) {
        solved(board);
    }
};
