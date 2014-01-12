/* 
 *  A simple solution for 3sum variation closest
 * Also a simple extension of the 2 pointer algorithm. 
 * This is actuall a hidden DP, as on each calculation, 
   you know exactly what to throw away and dont need to recalculate them again
 */


class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int N = num.size(); 
        int i, j, k;
        int nt; // new target
        int res; // current closest sum
        int min = 0x7fffffff; // current min to target
        
        if(N<3) return -1; 
        std::sort(num.begin(), num.end());
        for(i = 0; i<N; i++){
            j = i+1; k = N-1; nt = target - num[i]; // 
            while(j<k){
              if(num[i] + num[j] + num[k] > target ) {
                  if(abs(num[k] + num[j] + num[i] - target) < min){
                      res = num[i]+num[k]+num[j];
                      min = abs(num[k] + num[j] - nt); 
                  }
                  k--;
              } 
              else if(num[i] +num[j]+num[k] < target) {
                  if(abs(num[k] + num[j] + num[i] - target) < min){
                      res = num[i]+num[k]+num[j];
                      min = abs(num[k] + num[j] - nt); 
                  }
                  j++;
              }
              else if(num[i] + num[j] + num[k] == target) {
                  return target;
              }
            }
        }
        return res; 
    }
};
