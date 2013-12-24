/*
 * strStr: return the starting location (ptr) of the first occurance of a substr 
 * 
 * Crazy simple program that requires so much efforts to get it right
 *   get the first occurance of a substring 
 * Pain&Gain
     0 type fast to think fast // not sure if this will work but try it as in playing a guitar
 *   1. Need to improve program simplicity
     2. Think simple and program simple. 
     3. Think abou how to improve this program tomorrow and compare with other impl
   Gotchas: 
     1. List three of them in the program
     2. Basically is condition on the absolute value while you should condition on the tuned version of the variable. 
     3. When you've already used much brain cell just to covnerge to a solution, it is hard to keep track of all the variables. Need to find a systematic way to get around this 
     - reduce variables, use functions, reduce conditions 
     - it seems when to stop, when to start, where to break is always a pain
     - for loop boundaries should I start drawing window/maps to keep track?  Let's see
 *
 */

#include <iostream>
#include <cstring>

using namespace std;


class Solution {
public:
    int next_idx(int l, int r, char *haystack, char target)
    {
        for(int i = l; i <= r; i++)
        {
            if(haystack[i] == target) return i; 
        }
        return -1; 
    }
    char *strStr(char *haystack, char *needle) {
        int l, r; 
        int lh = strlen(haystack);
        int ln = strlen(needle);
        int i, j; 
        
        if(lh < ln) return NULL;
        if(ln == 0 && lh == 0) return haystack; 
        if(ln == 0 && lh != 0) return haystack; 
        if(ln != 0 && lh == 0) return NULL; 
        
        if(ln == 1)
        {// single char matching 
            for(i = 0; i < lh; i++) 
            {
                if(haystack[i] == needle[0]) return haystack+i;
            }
            return NULL; 
        }
        
        char front = needle[0];
        char back = needle[ln-1];
        i = j = 0; 
        l = 0; r = lh-1; 
        while(l < lh)
        {
          i = next_idx(l, r, haystack, front);
          if(i == -1) return NULL; 
          else
          {
//              j = next_idx(i + ln -1 , r, haystack, back);
              if( i + ln -1 > lh-1 ) 
                  return NULL;  // windwo not enough 
              else if(haystack[i + ln - 1] != back)
              {// window tail not mathcing skip this loop 
                  l = i + 1; 
              }
              else              
              {// window valid
                 int k; 
                 for(k = i; k-i < ln; k++)  // gotcha 2 
                     if(haystack[k] != needle[k-i]) break;
                 if(k -i == ln ) return haystack + i;   // match found at i // gotcha 3 
                 l = i + 1; 
              }
          } // else
        } // whle
        
    }
};

int main()
{
   cout << "Hello World" << endl; 
   Solution sol; 
   
   char a[] = "cacccbbabb";
   char b[] = "babb";
   cout << sol.strStr(a, b) << endl;
   return 0;
}


