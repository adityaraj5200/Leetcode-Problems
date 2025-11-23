class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> remainder[3];
        int totalSum = 0;
        for(int &num: nums){
            remainder[num%3].push_back(num);
            totalSum += num;
        }
        
        int rem = totalSum%3;
        int ans = INT_MIN;
        if(rem==0){
            ans = totalSum;
        }
        else if(rem==1){
            if(remainder[1].size()>=1){
                ans = max(ans, totalSum-remainder[1][0]);
            }
            if(remainder[2].size()>=2){
                ans = max(ans, totalSum-(remainder[2][0]+remainder[2][1]));
            }
        }
        else if(rem==2){
            if(remainder[2].size()>=1){
                ans = max(ans, totalSum-remainder[2][0]);
            }
            if(remainder[1].size()>=2){
                ans = max(ans, totalSum-(remainder[1][0]+remainder[1][1]));
            }
        }

        return ans;
    }
};