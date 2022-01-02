class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> hashmap(60,0);
        int ans = 0;
        for(int val: time){
            ans += hashmap[(60 - val % 60) % 60];
            hashmap[val%60]++;
        }
        return ans;
    }
};