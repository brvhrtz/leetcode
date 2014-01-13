/*
 * Best time to buy and sell stock III
 * Algorithm1: 
     1. Brutal force.     i=[0, N-2]{j=[i+1, N-1]{k=[j+1, N-1]{l={k+1, N-1}}}}    
        4 level of loops to pick 4 break point for 2 buys and 2 sells
        Not really attractive at all
   Algorithm2: (wrong but is kind of cute and worth analysis and why it is not working)
   Input:	[6,1,3,2,4,7]
   Output:	    6    [1,3]+[2,7] merged to [1,7] (wrong)
   Expected:	7    
     2. follow sell stock II and then merge as much as possible and then chose the two with most profit
        The tricky part is when to merge
        min1   min2   min3   min4  min5 
        max1   max2   max3   max4  max5 
5                             *          *
4         *                  *          *
3        *             *    *          *
2       *        *   *     *          *
1      *       *                     *
0            *                      *
      t1     t2      t3    t4       t5
Merge rules:       
     1. only merge neighboring transactions 
     2. never merge if min2 < min1
     3. when min2>=min1  
           if max2<=max1 just throw transaction 2
           if max2> max1 merge the two transaction 
     4. Use a queue to store the transactions
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
    struct Transaction{
        int min; // buying price
        int max; // seling price
        int profit; // profit 
        Transaction(int x, int y) : min(x), max(y), profit(y-x) {}
        Transaction() : min(0), max(0), profit(0) {}
    }; 
    bool compare(Transaction t1, Transaction t2){
        return t1.profit < t2.profit ? true : false; 
    }
    
class Solution {
public:
    int maxProfit(vector<int> &prices) {
       vector<Transaction> tq;// transaction queue
       Transaction        tr; 
       int  i, j; 
       int N = prices.size(); 
       
       if(N<2) return 0; 
       
       i=0; j=1;
       while(i<N-1 && j<N)
       {
           if(prices[j]<= prices[i]){// move i to j, j to j+1
               i = j; 
               j = i+1; 
           }
           else
           if(prices[j]>prices[i]){
               if(j == N-1 ){// if j is last,  finish transaction and break
                   tr.min = prices[i];
                   tr.max = prices[j]; 
                   tr.profit = prices[j]-prices[i]; 
                   tq.push_back(tr); 
                   break; // get out of while loop 
               }
               else
               if(prices[j+1]>=prices[j]){// if j+1 is equal or larger, just move j++
                   j++; 
               } 
               else
               if(prices[j+1]<prices[j]){// if j+1 is smaller, record transaction and move
                  tr.min = prices[i]; 
                  tr.max = prices[j]; 
                  tr.profit = prices[j]-prices[i]; 
                  tq.push_back(tr); 
                  i = j+1; j=i+1; 
               }
           }
       }// check if infinite loop 
       
       
       // Processing transactions
       if(tq.size() == 0) return 0; 
       if(tq.size() == 1) return tq.front().profit; 
       
       N = tq.size();
       i = 0; j = 1; 
       while(i<N-1 && j<N){
           Transaction  &t1 = tq[i]; 
           Transaction  &t2 = tq[j]; 
           if(t2.min < t1.min){
               i++; j++; 
               continue; 
           } 
           else
           if(t2.min >= t1.min){
               if(t2.max >=t1.max){
                   // merge  
                   t1.profit = 0; 
                   t2.min = t1.min; 
                   t2.profit = t2.max-t2.min; 
                   i++; j++; 
               }
               else
               if(t2.max < t1.max){// replace t2 with t1
                   t2.min = t1.min; 
                   t2.max = t1.max; 
                   t2.profit = t1.profit;
                   t1.profit = 0; 
                   i++; j++; 
               }
           }
       }
       
       // Returning
       if(tq.size()==1) return tq.front().profit; 
       else{
           std::sort(tq.begin(), tq.end(), compare);
           return tq[N-1].profit + tq[N-2].profit; 
       }
    }
};
