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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode node,*prehead=&node,*curr=prehead,*leftside=NULL,*tail=NULL,*prev,*ahead;
        prehead->next = head;
        for(int i=0;i<left-1;i++)
            curr = curr->next;
        prev = leftside = curr;
        curr = tail = curr->next;
        ahead = curr->next;
        for(int i=0;i<right-left+1;i++){
            curr->next = prev;
            prev = curr;
            curr = ahead;
            if(ahead) ahead=ahead->next;
        }   
        leftside->next = prev;
        tail->next = curr;
        return prehead->next;
    }
};