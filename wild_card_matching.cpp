/*
 *  Wildcard matching 
 *  
 * Problem:
      1. Understand the phrase "The matching should cover the entire input string (not partial)."
         1.1 This means the two string has to be exactly same with some kind of wild card interpretation
         1.2 that's why isMatch("aab", "c*a*b") → false ;   it only a partial matching
 * Follow-up:
      1. Write my own version please as you now know the algorithms
 */

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         
        const char* star=NULL;
        const char* ss=s; 
        while (*s){
            if ((*p=='?')||(*p==*s)){s++;p++;continue;}
            if (*p=='*'){star=p++; ss=s;continue;}
            if (star){ p = star+1; s=++ss;continue;}
            return false;
        }
        while (*p=='*'){p++;}
        return !*p;
    }
};
