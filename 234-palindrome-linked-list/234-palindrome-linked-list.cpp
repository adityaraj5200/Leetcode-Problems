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
    ListNode* reverseLL(ListNode* head){
        ListNode *curr = head, *behind = NULL, *ahead = head->next;
        while(curr){
            curr->next = behind;
            behind = curr;
            curr = ahead;
            if(ahead != NULL)
                ahead = ahead->next;
        }
        
        return behind;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL)
            return true;
        
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *tail = reverseLL(slow), *curr = head;
        
        while(tail != NULL){
            if(tail->val != curr->val)
                return false;
            
            tail = tail->next;
            curr = curr->next;
        }
        
        return true;
    }
};