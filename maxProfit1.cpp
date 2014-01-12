/*
 *   Algorithm1: 
        Brutal force
     Algorithm2: 
        for [a, ... b,c,.d,..], if c<min[a..b], we can restart from c and there is no loss of info 
        since if have a d that can do better with min([a..b]), aka, d-min([a..b]) > d-c
        we have c > min([a..b]). There is a contradiction here. 
    Experience: 
        Use while loop if you are unsure of when you would like to increase change i,j
 */


class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxp;
        int i, j; 
        int N = prices.size(); 
        int min, max; 
        
        if(N<2) return 0; 
        
        min = prices[0]; 
        max = prices[0];
        maxp = 0; 
        i = 0; 
        while(i<N-1){
            j = i+1; 
            while(j < N){
                if(prices[j] < min) 
                { 
                    min = prices[j];
                    max = prices[j]; 
                    i = j; 
                    break;
                }
                else 
                if(prices[j] > max)
                { 
                    max = prices[j]; 
                    if(max-min > maxp) maxp = max-min; 
                    j++;
                }
                else  
                    j++;  // min<=prices[j]<=max 
            }
            if(j==N) break; // This is easily forgotten, otherwise you will have infinite loop
        }
         return maxp; 
    }
};
