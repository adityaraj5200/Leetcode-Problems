class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        stack<int> suffixSum;
        int runningSum = 0;
        suffixSum.push(0);
        for(int i=cardPoints.size()-1,j=0;j<k;i--,j++){
            runningSum += cardPoints[i];
            suffixSum.push(runningSum);
        }

        int prefixSum = 0;
        int ans = suffixSum.top();
        for(int i=0;i<k;i++){
            prefixSum += cardPoints[i];
            suffixSum.pop();
            ans = max(ans, prefixSum + suffixSum.top());
        }

        return ans;
    }
};