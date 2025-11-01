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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* preHeadNodePtr = new ListNode(0,head);
        ListNode* prev = preHeadNodePtr;
        sort(nums.begin(),nums.end());
        while(prev->next!=NULL){
            if(binary_search(nums.begin(),nums.end(),prev->next->val)){
                // don't include
                prev->next = prev->next->next;
            }
            else{
                prev = prev->next;
            }
        }

        return preHeadNodePtr->next;
    }
};