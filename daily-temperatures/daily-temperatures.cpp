class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // ngr
        int n = temperatures.size();
        vector<int> result(n,-1);
        stack<int> stk;
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && temperatures[stk.top()] <= temperatures[i])
                stk.pop();
            
            if(!stk.empty())
                result[i] = stk.top();
            
            stk.push(i);
        }
        
        for(int i=0;i<n;i++){
            result[i] = result[i]==-1 ? 0 : result[i]-i;
        }
        
        return result;
    }
};