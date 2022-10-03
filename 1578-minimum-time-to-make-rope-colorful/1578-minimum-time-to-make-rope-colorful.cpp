class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0, n = colors.length();
        for(int i=0;i<n-1;i++){
            if(colors[i] == colors[i+1]){
                int idx = i, maxValue = 0, sum = 0;
                while(idx<n && colors[idx] == colors[i]){
                    sum += neededTime[idx];
                    maxValue = max(maxValue, neededTime[idx]);
                    idx++;
                }
                ans += sum-maxValue;
                i = idx-1;
            }
        }
        
        return ans;
    }
};