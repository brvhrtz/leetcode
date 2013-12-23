/*
 *  Reverse linked list in groups of k nodes
 *   This is the accepted version 
 *  Key Takeaways: 
    1. For linked list issues always use mem map to help you think
    2. Write psudo code on paper is quicker with all mem maps and other markers to facilitate your thought
    3. Boundary check, NAO issue, writing faster program still needs improvement
 *  Time Saving: 
 *  1. Removed function calls, 
    2. Removed get length 
    3. Only need to traverse the list once
    4. a k ptr cache is used to store the just traversed k nodes
    5. this cache is a vector so it automatically recorded the traverse sequence. 
 * Gotchas:
   1. conditions (!cur) or (cur) happens again
   2. use New as Old (NAO issue)
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode  *parent, *cur;
//      ListNode *pre, *next, *first;  // no need as vec automatically generate ranks
        
        if(!head) return NULL;
        
        cur = head; 
        
        // init dummy
        ListNode *dummy;
        dummy = new ListNode(-1); 
        dummy->next = head; 
        
        // init for first loop
        parent = dummy;
        cur = head;
        while(cur)
        {
          vector<ListNode*> vec; // hold k addresses
          int cnt = 0;
          while(cur && cnt < k )
          {
            vec.push_back(cur);
            cnt++;
            cur = cur->next;
          }
          
          if(cnt<k) 
          {
              // reach the end without a full k nodes sequence
              return dummy->next;
          }
          else
          {
              // got a full k seq, cur = k + 1, first = 1, parent = 0
           
              vec.front()->next = cur; // 1 -> k+1
              for(int i = 1; i < k; i++)
              {
                  vec[i]-> next = vec[i-1];  // i -> i-1
              }
              parent->next = vec.back();
              parent = vec.front(); // new parent = 1
          }
          vec.clear();
        }
        
        return dummy->next; 
    }
};


int main()
{
   cout << "Reverse List in K group(s)" << endl; 
   
   ListNode *head, *cur, *temp; 
   
   int seq[] = {1, 2, 3, 4};
   head = new ListNode(seq[0]);
   cur = head; 
   for(int i = 1; i < sizeof(seq)/sizeof(int); i++)
   {
       temp = new ListNode(seq[i]);
       cur->next = temp; 
       cur = cur->next; 
   }
   
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
