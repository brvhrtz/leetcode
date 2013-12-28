/*
 * canJump: test if last nodes is reachable from first node
 * 
 * Algorithm: 
       i is unreachable if: 
        -  i's leftmost onehop node is unreachable
        -  extreme case, A[i-1] = 0 and i can not be touched by previous node yet
        -  general case, i-x with A[i-x] = 7 is i's leftmost one hop node is unreachable, 
           there is no way it can be reached. If i can be reached, it must be reached by some  i' < i-x, 
           and that means i-x is not i's leftmost onehop node
 * Gotchas: 
      1. if your algorithm is changing back and forth, it increase the chance that you misplace some of your conditions
         e.g. 
            if(pre_hop[i] == -1 && A[i-1] == 0)  // lost dutchmen misplace with || instead of && 
            // one of the reason is because I'm copy and paste or modifying previous statements 
            // Maybe I should try to write new conditions whenever I need to change a condition 
            
       
 */



#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring> 

using namespace std;

class Solution {
public:
   
    bool canJump(int A[], int n) {
              // 1-D backwards Dynamic Programming
      // Need to think why backwards works
      if(n == 0) return false; 
      if(n == 1 && A[0] == 0) return true; 
      if(n == 1 && A[0] != 0) return true;
      if(n > 0  && A[0] == 0) return false; 
      
      
      int i, j, r; 
      int pre_hop[n];  // recording the previous hop in min jump path for this nodes
      int rmax; 
      
      memset(pre_hop, -1, n*sizeof(int));

      pre_hop[0] = -1;
      r = std::min(A[0], n-1);
      for(i = 1; i <= r; i++) pre_hop[i] = 0; 
     
      i = 1; 
      while(i < n-1)
      {
          if(i > r) r = i; 
          if(pre_hop[i] == -1 && A[i-1] == 0)
          { // lost dutchmen, this is an unreachable node 
              i++; 
              continue; 
          }
          if(A[i] == 0) 
          { // dead end, no further node can be reached here
              i++;  
              continue;
          } 
          
          if(pre_hop[i] == -1) pre_hop[i] = i-1;
          
          //rmax = (i + A[i]) < n? (i + A[i]): n-1 ;
          rmax = std::min(i + A[i], n-1);
          if(rmax > r){
              for(j = r+1; j <= rmax; j++)
              {
                  if(pre_hop[j] == -1) pre_hop[j] = i;
              }
              r = rmax;
          }
          cout << i << " " << pre_hop[i] << endl; 
          i++;  
      }
      
      i = n-1; 
      while(i > 0)
      {
          if(pre_hop[i] == -1) return false;
          i = pre_hop[i]; 
      }
      return true; 
    }
    
};
int main()
{
   cout << "Hello World" << endl; 
   Solution sol; 
   
   int A[] = {2, 0, 2, 0, 1};
   cout << sol.canJump(A, sizeof(A)/sizeof(int)) << endl;  
   return 0;
}
