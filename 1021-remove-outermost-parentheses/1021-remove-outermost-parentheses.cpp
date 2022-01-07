class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int stack = 0;
        
        for(char &ch: s)
            if(ch == '(' ? stack++ > 0 : --stack > 0)
                ans.push_back(ch);
        
        return ans;
    }
};