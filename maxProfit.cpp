/*
 * Record setting so far: first program to get accepted with only one minor compiler error before it (missing an declaration)
 * Using greedy algorithm to basically trade 
 * The proof is      for [a,..,b,c,..,d] if b>c,   we have (d-c)+(b-a) >= d-a ,  d-c+b-a >= d-a ,  b-c>=0 => b>=c
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // just get greedy
        int maxp; 
        int i, j;
        int N = prices.size(); 
        
        if(N<2) return 0;

       i = 0; j = 1; maxp = 0; 
     while(i < N-1 && j<N){
            if(prices[j] >= prices[i]){
                    if(j==N-1){ //  [1 2 3]
                        maxp = maxp+ prices[j]-prices[i];
                        break; 
                    }
                    else if(j+1<N && prices[j+1] < prices[j]){ // 1 2 3 2...
                        maxp = maxp+ prices[j]-prices[i];
                        i = j+1; 
                        j = i+1; 
                    }
                    else{// 1 2 3 4...
                        j++; 
                    }
            }
            else{
                    i = j;
                    j = i+1; 
            }
    }
    return maxp;
  }
};
