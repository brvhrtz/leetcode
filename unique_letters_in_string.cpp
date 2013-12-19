#include <iostream>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string s) {
        // this is definitely DT
        int count = 0; 
        map<char, int> intMap;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(intMap.find(s[i]) == intMap.end())
            {
              cout << i << ":" << s[i] << endl;  
              intMap.insert(std::pair<char, int>(s[i], i)); 
              count ++; 
            } 
        }
        return count;
}
    
int main()
{
   string str = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco"; 
   
   cout << lengthOfLongestSubstring(str) << endl; 
   
   return 0;
}
