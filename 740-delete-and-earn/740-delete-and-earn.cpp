class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> freq;
        for(int &val: nums)
            freq[val]++;
        
        int last = -1, include = 0, exclude = 0, ans = 0;
        for(auto p: freq){
            int points = p.first*p.second, val = p.first;
            
            if(val == last+1){
                int tempinc = include, tempexc = exclude;
                include = exclude + points;
                exclude = max(tempinc, tempexc);
            }
            else{
                ans += max(include,exclude);
                include = points;
                exclude = 0;
            }
            
            last = val;
        }
        
        ans += max(include,exclude);
        
        return ans;
    }
};