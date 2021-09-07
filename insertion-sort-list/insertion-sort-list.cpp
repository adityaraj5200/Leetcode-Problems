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
    ListNode* insertionSortList(ListNode* head) {
        for(auto it=head;it;it=it->next)
            for(auto it2=it;it2;it2=it2->next){
                if(it2->val < it->val){
                    swap(it->val,it2->val);
                }
            }
        return head;
    }
};