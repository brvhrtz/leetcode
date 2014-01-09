/*
 *
 * Summary: 
      1. string can be consider a descendant of vectors 
         1.1 every single oper you can do with vectors you can do with strings
         1.2 important string extras, e.g.  "+" ,  c_str, find, substr, compare
 *
 *
 */
int main()
{

     // constructors used in the same order as described above:
  std::vector<int> first;                                // empty vector of ints
  std::vector<int> second (4,100);                       // four ints with value 100
  std::vector<int> third (second.begin(),second.end());  // iterating through second
  std::vector<int> fourth (third);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
    
    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  // C++11
    vec.erase(vec.begin() + 3); // erase 4th element
    vec.erase(vec.begin(), vec.begin() + 3); 
    // erase from begin() to begin() + 2 but not begin()+3 
    // easier to understand thinking of vec.erase(vec.begin(), vec.end()); 
    
    for(int i = 0; i < vec.size(); i++) cout << vec[i] << " "; 
    cout << endl; 
    
    return 0; 
}




/*
 * Clean up of vector of pointers to dynamically allocated data structures
 * Key Points: 
 * 1. Two method:
      - Use iterator    "delete *iter"
      - Use numbered [] operator  "delete vec[i]"
 * 2. After deletion, the size of vector remains unchanged, each item now point to undefined address
 * 3. Do a "vec.clear()" to clear the vector itself. 
 */ 

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
