/*
 *  Zhenhua @ 6:04pm 12/18/2013
 *  Leetcode: Length of Longest Non-repeating Substring
 *
 * Algorithm: 
 * 1. DP with Moving window
 * 
 * Gotchas: 
 * 1. std::Map<?, ?>::begin() does not return the first inserted item but the smalles keyed item. 
 * 2. The substring has to be consecutive chars
 * 3. Be extremely careful about boudary values of your loop 
 * 4. If both old value and new value needs to be used in the same loop. Arrange the logic properly. 
 */

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int count, max;
      int i, j;
      int l , r;
      map<char, int> cMap; 
      
      count = max = l = r = 0;
      for(i = 0; i < s.size(); i++)
      {
        if(cMap.find(s[i]) == cMap.end())
        {
                      // letter NOT happened before, keep unique so far       
          cMap.insert(std::pair<char, int>(s[i], i));
          r = i;
          count ++;
        }
        else 
        {
                      // First duplicate, need to update l, r and count
           int temp = cMap.find(s[i])->second + 1;
           for(j = l; j <= cMap.find(s[i])->second; j++) {  cMap.erase(s[j]); }
           l = temp; 
           cMap.insert(std::pair<char, int>(s[i], i));
           r = i;
           if(max < count) max = count; 
           count = r - l +1;
        }
      }
      return max; 
    }
};
    
int main()
{
//    string str = "wlrbbmqbhczdarzowkky";
                //01234567890123456789
/*   string str = "wlrbbmqbhc"
                "zdarzowkky"
                "hiddqscdxr"
                "jmowfrxsjy"
                "bldbefsarc"
                "bynecdyggx"
                "xpklorelln"
                "mpapqfwkho"
                "pkmco"; 
*/
//    string str = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
string str = "hnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcac";

//   string str = "gabcdbeb"; 
   Solution sol; 
   cout << sol.lengthOfLongestSubstring(str) << endl; 
   
   return 0;
}
