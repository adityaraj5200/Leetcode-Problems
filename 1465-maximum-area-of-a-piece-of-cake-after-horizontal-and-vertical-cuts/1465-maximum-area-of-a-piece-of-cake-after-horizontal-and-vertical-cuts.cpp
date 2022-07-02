class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        int best_hor_cuts_gap = 0, best_ver_cuts_gap = 0;
        for(int i=1;i<horizontalCuts.size();i++){
            best_hor_cuts_gap = max(best_hor_cuts_gap, horizontalCuts[i]-horizontalCuts[i-1]);
        }
        for(int i=1;i<verticalCuts.size();i++){
            best_ver_cuts_gap = max(best_ver_cuts_gap, verticalCuts[i]-verticalCuts[i-1]);
        }
        
        return ((long long)best_hor_cuts_gap * (long long)best_ver_cuts_gap)%((long long)(1e9+7));
    }
};