/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> result;
    void traverse(Node* root){
        result.push_back(root->val);
        for(Node* &childNode: root->children)
            traverse(childNode);
    }
    vector<int> preorder(Node* root) {
        if(root != NULL)
            traverse(root);
        return result;
    }
};