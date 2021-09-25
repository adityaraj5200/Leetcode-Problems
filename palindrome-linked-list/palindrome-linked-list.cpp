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
    queue<ListNode*> q;
    bool isPalindrome(ListNode* head) {
        int size = 0;
        ListNode* curr = head;
        while(curr){
            curr = curr->next;
            size++;
        }
        curr = head;
        stack<int> stk;
        for(int i=0;i<size/2;i++){
            stk.push(curr->val);
            curr = curr->next;
        }
        if(size & 1) curr = curr->next;
        while(curr){
            if(curr->val != stk.top()) return false;
            stk.pop();
            curr = curr->next;
        }
        return true;
    }
};