/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node){
        if(node==NULL) return node;
        set<Node*> seen;
        map<Node*,Node*> clonecopy;
        queue<Node*> q;
        Node* clone = new Node(node->val);
        clonecopy[node] = clone;
        q.push(node);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(seen.find(curr) != seen.end()) continue;
            seen.insert(curr);
            for(Node* neighborNode: curr->neighbors){
                if(seen.find(neighborNode) != seen.end()) continue;
                
                if(clonecopy.find(neighborNode) == clonecopy.end())
                    clonecopy[neighborNode] = new Node(neighborNode->val);
                clonecopy[curr]->neighbors.push_back(clonecopy[neighborNode]);
                clonecopy[neighborNode]->neighbors.push_back(clonecopy[curr]);
                
                q.push(neighborNode);
            }
        }
        return clone;
    }
};