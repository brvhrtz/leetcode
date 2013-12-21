/*
 * An imperfect implementation of AtoI function 
 * Need to improve
 */
#include <iostream>

using namespace std;


class Solution {
public:
    int ctod(const char mychar){
        int res; 
        if(mychar >= '0' && mychar <= '9')
        {
            res =  (int)mychar - (int)'0';
        }
        else if(mychar >= 'a' && mychar <= 'f')
        {
            res = (int)mychar - (int)'a' + 10;
        }
        else if(mychar >= 'A' && mychar <= 'F')
        {
            res = (int)mychar - (int)'A' + 10; 
        }
        cout << "input : " << mychar << " output: " << res << endl; 
        return res; 
    }
    int convert_hex(const char *str, int L)
    {
        int res = 0;
        
        for(int i = 2; i < L; i++)
        {
          res = res * 16 + ctod(str[i]);
        }
        return res;
    }
    int convert_oct(const char *str, int L)
    {
        int res = 0;
        
        for(int i = 1; i < L ; i++)
        {
            res = res * 8 + ctod(str[i]);
        }
        return res;
    }
    int convert_pdec(const char *str, int L)
    {
        int res = 0;
        cout << " L = " << L  << endl; 
        for(int i = 0; i < L; i++)
        {
            cout << "str[" << i << "] = " << str[i]<< endl; 
            res =  res * 10 + ctod(str[i]);
        }
        return res;
    }
    int convert_ndec(const char *str, int L)
    {
        int res = 0;
        for(int i = 1; i < L ; i++)
        {
            res = res * 10 +  ctod(str[i]);
        }
        return -res;
    }
    int atoi(const char *str) {
        int L;  // length of str
        int i = 0;
        int res;
        
        if(!str) return -1; 
        while(str[i] != '\0') i++;
        L = i;
        cout << "Sol: L = " << L << endl; 
        for(i = 0; i < L; i++) cout << str[i] << " "; 
        cout << endl; 
        
        if(L == 1 && str[0] == '0')
        {
            //special case 1: 0   
          res = 0;   
        }  
        else
        {
            if(str[0] == '0')
            {
                if(str[1] == 'x')
                {
                   // hex   
                   cout << "called convert_hex" << endl; 
                   res = convert_hex(str, L);
                }
                else 
                {
                    // oct
                    cout << "called convert_oct" << endl; 
                    res = convert_oct(str, L);
                }
            }
            else if(str[0] == '-')
            {
                // negative decimal
                cout << "called convert_ndec" << endl; 
                res = convert_ndec(str, L);
            }
            else
            {
                // non-negative decimal
                cout << "called convert_pdec with L = "<< L <<  endl; 
                res = convert_pdec(str, L);
            }    
        }
        return res; 
        
    }
};

#define INT_MAX 2147483647
#define INT_MIN -2147483648

class Solution2 {
public:
    int ctod(const char mychar){
        int res; 
        if(mychar >= '0' && mychar <= '9')
        {
            res =  (int)mychar - (int)'0';
        }
        else if(mychar >= 'a' && mychar <= 'f')
        {
            res = (int)mychar - (int)'a' + 10;
        }
        else if(mychar >= 'A' && mychar <= 'F')
        {
            res = (int)mychar - (int)'A' + 10; 
        }
        return res; 
    }
    int convert_hex(const char *str, int L)
    {
        int res = 0;
        
        for(int i = 2; i < L; i++)
        {
          res = res * 16 + ctod(str[i]);
        }
        if (res > INT_MAX) res = INT_MAX;
        if (res < INT_MIN) res = INT_MIN;
        return res;
    }
    int convert_oct(const char *str, int L)
    {
        int res = 0;
        
        for(int i = 1; i < L ; i++)
        {
            res = res * 8 + ctod(str[i]);
        }
        if (res > INT_MAX) res = INT_MAX;
        if (res < INT_MIN) res = INT_MIN;
        return res;
    }
    int convert_pdec(const char *str, int L)
    {
        int res = 0;
        cout << " L = " << L  << endl; 
        for(int i = 0; i < L; i++)
        {
            res =  res * 10 + ctod(str[i]);
        }
        if (res > INT_MAX) res = INT_MAX;
        if (res < INT_MIN) res = INT_MIN;
        return res;
    }
        int convert_pdec_with_plus(const char *str, int L)
    {
        int res = 0;
        cout << " L = " << L  << endl; 
        for(int i = 1; i < L; i++)
        {
            res =  res * 10 + ctod(str[i]);
        }
        if (res > INT_MAX) res = INT_MAX;
        if (res < INT_MIN) res = INT_MIN;
        return res;
    }
    int convert_ndec(const char *str, int L)
    {
        int res = 0;
        for(int i = 1; i < L ; i++)
        {
            res = res * 10 +  ctod(str[i]);
        }
        if(res > INT_MAX) res = INT_MAX;
        if (res < INT_MIN) res = INT_MIN;
        return -res;
    }
    int atoi(const char *str) {
        int L;  // length of str
        int i = 0;
        int res;
        
        // Bondary conditions to consider
        // 1. zero input
        // 2. whitespace input before and after
        // 3. overflowed integer   x > 0x7FFFFFFF or x < 0x80000001
        if(!str) return 0; 
        while(str[i] != '\0') i++;
        L = i;
        
        char *new_str = new char[L];
        int count = 0;
        for(i = 0; i < L; i++)
        {
             if(count == 0 && str[i] == ' ') continue;
             else if(str[i] == ' ') break;
             else
             {
                 new_str[count++] = str[i];
             }
        }
        L = count; 
        
        if(L == 1 && new_str[0] == '0')
        {
            //special case 1: 0   
          res = 0;   
        }  
        else
        {
            if(new_str[0] == '0')
            {
                if(new_str[1] == 'x')
                {
                   // hex   
                   res = convert_hex(new_str, L);
                }
                else 
                {
                    // oct
                    res = convert_oct(new_str, L);
                }
            }
            else if(str[0] == '-')
            {
                // negative decimal

                res = convert_ndec(new_str, L);
            }
            else if(str[0] == '+')
            {
                // non-negative with + sign
                res = convert_pdec_with_plus(new_str, L);
            }
            else 
            {
                // non-negative decimal
                res = convert_pdec(new_str, L);
            }    
        }
        return res; 
        
    }
};

int main()
{
   cout << "Hello World" << endl; 
   Solution2 sol; 
   
   int res; 
   res = sol.atoi("0x80000000");
   cout << res << endl; 
   return 0;
}
