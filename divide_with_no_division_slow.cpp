/*
 *  A naive but complete solution to simulate divide without (*, /, %) operations
 *  Exceed time limit in Leetcode
 */
 
// determine sign by bit-and LSB
//        bool posi; 
//        posi = (dividend & 0x80000000) & (divisor & 0x80000000) == 0? true : false;   

#define MAX_P 0x7fffffff
#define MAX_N 0x80000000
class Solution {
public:
    int divide(int dividend, int divisor) {
         
        // special case: divisor == 0
        if(divisor == 0) return dividend > 0? MAX_P : MAX_N;
    
        // special case: buffer overflow
        if(dividend == MAX_N && divisor == -1) return MAX_P; // overflow
//        if(dividend == MAX_N && divisor == 1) return MAX_N; // 
//        if(divisor == MAX_N) return 0; 
//        if(dividend == MAX_N && divisor == MAX_N) return 1;

        int x, y;
        x = dividend; y = divisor;
        if(x < 0 && y > 0)
        {
            int cnt = 0; // record x/y
            while(x + y <= 0)
            {
                x = x + y;
                cnt--; 
            }
            return cnt;    
        }
        else if(x < 0 && y < 0)
        {
            int cnt = 0; // record x/y
            while(x - y <= 0)
            {
                x = x - y;
                cnt++; 
            }
            return cnt;    
        }
        else if(x >= 0 && y >0)
        {
            int cnt = 0; // record x/y
 //           int rem = 0; // record x%y
            while(x -y >= 0)
            {
                x = x-y;
                cnt++; 
            }
            return cnt;      
        }
        else if(x >= 0 && y<0)
        {
            int cnt = 0;
            while(x + y >= 0)
            {
                x = x + y; 
                cnt--; 
            }
            return cnt; 
        }
    }
};
