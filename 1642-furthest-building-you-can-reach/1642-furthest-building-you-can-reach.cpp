class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders){
        priority_queue<int> pq;
        int idx, n = heights.size();
        for(idx = 0; idx+1 < n; idx++){
            int diff = heights[idx+1] - heights[idx];
            if(diff > 0) 
                pq.push(-diff);
            
            if(pq.size() > ladders){
                bricks += pq.top();
                pq.pop();
                
                if(bricks<0)
                    break;
            }
        }
        
        return idx;
    }
};