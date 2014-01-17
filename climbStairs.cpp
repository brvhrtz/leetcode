/*
 *  Find how many ways can use any number of 2s and 1s to add to n
 *   Fibonacci Style problem
 */

class Solution {
public:
    int climbStairs(int n) {
        if(n==0) return 1; 
        
        int i, j;
        int res = 1; // represent all '1's 
        for(i=1; i<=n-1; i++){ // replace two '1' with a '2' and recursively, remember not to look back
            res += climbStairs(n-(i+1)); 
        }
        return res; 
    }
    int climbStairs(int n) {
        vector<int> vec(n+1, 0); 
        int res; 
        int i, j; 
        
        if(n<1) return 0; 
        vec[0] = 1; 
        vec[1] = 1;
        
        i = 2; 
        while(i<=n){
            vec[i] = 1; // all '1's
            for(j=i-2; j>=0; j--){
                vec[i] += vec[j]; 
            }
        }
        return vec[n]; 
    }
};
