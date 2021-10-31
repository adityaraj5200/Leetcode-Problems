/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
//     Node* helper(Node *node){
//         Node *curr = node,*tail = node;
//         while(tail->next)
//             tail = tail->next;
        
//         while(curr){
//             if(curr->child){
//                 Node *childNode = curr->child;
//                 Node *nextNode = curr->next;
//                 Node *returnedNode = helper(curr->child);
//                 curr->child = NULL;
                
//                 childNode->prev = curr;
//                 curr->next = childNode;
                
//                 returnedNode->next = nextNode;
//                 if(nextNode) nextNode->prev = returnedNode;
                
//                 // curr = tempcurr;
//                 curr = returnedNode;
//             }
//             curr = curr->next;
//         }
//         return tail;
//     }
    Node* flatten(Node* head) {
        for(Node *curr=head;curr;curr=curr->next){
            if(curr->child){
                Node *nextNode = curr->next,*childNode = curr->child;
                curr->next = childNode;
                childNode->prev = curr;
                while(childNode->next)
                    childNode = childNode->next;
                childNode->next = nextNode;
                if(nextNode) nextNode->prev = childNode;
                curr->child = NULL;
            }
        }
        return head;
    }
};