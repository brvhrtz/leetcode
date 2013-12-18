// Adding two linked list
// Many gotchas 
// Need to learn ask yourself critical questions for loops & recursions
// 1. In what condition do I need to go to the next loop 
// 2. In what condition do I need to invoke this action? 
// 3. A good trick to avoid segmentation fault is to avoid using iter->next when possible. 


#include <iostream>

using namespace std;



 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
 
 ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *res, *it3, *it1, *it2, *temp;
        int val1, val2, sum, carry;
        
        if(!l1 && l2) return l2; // or copy l2
        if(l1 && !l2) return l1; // or copy l1
        if(!l1 && !l2) return NULL;
        
        it1 = l1; it2 = l2;
        cout << it1->val << " " << it2->val << endl; 
        sum = (it1->val + it2->val) % 10;
        carry = (it1->val + it2->val) / 10;
        cout << "sum: " << sum << " carry:" << carry << endl; 
        res = new ListNode(sum);
        cout << it1->val << " " << it2->val << endl; 
      
         
        it3 = res;
        while(it1->next || it2->next || carry > 0)
        {
            // update pointers 
            if(it1->next) it1 = it1->next; 
            if(it2->next) it2 = it2->next;
            
            // calculate with new pointers
            if(it1) val1 = it1->val; else  val1 = 0;
            if(it2) val2 = it2->val; else  val2 = 0;
            sum = (val1 + val2 + carry)%10;
            cout << "sum = " << sum << " carry:" << carry << endl; 
                  
            // add new nodes 
            if(it1 || it2 || carry > 0)
            {
            temp = new ListNode(sum);
            it3->next = temp;
            it3 = it3->next;
            }
            
            carry = (val1 + val2 + carry)/10; // update carry for next round
        }
        return res; 
}
    
int main()
{
   cout << "Hello World" << endl; 
   
   ListNode *l1, *l2, *l3;
   l1 = new ListNode(5);
   l2 = new ListNode(5);
   l3 = addTwoNumbers(l1, l2);
   
   while(l3)
   {
       cout << l3->val << " -> " << endl; 
       l3 = l3->next;
   }
   
   return 0;
}
