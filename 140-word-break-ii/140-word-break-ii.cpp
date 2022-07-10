class Solution {
public:
    struct Trie{
        Trie *child[26];
        bool isEnd;
        Trie(){
            for(int i=0;i<26;i++)
                child[i] = NULL;
            isEnd = false;
        }
    };
    
    Trie *root;
    
    void insert(string &s){
        Trie *curr = root;
        for(char &ch: s){
            if(curr->child[ch-'a'] == NULL)
                curr->child[ch-'a'] = new Trie();
            curr = curr->child[ch-'a'];
        }
        curr->isEnd = true;
    }
    
    vector<string> ans;
    string currstr="";
    
    void search(string &sentence,int idx,Trie *currnode){
        if(idx==sentence.length()){
            if(currstr.back()==' '){// this tells that last character added to currstr was a dictionary word.
                currstr.pop_back();
                ans.push_back(currstr);
                currstr += ' ';
            }
            
            return;
        }
        
        if(currnode->child[sentence[idx]-'a'] == NULL)
            return;
        
        currstr += sentence[idx];
        currnode = currnode->child[sentence[idx]-'a'];
        
        if(currnode->isEnd){
            currstr += ' ';
            search(sentence,idx+1,root);
            currstr.pop_back();
        }
        
        search(sentence,idx+1,currnode);
        currstr.pop_back();
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        root = new Trie();
        for(string &str: wordDict)
            insert(str);
        
        search(s,0,root);
        return ans;
    }
};