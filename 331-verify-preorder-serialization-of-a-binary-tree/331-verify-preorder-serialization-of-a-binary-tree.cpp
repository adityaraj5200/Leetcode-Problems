class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder == "#") return true;
        stack<int> stk;
        int i = 0, n = preorder.length();
        while(i<n){
            if(i!=0 && stk.empty())
                return false;
            if(preorder[i] == '#'){
                if(stk.empty()) return false;
                stk.top()++;
                while(!stk.empty() && stk.top() == 2){
                    stk.pop();
                    if(!stk.empty())
                        stk.top()++;
                }
                i++;
            }
            else{
                stk.push(0);
                while(i<n && preorder[i] != ',')
                    i++;
            }
            i++;
        }
        return stk.empty();
    }
};