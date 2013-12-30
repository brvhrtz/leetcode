/*
 *  Regular expression matching
 *  Gotcha:
     0. Understand the problem correctly first
        0.1  so ".*" = "....." and each '.' can match to anything
        0.2  so "**" is invalid input
        0.3  so "a*" !="a"+Anything;  * is precisely repeating preceding element any times; 
     1. This is hugely deceptive problem. A monster with a baby face. A wolf hide under a sheep skin. 
     2. The edge conditions can kill you
     3. It is though easy to grasp the idea that whether the next char is '*' is the key differentiator 
         3.1 without '*' looming behind your back, it is straightfoward matching or not, only to handle the condition of '\0' char
         3.2 with '*' coming next, however, you have to be really careful
           3.2.1 One extremely difficult to spot pitfall is shown below
                  s = "abbc";  p = "ab*bbc";    
                  greedy algorithm won't work here if you simply push to the end of 'b's in s
                  instead, you need to brutal force check how many 'b' the '*' should represent. 
 */
 

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if(s == NULL || p == NULL || *p == '*') return false;
        if(*p == '\0') return *s == '\0';
        if(*(p+1) != '*') {
            if(*s == '\0') return false;
            if(*p != '.' && *p != *s) return false;
            return isMatch(s+1,p+1);
        } else {
            int slen = strlen(s);
            if(isMatch(s,p+2)) return true;
            for(int i = 0; i < slen; ++i) {
                if(*p!='.' && *p != *(s+i)) return false;
                if(isMatch(s+i+1,p+2)) return true;
            }
            return false;
        }
    }
  
  // A even more concise solution 
  // from http://leetcode.com/2011/09/regular-expression-matching.html
  bool isMatch2(const char *s, const char *p) {
  assert(s && p);
  if (*p == '\0') return *s == '\0';
 
  // next char is not '*': must match current character
  if (*(p+1) != '*') {
    assert(*p != '*');
    return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
  }
  // next char is '*'
  while ((*p == *s) || (*p == '.' && *s != '\0')) {
    // brutal force to decide how many (*s) we want to replace with this '*'
    // think about this case      abbc matching to ab*bbc
    if (isMatch(s, p+2)) return true;
    s++;
  }
  return isMatch(s, p+2);
 }
};

