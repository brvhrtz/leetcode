/*
 * The original problem somehow don't need you to think about over flow
 * But this is actually a huge part of a Integer arithmatics. 
 * It will be enlightening to explore the overflow check and 32 to 64 conversion and vice versa
 */

#define iMax  0x7fffffff
#define iMin  0x80000000
#define iMax64 0x000000007fffffff
#define iMin64 0xffffffff80000000

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int tLen = tokens.size(); 
        stack<int> stk; 
        int op1, op2;
        int res32 = 0;
        long long  llop1, llop2; 
        long long  res64 = 0; 
        int i; 
        
        if(tLen == 0) return 0; 
        
        for(i = 0; i < tLen; i++)
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") 
            {// operands
              //stk.push(atoi(tokens[i].c_str()));
              stk.push(stoi(tokens[i]));
            } 
            else
            {// operators
                  if(stk.size() <= 0)  return 0;  // operators with 0 operand
                  else { op2 = stk.top(); stk.pop(); }
                  if(stk.size() <= 0)  return 0;  // operator with only 1 operand 
                  else { op1 = stk.top(); stk.pop(); }
  
  /*                
                  llop1 = (long long)op1; llop2 = (long long) op2;
                  if(tokens[i] == "+"){ res64 = llop1 + llop2;}
                  if(tokens[i] == "-"){ res64 = llop1 - llop2;}
                  if(tokens[i] == "*"){ res64 = llop1 * llop2;}
                  if(tokens[i] == "/"){ res64 = llop1 / llop2;}
                      if(res64 > iMax64)  res32 = iMax;
                      else if(res64 < iMin64)  res32 = iMin; 
                      else res32 = (int) res64; 
    */
                  if(tokens[i] == "+"){ res32 = op1 + op2;}
                  if(tokens[i] == "-"){ res32 = op1 - op2;}
                  if(tokens[i] == "*"){ res32 = op1 * op2;}
                  if(tokens[i] == "/"){ res32 = op1 / op2;}
                      stk.push(res32);
            }
        return stk.top(); 
    }
};
