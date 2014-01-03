/*
 *  DP version
 *  Algorithm: 
       1. This is a rather difficult DP to think of.
       2. sweep forward and at each node sweep backwords 
       3. My brain is hurting right now. The algorithm obviously needs some very clever design
       4. I haven't grasped the key clue (e.g. in what condition you can claim you don't need to calculate this guy with previous calculations)
       5. When design a DP, you need to think of:
            what's to track (computation that has already been done)
            how to design your loop
               loop forward + inner loop forward
               loop forward + inner loop backward
               loop from middle, loop both backward and forward
               loop backward + inner loop forward
 */

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int i, j;
        vector<bool> vec(s.size() + 1, false);
        
        vec[0] = true; 
        // 0 is dummy, vec[i] means from the ith char aka s[i-1] backwards is a wordbreak
        for(i = 1; i <= s.size(); i++){ // check ith char
            for(j = i-1; j >= 0; j--){
                 if(vec[j]&& dict.count(s.substr(j, i-j))>0)
                 {
                     vec[i] = true; 
                     break; 
                 }
            }
        }
        return vec[s.size()];
    }
};

/*
 *   Using multimap to reduce some complexity
 */

class Solution2 {
public:
    bool helper(string s, int start, int N, unordered_set<string> &dict, multimap<int, int> &mmap)
    {
        std::pair<std::multimap<int, int>::iterator, std::multimap<int, int>::iterator> ret;
        std::multimap<int, int>::iterator iter; 
        
        if(start >= N) return true; 
        
        ret = mmap.equal_range(start);
        for(iter = ret.first; iter!=ret.second; ++iter)
        {
            if(helper(s, iter->second + 1, N, dict, mmap)) return true; 
        }
        return false;
    }
    
    bool wordBreak(string s, unordered_set<string> &dict) {
        multimap<int, int> mmap; 
        int i, j;
        string str; 
        
        for(i = 0; i < s.size(); i++){
            for(j = i; j< s.size(); j++){
                str = s.substr(i, j-i+1);
                if(dict.count(str)>0) mmap.insert(std::pair<int, int>(i,j));
            }
        }
        return helper(s, 0, s.size(), dict, mmap);
    }
};

/*
 *  Simplest recursion: conceptually simple but brutal force  
 */
class Solution3 {
public:
    bool helper(string s, int start, int N, unordered_set<string> &dict)
    {
        int i;
        string str; 
        
        if(i >= N) return true; 
        for(i = start; i < N; i++)
        {
            str = str+s[i];
            if(dict.count(str) > 0 && helper(s, i+1, N, dict)) return true; 
        }
        return false;
    }
    bool wordBreak(string s, unordered_set<string> &dict) {
        return helper(s, 0, s.size(), dict);
    }
};
