class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0, candidate1 = INT_MIN, candidate2 = INT_MIN, n = nums.size();
        for(int &val: nums){
            if(val == candidate1)
                count1++;
            else if(val == candidate2)
                count2++;
            else if(count1 == 0)
                candidate1 = val, count1 = 1;
            else if(count2 == 0)
                candidate2 = val, count2 = 1;
            else
                count1--, count2--;
        }
        
        vector<int> ans;
        count1 = 0, count2 = 0;
        for(int &val: nums){
            if(val==candidate1)
                count1++;
            else if(val==candidate2)
                count2++;
        }
        
        if(count1 > n/3)
            ans.push_back(candidate1);
        if(count2 > n/3)
            ans.push_back(candidate2);
        
        return ans;
    }
};