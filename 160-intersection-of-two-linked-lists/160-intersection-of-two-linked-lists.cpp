/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = 0, sizeB = 0;
        
        ListNode *curr = headA;
        while(curr != NULL){
            sizeA++;
            curr = curr->next;
        }
        
        curr = headB;
        while(curr != NULL){
            sizeB++;
            curr = curr->next;
        }
        
        int diff = sizeA - sizeB;
        curr = diff>0 ? headA : headB;
        
        for(int i=0;i<abs(diff);i++)
            curr = curr->next;
        
        if(diff > 0) headA = curr;
        else headB = curr;
        
        while(headA && headB){
            if(headA == headB)
                return headA;
            
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
};