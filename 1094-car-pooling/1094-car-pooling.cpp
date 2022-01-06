class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int currcapacity = 0;
        map<int,int> hashmap;
        
        sort(trips.begin(),trips.end());
        for(auto &t: trips){
            hashmap[t[1]] += t[0];  
            hashmap[t[2]] -= t[0];
        }
        
        for(auto &p: hashmap){
            currcapacity += p.second;
            if(currcapacity > capacity)
                return false;
        }
        
        return true;
    }
};