class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        heaters.push_back(-1e9);
        heaters.push_back(2e9);
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        
        map<int,int> next,prev; // stores position of next and previous heater for (key)'th house
        
        int i = 0, j = 0, prev_heater = -1e9;
        const int n = houses.size();
        
        while(i<n){
            if(houses[i] < heaters[j]){
                next[houses[i]] = heaters[j];
                prev[houses[i]] = prev_heater;
                i++;
            }
            else if(houses[i] > heaters[j]){
                prev_heater = prev[houses[i]] = heaters[j];
                j++;
            }
            else{
                prev_heater = next[houses[i]] = prev[houses[i]] = heaters[j];
                i++;
            }
        }
        
        int ans = -1;
        for(int &house: houses){
            int min_dist = min(next[house]-house,house-prev[house]);
            ans = max(ans, min_dist);
        }
        
        return ans;
    }
};