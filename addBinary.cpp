/*
* Simple problem sometimes give you headache
* This is a prime example of what you should be aware when asked a simple question
* Where is going wrong, you didn't run through simple example on the paper and started coding immediately
* Gain: 
* 1. Add to the skeleton procedures add a run through with real test cases before you start writing code
  2. When asked a simple question, be happy but be cautious to stick even closer to the paper skelton test (PST) procedures.  
*/


class Solution {
public:
    string helper(string a, string b){
        int Na = a.size(); // assuming a.size()>b.size() 
        int Nb = b.size(); 
        int i, j; 
        bool carry = false; 
        char temp; 
        
        i = Na-1; 
        j = Nb-1; 
        while(i >=0 || j>=0){
                if(j < 0) temp = '0';
                else               temp = b[j];
                
                if(a[i]!=temp && carry == false) {a[i] = '1'; carry = false;} 
                else 
                if(a[i]!=temp && carry == true) {a[i] = '0'; carry = true;}
                else
                if(a[i]=='0' && carry == false) {a[i] ='0'; carry = false; }
                else
                if(a[i]=='0' && carry == true) {a[i] ='1'; carry = false;}
                else
                if(a[i]=='1' && carry == false) {a[i] ='0'; carry = true;}
                else
                if(a[i]=='1' && carry == true) {a[i] = '1'; carry = true;}
                
                i--; j--; 
        }
        if(carry == true) return '1'+a; 
        else              return a; 
    }
    string addBinary(string a, string b) {
        int Na = a.size(); 
        int Nb = b.size(); 

        if(Na==0 || Nb == 0) return a+b; 
        // walk through bit backwards
        if(Na > Nb) return helper(a, b); 
        else        return helper(b, a);  
    }
};
