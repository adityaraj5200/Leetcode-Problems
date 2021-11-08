class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for(char &ch: s){
            if(stk.empty() || ch != stk.top()) 
                stk.push(ch);
            else stk.pop();
        }
        string result;
        while(!stk.empty()){
            result.push_back(stk.top());
            stk.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};