class CombinationIterator {
public:
    vector<string> vec;
    void helper(string &characters,int start,int len,string &str){
        if(len==0){
            vec.push_back(str);
            return;
        }
        
        for(int i=start;i<=characters.length()-len;i++){
            str.push_back(characters[i]);
            helper(characters,i+1,len-1,str);
            str.pop_back();
        }
    }
    
    CombinationIterator(string characters, int combinationLength) {
        string curr;
        helper(characters,0,combinationLength,curr);
        reverse(vec.begin(),vec.end());
        cout<<vec.size();
    }
    
    string next(){
        string res = !vec.empty() ? vec.back() : "";
        if(!vec.empty()) vec.pop_back();
        // cout<<res<<' ';
        return res;
    }
    
    bool hasNext() {
        return !vec.empty();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */