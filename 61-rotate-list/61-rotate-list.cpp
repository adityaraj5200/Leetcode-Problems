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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        int size = 0;
        ListNode* ptr = head;
        while(ptr){
            size++;
            ptr = ptr->next;
        }
        k = k%size;
        if(k==0) return head;
        int times = size-k-1;
        ptr = head;
        while(times--)
            ptr = ptr->next;
        ListNode* newhead = ptr->next;
        ptr->next = NULL;
        ptr = newhead;
        while(ptr->next)
            ptr = ptr->next;
        ptr->next = head;
        return newhead;
    }
};