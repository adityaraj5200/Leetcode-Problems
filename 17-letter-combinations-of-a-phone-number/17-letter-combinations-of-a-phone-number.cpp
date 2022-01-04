class Solution {
public:
    vector<string> res;
    vector<vector<char>> store = {{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    
    void helper(string &digits,int i,string &curr){
        if(i==digits.length()){
            res.push_back(curr);
            return;
        }
        
        for(char &ch: store[digits[i]-'0']){
            curr.push_back(ch);
            helper(digits,i+1,curr);
            curr.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        string curr;
        helper(digits,0,curr);
        return res;
    }
};