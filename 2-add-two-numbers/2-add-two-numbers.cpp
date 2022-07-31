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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL&&l2==NULL)
            return l1;
        int c=((l1==NULL?0:l1->val)+(l2==NULL?0:l2->val))/10;
        ListNode *head=new ListNode(((l1==NULL?0:l1->val)+(l2==NULL?0:l2->val))%10);
        l1=l1==NULL?l1:l1->next;
        l2=l2==NULL?l1:l2->next;
        ListNode *c1=head;
        int i=0;
        while(true)
        {
            if(l1==NULL&&l2==NULL)
            {
                if(c==0)
                {
                    cout<<"in c==0 "<<i++<<endl;
                    return head;
                }
                cout<<"in NULL "<<i++<<endl;
                c1=ins(c,c1);
                return head;
                
            }
            if(l1==NULL)
            {
                cout<<"in l1==NULL "<<i++<<endl;
                c1=ins((l2->val+c)%10,c1);
                c=(l2->val+c)/10;
                l2=l2->next;
            }
            else if(l2==NULL)
            {
                cout<<"in l2==NULL "<<i++<<endl;
                c1=ins((l1->val+c)%10,c1);
                c=(l1->val+c)/10;
                l1=l1->next;
            }
            else
            {
                cout<<"in else "<<i++<<endl;
                c1=ins((l1->val+l2->val+c)%10,c1);
                c=(l1->val+l2->val+c)/10;
                l1=l1->next;
                l2=l2->next;
            }
        }
        return head;
    }
    ListNode* ins(int n,ListNode* c)
    {
        ListNode *t=new ListNode(n);
        c->next=t;
        return c->next;
    }
};