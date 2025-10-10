class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans = INT_MIN, n = energy.size();
        for(int startPoint=n-1;startPoint>n-1-k;startPoint--){
            int idx = startPoint, sum = 0;
            while(idx>=0){
                sum += energy[idx];
                ans = max(ans, sum);
                idx -= k;
            }
        }

        return ans;
    }
};