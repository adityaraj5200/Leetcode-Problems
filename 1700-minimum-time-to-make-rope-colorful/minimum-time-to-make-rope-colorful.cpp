class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0, sumSameColor = 0, maxSameColor = 0;
        char lastColor = '#';
        colors += "#";
        neededTime.push_back(0);
        for(int i=0;i<colors.size();i++){
            if(colors[i] != lastColor){
                ans += sumSameColor-maxSameColor;
                sumSameColor = 0, maxSameColor = INT_MIN;
            }
            sumSameColor += neededTime[i];
            maxSameColor = max(maxSameColor, neededTime[i]);

            lastColor = colors[i];
        }
        neededTime.pop_back();

        return ans;
    }
};