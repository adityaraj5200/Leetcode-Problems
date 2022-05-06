class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> stk;
        for(char &ch: s){
            if(stk.empty() || stk.top().first!=ch)
                stk.push({ch,1});
            else stk.top().second++;
            
            if(stk.top().second == k)
                stk.pop();
        }
        
        string ans;
        while(!stk.empty()){
            auto p = stk.top();
            stk.pop();
            string temp(p.second,p.first);
            ans += temp;
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};