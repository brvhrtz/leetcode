/*
 * Clean up of vector of pointers to dynamically allocated data structures
 * Key Points: 
 * 1. Two method:
      - Use iterator    "delete *iter"
      - Use numbered [] operator  "delete vec[i]"
 * 2. After deletion, the size of vector remains unchanged, each item now point to undefined address
 * 3. Do a "vec.clear()" to clear the vector itself. 
 */ 

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
  int x; 
  int y;   
};

int main()
{
   cout << "Hello World" << endl; 
   
   vector<Node *> vec; 
   Node *ptr; 
   
   for(int i = 0; i < 10; i++)
   {
     ptr = new Node; 
     ptr->x = i;
     ptr->y = i + 100; 
     vec.push_back(ptr);
   }
   
   cout << "vec size is : " << vec.size() << endl; 
   
      for(int i = 0; i < vec.size(); i++)
   {
       cout << vec[i]->x << " " << vec[i]->y << endl; 
   }
   /*
   for(int i = 0; i < vec.size(); i++)
   {
       delete vec[i];
       vec[i] = NULL; 
   }
   vec.clear();
   */
   
   std::vector<Node *>::iterator iter;
   for(iter = vec.begin(); iter != vec.end(); iter++)
   {
       delete *iter;
   }
   vec.clear(); 
   
   for(int i = 0; i < vec.size(); i++)
   {
       cout << vec[i]->x << endl; 
   }
   cout << "vec size is : " << vec.size() << endl; 
   
   return 0;
}
