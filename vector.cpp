/*
 *
 * Summary: 
      1. string can be consider a descendant of vectors 
         1.1 every single oper you can do with vectors you can do with strings
         1.2 important string extras, e.g.  "+" ,  c_str, find, substr, compare
 *
 *
 */
 
 
#include <iostream>
#include <vector>

using namespace std; 

int main()
{
    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    vec.erase(vec.begin() + 3); // erase 4th element
    vec.erase(vec.begin(), vec.begin() + 3); 
    // erase from begin() to begin() + 2 but not begin()+3 
    // easier to understand thinking of vec.erase(vec.begin(), vec.end()); 
    
    for(int i = 0; i < vec.size(); i++) cout << vec[i] << " "; 
    cout << endl; 
    
    return 0; 
}
