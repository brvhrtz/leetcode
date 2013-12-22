/*
 * Slow version of The Reverse Linked List in K groups problem
 * Gotcha:
 *    1. This implementation is straight forward. 
      2. The use after update issue come again in loops and cause seg fault 
 * Gains:
      1. Creating a dummy node save some headache in handling list head with min mem cost
      2. Use the linked list mem map to help you recognize all the link changes
      3. Use a sub function to ease the pain of looking at & remembering too many line of codes 
 */


#include <iostream>
#include <vector> 

using namespace std;


//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    void reverseK(ListNode *pre, ListNode *first, ListNode *last, int k)
    {
        ListNode *cur; 
        ListNode *post = last->next; 
        
        cout << "in reverseK   k = " << k << endl;
        cout << "pre: " << pre->val << endl; 
        cout << "first: " << first->val << endl; 
        cout << "last: " << last->val << endl; 
        
        // evaluate addrs container
        // for 3 nodes pack, vec == { &post, &1st, &2nd }  
       
        vector<ListNode*> vec; 
        vec.push_back(last->next);
        cur = first;  int count = k; 
        while(count > 1)
        {   
            vec.push_back(cur);
            cur = cur->next; 
            count--;
        }
                
        count = 0;
        pre->next = last;
        cur = first;
        while(count < k)
        {  // resulting list:  pre->last  1st->post 2nd->1st 3rd/last->2nd
            ListNode *next = cur->next; 
            cur->next = vec[count];
            cur = next; 
            count++; 
        }
    }
    
    ListNode *reverseKGroup(ListNode *head, int k) {
        int len = 0; 
        ListNode  *pre, *first, *last; 
        
        if(!head) return NULL;
        
        // get length
        ListNode *cur = head; 
        while(cur)
        {
            len++;
            cur = cur->next; 
        }
        
        ListNode *dummy;
        dummy = new ListNode(-1); 
        dummy->next = head; 
        pre = dummy;
        first = head; 
        last = head;
        
        while(len >= k)
        {// reverse 3 at a time
         // since there is no previous linkage
         // keep track the addresses of previous, first, last node 
            int count = 1; 
            while(count < k) {last = last->next; count++; cout << count << endl;}
            reverseK(pre, first, last, k);
            
        // update len, pre, first, last
            len = len - k;
            pre = last; first = last -> next;  last = first; 
        }
        return dummy->next; 
    }
};

int main()
{
   cout << "Reverse List in K group(s)" << endl;

   ListNode *head;

   head = new ListNode(1);
   ListNode *first = new ListNode(2);

   head->next = first;

   ListNode *cur;
   cur = head;
      while(cur)
   {
       cout << cur->val << endl;
       cur = cur->next;
   }
   cout << endl;

   Solution sol;
   head = sol.reverseKGroup(head, 2);

   while(head)
   {
       cout << head->val << endl;
       head = head->next;
   }
   cout << endl;

   return 0;
}
