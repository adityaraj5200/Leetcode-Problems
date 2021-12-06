class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int oddPositions=0,evenPositions=0;
        for(int val: position)
            if(val&1) 
                oddPositions++;
            else
                evenPositions++;
        
        return min(oddPositions,evenPositions);
    }
};