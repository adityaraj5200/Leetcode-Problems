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
    Node* cloneGraph(Node* node) {
        if(node == NULL) 
            return NULL;
        
        Node* copy = new Node(node->val);
        set<Node*> done; // Insert in this set when you have cloned orginal node and
        // and cloned and linked all of it's neighbor nodes
        
        unordered_map<Node*,Node*> mp;
        mp[node] = copy;
        
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()){
            Node *currNode = q.front();
            q.pop();
            if(done.find(currNode) != done.end())
                continue;
            
            for(Node* nextNode: currNode->neighbors){
                if(mp.find(nextNode) == mp.end()){
                    mp[nextNode] = new Node(nextNode->val);
                }
                
                mp[currNode]->neighbors.push_back(mp[nextNode]);
                q.push(nextNode);
            }
            
            done.insert(currNode);
        }
        
        return copy;
        
    }
};