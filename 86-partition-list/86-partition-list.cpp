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
    ListNode* partition(ListNode* head, int x) {
        ListNode *prehead = new ListNode, *greaterList = new ListNode, *curr = head;
        ListNode *ptr1 = prehead ,*ptr2 = greaterList;
        prehead->next = head;
        // return prehead->next;
        while(curr){
            if(curr->val < x){
                ptr1->next = curr;
                ptr1 = ptr1->next;
            }
            else{
                ptr2->next = curr;
                ptr2 = ptr2->next;
            }
            curr = curr->next;
        }
        ptr2->next = NULL;
        ptr1->next = greaterList->next;
        return prehead->next;
    }
};