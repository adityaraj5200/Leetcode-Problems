class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        int max_hor_gap = max(horizontalCuts[0],h-horizontalCuts.back());
        int max_ver_gap = max(verticalCuts[0],w-verticalCuts.back());
        
        for(int i=1;i<horizontalCuts.size();i++)
            max_hor_gap = max(max_hor_gap, horizontalCuts[i]-horizontalCuts[i-1]);
        for(int i=1;i<verticalCuts.size();i++)
            max_ver_gap = max(max_ver_gap, verticalCuts[i]-verticalCuts[i-1]);
        
        return ((long long)max_hor_gap * (long long)max_ver_gap) % ((long long)(1e9+7));
    }
};