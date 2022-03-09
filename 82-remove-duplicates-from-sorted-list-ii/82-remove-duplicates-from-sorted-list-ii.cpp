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
    ListNode* deleteDuplicates(ListNode* head){
        if(head==NULL || head->next == NULL) return head;
        ListNode *prehead = new ListNode, *ptr = prehead, *ahead = head;
        prehead->next = head;
        while(ahead){
            if(ahead->next==NULL || ahead->val != ahead->next->val){
                ptr->next = ahead;
                ptr = ahead;
                ahead = ahead->next;
            }
            else{
                int currval = ahead->val;
                while(ahead && ahead->val == currval)
                    ahead = ahead->next;
            }
        }
        ptr->next = ahead;
        
        // prehead.next = NULL;
        return prehead->next;
    }
};
