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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int,int> hash;
        for(auto &node: lists){
            ListNode *curr = node;
            while(curr != NULL){
                hash[curr->val]++;
                curr = curr->next;
            }
        }
        
        ListNode *prehead = new ListNode(-1,NULL), *curr = prehead;
        
        for(auto &p: hash){
            while(p.second>0){
                curr = curr->next = new ListNode(p.first);
                p.second--;
            }
        }
        
        return prehead->next;
    }
};