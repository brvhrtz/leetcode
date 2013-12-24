/*
 * Divide integers without "*" "/" and "%" oper
 * 
 * Experience: 
 *     1. If you have difficulty get over something problem,  
          it could be that you are lacking some key info/skill/knowledge/personality. 
          Sometimes it is just some additional knowledge. 
       2. Find the missing link and work on it until you master it and try again. 
 * 
 * Summary: 
 *     1. <cmath>: pow, sqrt, exp, log, abs, ceil, floor
 *     2. Need to work on random numbers as well
 */


// determine sign by bit-and LSB
//        bool posi; 
//        posi = (dividend & 0x80000000) & (divisor & 0x80000000) == 0? true : false;   

#include <iostream>
#include <cmath>

using namespace std; 

#define MAX_P (int)0x7fffffff
#define MAX_N (int)0x80000000

class Solution {
public:
    int divide(int dividend, int divisor) {
         
        // special case: divisor == 0
        
    
        // special case: buffer overflow
        
//        if(dividend == MAX_N && divisor == 1) return MAX_N; // 
//        if(divisor == MAX_N) return 0; 
//        if(dividend == MAX_N && divisor == MAX_N) return 1;

        int res = 0; 
        unsigned int x = abs(dividend);
        unsigned int y = abs(divisor);
        bool xsign, ysign; 
        
        xsign =  dividend > 0 ? true : false;
        ysign =  divisor > 0 ? true : false; 
        
        // eliminate 0 values
        if(y == 0) return x > 0? MAX_P : MAX_N;
        if(x == 0) return 0; 
        
        // 
        if(y == abs(MAX_N) && x != abs(MAX_N)) return 0;
        if(y == abs(MAX_N) && x == abs(MAX_N)) return 1; 
        
        if(x >= y)
        {
          while(x >= y){
            unsigned int temp = y; 
            unsigned int cnt = 0; 
            while( (temp << 1) < x)
            {
                temp = temp << 1;
                cnt++;
            }
            res += pow(2, cnt);
            x = x - temp; 
          }
        }
        else
        {
            res = 0; 
        }
        
        return xsign == ysign ? res : -res; 
    }
};

int main()
{
    Solution sol; 
    
    cout << sol.divide(1, 1) << endl; 
    return 0; 
}
