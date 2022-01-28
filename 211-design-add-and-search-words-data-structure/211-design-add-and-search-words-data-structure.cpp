class WordDictionary {
private:
    unordered_map<int,vector<string>> hashmap;
    bool isEqual(string &s, string &word){
        for(int i=0;i<s.length();i++)
            if(word[i]!='.' && word[i] != s[i])
                return false;
        return true;
    }
    
public:
    WordDictionary() {}
    
    void addWord(string word) {
        hashmap[word.length()].push_back(word);
    }
    
    bool search(string word) {
        for(string &s: hashmap[word.length()])
            if(isEqual(s, word))
                return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */