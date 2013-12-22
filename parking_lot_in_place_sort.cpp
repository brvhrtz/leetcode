/*  Google Revenge ! Oh yeah! 
* Parking Lot In-place Sort with one additional mem space
*  Input: unsorted array a[N]
*  Output: sorted array  a[N]
* Requirement: time complexity O(n), space complexity O(1), only swap is available 
*/

#include <iostream>

using namespace std;

class Solution
{
  public: 
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp; 
        return; 
    }
    void mysort(int a[], int len)
    {
        int l = 0; 
        int count = len; 
        while(count > 0 && l < len)
        {
            if(a[l] != a[a[l]-1]) 
              {
                  swap(a[l], a[a[l]-1]);
                  count--; // one guy in place
              }
            else {l++; count--;}
        }
    }
};

int main()
{
   cout << "Hello World" << endl; 
   Solution sol;
   int a[] = {5, 2, 1, 4, 3, 9, 8, 7, 6};
   
   int len = sizeof(a)/sizeof(int);
   sol.mysort(a, len);
   for(int i = 0; i < len; i++)
   {
       cout << a[i] << " ";
   }
   cout << endl; 
   
   return 0;
}
