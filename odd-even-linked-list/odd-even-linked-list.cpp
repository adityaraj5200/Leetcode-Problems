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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *preOdd = new ListNode(-1,head), *preEven = new ListNode(-1,head->next);
        ListNode *currOdd = head, *currEven = head->next;
        while(currOdd && currEven){
            currOdd = currOdd->next = currEven->next;
            if(currOdd) currEven = currEven->next = currOdd->next;
        }
        currOdd = preOdd;
        while(currOdd->next)
            currOdd = currOdd->next;
        currOdd->next = preEven->next;
        return preOdd->next;
    }
};