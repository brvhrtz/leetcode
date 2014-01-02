/*
 *
 * Check if exist a starting point in a circle of gas stations that enables full circle traversal
 * 
 * Algorithms: 
      1. Brutal force: traverse all gas stations as starting point and determine if a forward route exists. 
      2. Dynamic programming: 
         2.1 start from any node i as an achor point, and use i as forward index, j=i as backward index
             Use rem = rem + gas[i] - cost[i]
                    move i forward until a negative rem is achieved. 
                    move j backward until a positive rem is arriaved. 
                    if( i == j) at any time and rem is positive, return true; 
                    else return false
         2.1 To cycle around a sequential idx 
              j = (j-1+N)%N (backward)
              i = (i+1)%N (forward) 
 * 
 * 
 *
 */

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int i, j, count; 
        int rem; // remaining gas
        int N = gas.size(); // number of gas stations 
        
        if(N==0) return -1; 
        
        // Since assuming unique solution, 
        // There should be at least one i that gas[i] - cost[i] < 0; 
        // If there is no, then every i should work. 
        for(i = 0; i<N; i++){
            if(gas[i] < cost[i]) break; 
        }
        if(i == N) return 0;  // no negative route, just smoothly go all the way
        if(N == 1) return -1; // one node with negative route
        
        // move away from i in two directions
        // mvoe j backward until a postive rem is arrived. 
        // move i forward until a negative rem is arrived. 
        // Give the above assumption, it becomes obvious that we can start from any i
        // just mvoe i forward until negative and move j from i back wards untill another positive is arrived. 
        rem = gas[i] - cost[i];
        for(j = (i-1+N)%N; j!=i; j=(j-1+N)%N)
        {
            rem = rem + gas[j] - cost[j];  
            while(rem>=0)
            {
                if(i%N == j) return j; 
                i = (i+1)%N; 
                rem = rem + gas[i] - cost[i];
            }
        }
        return -1; // circle closed, no viable route is obtained. 
    }
};
