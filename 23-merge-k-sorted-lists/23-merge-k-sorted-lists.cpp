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
    
    // bool cmp(ListNode* l1, ListNode* l2){
    //     return l1->val > l2->val;
    // }
    
    struct cmp {
        bool operator()(ListNode* l1, ListNode* l2){
            return l1->val > l2->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        
        for(ListNode* head: lists){
            if(head != NULL)
                pq.push(head);
        }
        
        ListNode* prehead = new ListNode(),*curr = prehead;
        prehead->next = NULL;
        
        while(!pq.empty()){
            ListNode* topNode = pq.top();
            // cout<<topNode->val<<' ';
            pq.pop();
            
            curr = curr->next = topNode;
            if(topNode->next){
                pq.push(topNode->next);
            }
        }
        
        return prehead->next;
    }
};