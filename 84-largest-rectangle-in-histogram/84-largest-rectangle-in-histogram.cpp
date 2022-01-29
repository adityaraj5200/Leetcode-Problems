class Solution {
public:
    vector<int> nsr(vector<int> &vec){
        const int n = vec.size();
        vector<int> result(n,n);
        stack<int> stk;
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && vec[i] <= vec[stk.top()])
                stk.pop();
            result[i] = !stk.empty() ? stk.top() : n;
            stk.push(i);
        }
        return result;
    }
    
    vector<int> nsl(vector<int> &vec){
        const int n = vec.size();
        vector<int> result(n,-1);
        stack<int> stk;
        for(int i=0;i<n;i++){
            while(!stk.empty() && vec[i] <= vec[stk.top()])
                stk.pop();
            result[i] = !stk.empty() ? stk.top() : -1;
            stk.push(i);
        }
        return result;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> NSR = nsr(heights);
        vector<int> NSL = nsl(heights);
        
        int ans = 0;
        
        for(int i=0;i<heights.size();i++)
            ans = max(ans, (NSR[i]-NSL[i]-1) * heights[i]);
        
        return ans;
    }
};