/*
 * Merge two sorted linked list
 * Tips: 
     1.Adding dummy node helps reduce boundary conditioning tremendously
 * Follow-up:
     2. Think about if no dummy added, what will happen
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define iMin  0x80000000
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummy;
        ListNode *p1, *cur1, *cur2; 
        
        if(!l1 && !l2) return NULL; 
        if(!l1) return l2; 
        if(!l2) return l1; 
        
        //add dummy node as l1's new head
        dummy = new ListNode(iMin);
        dummy->next = l1; 
        l1 = dummy; 
        
        cur1 = l1; 
        cur2 = l2; 
        while(cur1 && cur2){
            if(cur1->val <= cur2->val) {  // keep track of parent node 
              p1 = cur1; 
              cur1 = cur1->next;
            } 
            else { // 
              p1->next = cur2;
              cur2 = cur2->next; 
              p1->next->next = cur1;
              p1 = p1->next; 
            }
        }
        if(cur2 == NULL ) {
            // remove dummy
        }
        if(cur1 == NULL) { 
        // append rest of l2 to l1
          p1->next = cur2; 
        }
        dummy = l1; 
        l1 = l1->next; 
        delete dummy; 
        return l1; 
    }
};
