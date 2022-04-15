/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode *prehead = new ListNode(-1,head);
        ListNode *curr = head, *ahead = head->next, *behind = prehead;
        
        while(curr && curr->next){
            behind->next = ahead;
            curr->next = ahead->next;
            ahead->next = curr;
            
            behind = curr;
            curr = curr->next;
            if(curr) ahead = curr->next;
        }
        
        return prehead->next;
    }
};