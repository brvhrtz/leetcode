#include <iostream>
#include <vector> 

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // CHeck if parentheses is valid
        // Recursive algorithm should do the work
        vector<char> vec;
        
        if(s.size() == 0) 
          return true;
        else if(s.size()%2 != 0) 
          return false;
        else
        {
            for(int i = 0; i < s.size(); i++)
            {
              switch(s[i]){
                 case '(':
                    //c1++;
                    vec.push_back(s[i]);
                    break;
                 case ')':
                    if(vec.size() == 0) return false;
                    else if(vec.back() != '(') return false;
                    else vec.pop_back();
                    break;
                 case '[':
                    vec.push_back(s[i]);
                    break;
                 case ']':
                    if(vec.size() == 0) return false;
                    if(vec.back() != '[')
                      return false;
                    else 
                      vec.pop_back();
                    break;
                 case '{':
                    vec.push_back(s[i]);
                    break;
                 case '}':
                    if(vec.size() == 0) return false;
                    if(vec.back() != '{')
                      return false;
                    else 
                      vec.pop_back();
                    break;
                default:
                    break;
              }
            }
            if(vec.size() != 0) 
              return false; 
            else 
              return true;
        }
    }
};

int main()
{
   cout << "Hello World" << endl; 
  
   Solution sol; 
   
   string s = ")}{({))[{{[}"; 
   // = "()()()()(){}{}{}{[][][]}";
   if(sol.isValid(s)) cout << "Is Valid!" << endl; 
   else cout << "Not Valid" << endl; 
   return 0;
}
