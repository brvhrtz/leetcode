/*
 * Exercise for bit operations and integer boundaries 
 * 
 * Summary: 
 * 1. avoid l-shift with signed int if you can, (unless you are sure the LSB won't chagne) 
      - for signed int, both n & p values, the sign bit can change depends on the 2nd most LSB. 
   2. if have to l-shift use unsigned int
      - as long as it does not overflow, you double the value
   3. r-shift is always good, you got /2 in abs value, sign bit will be kept 
      - r-shift for signed int will keep sign bit (fills LSB with 0 for p, with 1 for n)
      - r-shift for unsigned int (fills LSB with 0)
   4. Use <cstdio> & printf will ease your pain of printing hex 
   5. To get abs of signed int, always use unsigned int as the receiver, e.g.
      -    unsigned int a = abs(x); 
      -        a is enough to hold any abs value of x
      -        bit manipulation is hidden from programmer which is awesome. Avoid bit manipulation if you can. 
      -    int a = abs(x);  // will not work
      -        if x = n_most, the above method will overflow. 
   6. More specific bit manipulation techniques especially bit-map will be opened in a new commit
      http://blog.csdn.net/hguisu/article/details/7880288
 *
 */
#include <iostream>
#include <vector> 
#include <cstdio>

using namespace std; 


int main()
{
    
    // Group 1: n value r-shift keep sign and divide abs value by 2
    printf("%x  %d\n", 0x80000000, 0x80000000); 
    // 80000000  -2147483648
    printf("%x  %d\n", (int)0x80000000 >> 1, (int)0x80000000 >> 1);
    // c0000000  -1073741824
    printf("%x  %d\n", (int)0x80000000 >> 2, (int)0x80000000 >> 2);
    // e0000000  -536870912
    printf("%x  %d\n", 0x80000000 >> 1, 0x80000000 >> 1);
    // 40000000  1073741824
    
    // Group 2: n value l-shift is undefined, overflow issue
    printf("%x  %d\n", (int)0x80000000 << 1, (int)0x80000000 << 1);
    // 0          0
    printf("%x  %d\n", (int)0xb0000000 << 1, (int)0xb0000000 << 1);
    // 60000000  1610612736
    printf("%x  %d\n", (int)0xd0000000 << 1, (int)0xd0000000 << 1);
    // a0000000  -1610612736
    
    // Group 3: p value r-shift same as group 1
    // keeps sign and divide abs value by 2
    
    // Gropu 4: p value l-shift is undefined
    // as in Group 2, 2nd leftmost bit becomes the sign bit
    
    //Group 5   diff btw r-shift of signed and Unsigned int 
    // unsigned r-shift fill 0 on LSB
    // signed r-shift fill 1 on LSB
    // both get half of the abs value
    printf("%x  %d\n", (unsigned int)0x80000000 >> 1, (unsigned int)0x80000000 >> 1); 
    //40000000  1073741824
    printf("%x  %d\n", (int)0x80000000 >> 1, (int)0x80000000 >> 1); 
    //c0000000  -1073741824
    
    //Group 6 Even with unsigned, l-shift still has overflow issue
    printf("%x  %u\n", (unsigned int)0xffffffff, (unsigned int)0xffffffff); 
    // ffffffff  4294967295
    printf("%x  %u\n", (unsigned int)0xffffffff << 1, (unsigned int)0xffffffff << 1);
    // fffffffe  4294967294
    return 0;
    
    //Group 7  Integer overflow
    // n_Most - 1, n_Most * 2 invoke int o/f err at compile time. 
    // l-shift does not invoke overflow issue. But undefined behavior is not desirable  
    // p_Most + 1, p_Most * 2  invoke int o/f err at compile time.
    
    //printf("%x  %d\n", (int)0x80000000 - 2, (int)0x80000000 - 2);
//     printf("%x  %u\n", (int)0x7fffffff + 1, (int)0x7fffffff + 1);

     //Group 8: Unsigned and signed conversion 
     // Keep all bit-wise value only interpretation changes
     // p value unchanged, directly use forced conversion is OK
     // n value, dont directly use force conversion which gives undesired results, abs value does not match
     // to conver n value to its abs version use this 
     // unsigned int  res = abs(n_most); 
     //  abs value unchanged, sign flipped
     // Forced type cast only works for n_Most :) surprise ! but yes, it is true. 
     printf("%x  %u\n", (unsigned int)0x80000000, (unsigned int)0x80000000);
     printf("%x  %d\n", 0x80000001, 0x80000001);
     printf("%x  %u\n", abs((int)0x80000001), abs((int)0x80000001));
     
}
