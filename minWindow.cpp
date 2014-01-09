/*
 * Find the minimum window that contains all the chars of a string
 *
 * So much to say about this one
    1. spent at least 3 full days for it and its sister problems "find concatence of all strings"
 *  2. The brutal force problem is easy to devise and is also helpful in building confidence. 
 *  3. first problem I use the skeleton method and it's a success 
       I was able to keep my sanity and finish the program without major grammar error for first time
 *  4. The basic algorithm is also devised pretty fast however, I was fumbling terribly doing conditioning. 
    5. I really need to have a better way of streamlining conditioning 
          the skeleton already helped a lot but still I need to be 
          even more efficient and fast on that part to free my mind to be able to 
          focused on streamlining algorithm 
 */

class Solution {
public:
    string minWindow(string S, string T) {
        map<char, int> cntMap; // the cache
        map<char, int> cnt; // the real counter 
        
        int N, M;  // S.size() and T.size()
        string res; 
        int l, r; // left and right side of window  
        int i, j; // numerical iterators
        int maxed; // record how many keys has already been filled up  
        bool exist = false; 
        
        if(S.size() == 0) return res;
        if(T.size() == 0) return res; 
        N = S.size();
        M = T.size();
        
        // init the count cache
        for(i = 0; i<M; i++){
            if(cntMap.find(T[i])==cntMap.end()){ 
              cntMap[T[i]] = 1; 
              cnt[T[i]] = 0; 
            }
            else
              cntMap[T[i]]++;  
        }
        
        
        // init l, r at 0
        l = 0; r = 0; 
        maxed = 0; 
        res = S + "$"; 
        while(r < N){
          // move r rightward till one known char is reached
          if(cntMap.find(S[r])!=cntMap.end())
          {
          // count S[r]
          cnt[S[r]]++;
          
          //if some element's cnt is maxed
          if(cnt[S[r]] >= cntMap[S[r]]){ 
              if(cnt[S[r]] == cntMap[S[r]]) maxed++; 
           // if maxed < M, continue move r
            if(maxed == cntMap.size()){
                 exist = true; 
                 // if maxed == M, we have a match, record the substr if shorter
                 while(l <= r){
                     // move l rightwards until we need to do maxed-- 
                     // E.g. any element's count is reduced below max   
                     if(cntMap.find(S[l])!=cntMap.end()){
                         
                         if(cnt[S[l]] == cntMap[S[l]]) break; // while exit, stop moving l
                         else if(cnt[S[l]]>cntMap[S[l]]){
                          //   maxed--; 
                             cnt[S[l]]--; 
                             l++; 
                         } // element in T but has overflow 
                     } 
                     else {l++;} // element not in T
                 }
                 if((r-l+1) < res.size()) 
                 res = S.substr(l, r-l+1);
             }
          }
          }
          r++; 
        // start to move r rightwards again until maxed == M again
        }  
        if(exist) 
            return res;
        else 
            return ""; 
    }
};

int main()
{
   cout << "Hello World" << endl;
   Solution sol;
 //  vector<string> L = {"fooo","barr","wing","ding","wing"};
 //  string S = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
  string S = "cabeca";
  string T = "cae";
  string res;

   res = sol.minWindow(S, T);
   cout << res << endl;

   return 0;
}
