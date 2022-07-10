class Solution {
public:
    struct Trie{
        unordered_map<string,Trie*> child;
        // bool isEnd;
        Trie(){
            // isEnd = false;
        }
    };
    
    Trie *root;
    
    void insert(string &dir){
        Trie *curr = root;
        int idx = 1, n = dir.length();
        while(idx<n){
            string str = "";
            while(idx<n && dir[idx]!='/')
                str += dir[idx++];
            idx++;
            
            if(curr->child.find(str) == curr->child.end())
                curr->child[str] = new Trie();
            
            curr = curr->child[str];
        }
        // curr->isEnd = true;
    }
    
    void remove(string &dir){ 
        Trie *curr = root;
        int idx = 1, n = dir.length();
        while(idx<n){
            string str = "";
            while(idx<n && dir[idx]!='/')
                str += dir[idx++];
            idx++;
            
            if(curr->child.find(str) != curr->child.end())
                curr = curr->child[str];
            else break;
        }
        curr->child = {};
        // curr->isEnd = true;
    }
    
    vector<string> ans;
    string currstr = "";
    
    void traverse(Trie* node){
        if(node->child.size() == 0){
            if(!currstr.empty())
                ans.push_back(currstr);
            
            return;
        }
        
        for(auto p: node->child){
            string foldername = p.first;
            Trie* nextnode = p.second;
            
            currstr += "/" + foldername;
            
            traverse(node->child[foldername]);
            
            int pop_these = foldername.size() + 1;
            while(pop_these--)
                currstr.pop_back();
        }
    }
    
    vector<string> removeSubfolders(vector<string>& folder){
        root = new Trie();
        
        for(string &s: folder) insert(s);
        for(string &s: folder) remove(s);
        traverse(root);
        
        return ans;
    }
};