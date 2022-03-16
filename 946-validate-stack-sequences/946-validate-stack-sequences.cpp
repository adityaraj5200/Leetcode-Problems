class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        const int n = pushed.size();
        int j=0;
        stack<int> stk;
        for(int i=0;i<n;i++){
            stk.push(pushed[i]);
            while(!stk.empty() && stk.top()==popped[j]){
                stk.pop();
                j++;
            }
        }
        return j==n;
    }
};