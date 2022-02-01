class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = 0, prev = 0;
        for(int &value: target){
            ans += max(0,value-prev);
            prev = value;
        }
        return ans;
    }
};