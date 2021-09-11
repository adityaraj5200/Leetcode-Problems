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
    void reorderList(ListNode* head) {
        if(head->next==NULL) return;
        ListNode *head1,*head2,*curr1,*curr2;
        head1 = curr1 = head;
        int size = 0;
        while(curr1){
            size++;
            curr1 = curr1->next;
        }
        
        curr1 = head;
        int partition = (size+1)/2;
        while(--partition)
            curr1 = curr1->next;
        
        head2 = curr2 = curr1->next;
        curr1->next = NULL;
        
        ListNode *prev=NULL,*ahead=head2->next;
        while(curr2){
            ahead = curr2->next;
            curr2->next = prev;
            prev = curr2;
            curr2 = ahead;
        }
        head2 = prev;
        
        curr1 = head1;
        curr2 = head2;
        
        while(curr1 && curr2){
            ListNode *temp = curr1->next;
            curr1->next = curr2;
            curr1 = temp;
            if(curr2){
                temp = curr2->next;
                curr2->next = curr1;
                curr2 = temp;
            }
        }
    }
};