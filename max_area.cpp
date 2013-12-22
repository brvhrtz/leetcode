#include <iostream>
#include <vector> 

using namespace std;

class Solution {
public:
    int volumn(int x1, int y1, int x2, int y2)
    {
        return abs(x2-x1) * std::min(y1, y2); 
    }
    int maxArea(vector<int> &height) {
        int max = 0;
        int vol = 0;
        int l, r;
        
//        if(height.size() < 2) return 0; 
        
        l = 0; r = height.size() - 1;
        while(l > r)        
        {
            vol = volumn(l, height[l], r, height[r]);
            cout << vol <<endl;
            max = std::max(max, vol);
            if(height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return max;  
    }
};

int main()
{
   cout << "Hello World" << endl; 
  
   Solution sol; 
   
   vector<int> vec = {1 , 1};
   cout << sol.maxArea(vec) << endl; 

   return 0;
}
