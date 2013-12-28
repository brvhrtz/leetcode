class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res; 
        
        // bondary check
        if(matrix.size() == 0) return res; 
        
        int M = matrix.size(); //
        int N = matrix[0].size(); // assuming all rows has same num of columns
        bool visited[M+2][N+2]; 
        bool done;
        int dir; // direction, rotate btw 0 ->, 1 V, 2 <-, 3 ^
        int i, j; // numerical iterators
        
      
        memset(visited, 0, sizeof(bool)*(M+2)*(N+2)); // start visited mtrx, all false
        for(j=0; j<N+2; j++) {visited[0][j] = true; visited[M+1][j] = true; }
        for(i=0; i<M+2; i++) {visited[i][0] = true; visited[i][N+1] = true; }
        
        dir = 0; // starting dir ->
        i =1; j = 1; // start pos (1, 1)
        done = false;  // not done yet
        while(!done)
        {
            //go along direction till end
            switch(dir){
                case 0: // ->  move till last node, change dir, check if done 
                  while(visited[i][j+1] != true ){
                      visited[i][j] == true; 
                      res.push_back(matrix[i-1][j-1]);
                      j++;
                  }
                  visited[i][j] == true; 
                  res.push_back(matrix[i-1][j-1]);
                  dir= (dir+1)%4; // change direction 
                  if(visited[i+1][j] == true) return res;
                  i++;
                  break;
                case 1: // v
                  while(visited[i+1][j] != true){
                      visited[i][j] == true; 
                      res.push_back(matrix[i-1][j-1]);
                      i++;
                  }
                  // last node in this direction
                  visited[i][j] == true; 
                  res.push_back(matrix[i-1][j-1]);   
                  dir= (dir+1)%4; // change direction to <----
                  if(visited[i][j-1] == true) return res; 
                  j--;
                  break;
                case 2: // <-
                  while(visited[i][j-1] != true){
                      visited[i][j] == true; 
                      res.push_back(matrix[i-1][j-1]);
                      j--; 
                  }
                  visited[i][j] == true; 
                  res.push_back(matrix[i-1][j-1]);  
                  dir= (dir+1)%4; // change direction to ^
                  if(visited[i-1][j] == true) return res; 
                  i--;
                  break;
                case 3: // ^
                  while(visited[i-1][j] != true){
                      visited[i][j] == true; 
                      res.push_back(matrix[i-1][j-1]);
                      i--;
                  }
                  visited[i][j] == true; 
                  res.push_back(matrix[i-1][j-1]);      
                  dir= (dir+1)%4; // change direction to -->
                  if(visited[i][j+1] == true) return res; 
                  j++;
                  break;
                default:
                  ; // error
            }
        }
    }
};
