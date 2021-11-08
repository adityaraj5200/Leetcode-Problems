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
    int getsize(ListNode *curr){
        int cnt = 0;
        while(curr && ++cnt)
            curr = curr->next;
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // for(ListNode *currA = headA; currA ; currA = currA->next)
        //     for(ListNode *currB = headB; currB ; currB = currB->next)
        //         if(currA == currB)
        //             return currA;
        int size1 = getsize(headA), size2 = getsize(headB), diff = abs(size1-size2);
        ListNode *ptr1 = size1>size2?headA:headB, *ptr2=ptr1==headA?headB:headA;
        while(diff--)
            ptr1 = ptr1->next;
        while(ptr1 != ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
};