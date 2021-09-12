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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *curr,*currhead,*ahead=head->next;
        curr=currhead=head;
        ListNode node(0),*prehead=&node,*prev=prehead,*prevtail=prehead;
        prehead->next = head;
        
        int size = 0;
        while(curr){
            curr = curr->next;
            size++;
        }
        curr=head;
        
        int groups = size/k;
        while(groups--){
            for(int i=0;i<k;i++){
                curr->next = prev;
                prev = curr;
                curr = ahead;
                if(ahead) ahead = ahead->next;
            }
            prevtail->next = prev;
            currhead->next = curr;
            prevtail = currhead;
            currhead = curr;
        }
        return prehead->next;
    }
};