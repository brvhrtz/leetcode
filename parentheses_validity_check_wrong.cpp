/*
 * This is a linear implementation but unfortunately not working
 *  e.g.  ()()()()   the last ')' find backwards is not necessarily the matching one for the first '('
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s, int l, int r)
    {
        int nr = r;
        
        cout << "l = " << l << " r  = " << r << endl; 
        if((r - l)%2 == 0)  return false;
 //       if(r - l == 1 && s[l] == s[r]) return true; 
 //       if(r - l == 1 && s[l] != s[r]) return false; 

        if(s[l] == '(')
        {// minimum 4 signs within s now
            if(r - l == 1) return s[r] == ')'? true:false; 
            
            while(s[nr] != ')' && nr > l) nr--;
            if((nr - l)%2 == 0) 
              return false;    // odd number of signs are always invalid within a closed bracket 
            else if(nr == l + 1) //  ()**
              return isValid(s, nr+1, r);
            else if(nr == r)     //  (**)
              return isValid(s, l+1, r-1);
            else                //  (**)**
              return isValid(s, l+1, nr-1) && isValid(s, nr+1, r); 
        }
        if(s[l] == '{')
        {
               if(r - l == 1) return s[r] == '}'? true:false; 
             while(s[nr] != '}' && nr > l) nr--;
            if((nr - l)%2 == 0) 
              return false;    // odd number of signs are always invalid within a closed bracket 
            else if(nr == l + 1) //  ()**
              return isValid(s, nr+1, r);
            else if(nr == r)     //  (**)
              return isValid(s, l+1, r-1);
            else                //  (**)**
              return isValid(s, l+1, nr-1) && isValid(s, nr+1, r); 
        }
        if(s[l] == '[')
        {
               if(r - l == 1) return s[r] == ']'? true:false; 
            while(s[nr] != ']' && nr > l) nr--;
            if((nr - l)%2 == 0) 
              return false;    // odd number of signs are always invalid within a closed bracket 
            else if(nr == l + 1) //  ()**
              return isValid(s, nr+1, r);
            else if(nr == r)     //  (**)
              return isValid(s, l+1, r-1);
            else                //  (**)**
              return isValid(s, l+1, nr-1) && isValid(s, nr+1, r); 
        }
    }
    bool isValid(string s) {
        // CHeck if parentheses is valid
        // Recursive algorithm should do the work
        if(s.size() == 0) 
          return true;
        else if(s.size()%2 != 0) 
          return false;
        else
          return isValid(s, 0, s.size()-1);
    }
};

int main()
{
   cout << "Hello World" << endl; 
   
   Solution sol;
   if(sol.isValid("(({[]}))")) cout << "Is Valide" << endl; 
   return 0;
}
