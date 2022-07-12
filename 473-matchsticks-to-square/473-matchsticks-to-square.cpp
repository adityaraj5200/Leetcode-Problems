class Solution{
public:
    int n,reqsum;
    bool helper(vector<int>& nums,int index,vector<int>&sides){
        if(index==n)
            return all_of(sides.begin(),sides.end(),[&](int x){return x==0;});
        for(int k=0;k<4;k++){
            if(sides[k]-nums[index] < 0) continue;
            sides[k] -= nums[index];
            if(helper(nums,index+1,sides)) return true;
            sides[k] += nums[index];
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        n = matchsticks.size();
        reqsum = sum/4;
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        // sort(matchsticks.begin(),matchsticks.end());
        if(sum%4 || matchsticks.size()<4) return false;
        vector<int> sides(4,sum/4);
        return helper(matchsticks,0,sides);
    }
};