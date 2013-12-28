/*
 * The DP version
 * Algorithm: 
      // Observation: the leftmost nodes i that can reach me, is always on the min jump path to me. 
      // Proof: Suppose if one min path do not use i, it has to use some node i+x
      //        This min path can be modified to use i to reach me without increasing the number of jumps 
      //        by making the second last nodes to jump to i and then from i to me. 
 * Optimizations: 
     - a lot of optimization has to be done to reach the time limit
       1. - Though it intended to sweep the array one time, but since there is a inner loop to set the future nodes, 
            the time complexity still can be n^2.
          - The following example shows how to over come this
            if A[i] = 7 then from  [i+1, i+7] all can be reached by i, if i+x has not been reached before,
            i is the leftmost nodes to reach i+x in one jump. The extreme case is all nodes has not been touched b4. 
            e.g. {1, 1, 7, 1, 1, 1, 1}
 * Gotchas: 
     1. - A[i] can be 0. This actually also pose the possibility of non-reachable end. 
        - fortunately if(A[i]==0), we can simply go on since it not going to leads us anywhere
        - in some cases, it may be useful to mark pre_hop[i] with special value if reachability is of concern
     2. if(A[i-1] == 0) and i hasn't been touched yet, i is a deadend node without path to him from the begining. 
 * 
 */


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring> 

using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
      // 1-D backwards Dynamic Programming
      // Need to think why backwards works
      if(n <= 1) return 0; 
      
      int i, j; 
      int r;           // rightmost nodes with known pre-hop node (leftmost onehop nodes) 
      int pre_hop[n];  // recording the previous hop in min jump path for this nodes
      int rmax;        // rightmost nodes i can reach
      int res;         // number of hops to be returned
      
      
      // Init pre hop array, -1 means that element has not been touched yet
      memset(pre_hop, -1, n*sizeof(int));

      i = 0; r = 1; 
      while(i < n-1)
      {
          if(A[i] == 0) { i++ ; continue;} 

          if(pre_hop[i] == -1 && A[i-1]!=0) pre_hop[i] = i-1;
          rmax = std::min(i + A[i], n-1);
          if(rmax > r){
              for(j = r+1; j <= rmax; j++)
              {
                  if(pre_hop[j] == -1) pre_hop[j] = i;
              }
              r = rmax;
          }
          i++;  
      }
      
      res = 0; 
      i = n-1; 
      while(i > 0)
      {
          i = pre_hop[i]; 
          res++; 
      }
      
      return res; 
    }
};
int main()
{
   cout << "Hello World" << endl; 
   Solution sol; 
   
   int A[] = {4, 1, 1, 3, 1, 1};
   cout << sol.jump(A, sizeof(A)/sizeof(int)) << endl;  
   return 0;
}
