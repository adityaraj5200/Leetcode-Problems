class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations){
        stations.push_back({target,0});
        
        priority_queue<int> pq; // pq will contain the refueling amounts which I might take in 
        // if I run out of fuel
        
        int prevPos = 0, currFuel = startFuel;
        int refuels = 0;
        
        for(int i=0;i<stations.size();i++){
            int currPos = stations[i][0];
            int fuelConsumed = currPos - prevPos;
            
            currFuel -= fuelConsumed;
            
            while(currFuel<0 && pq.size()>0){
                currFuel += pq.top();
                pq.pop();
                refuels++;
            }
            
            if(currFuel < 0)
                return -1;
            
            int fuelCurrStationHave = stations[i][1];
            pq.push(fuelCurrStationHave);
            
            prevPos = currPos;
        }
        
        return refuels;
    }
};