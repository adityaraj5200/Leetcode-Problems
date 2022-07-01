class Solution {
public:
    string largestNumber(vector<int>& nums){
        vector<string> numsstring(nums.size());
        for(int i=0;i<nums.size();i++){
            numsstring[i] = to_string(nums[i]);
        }
        
        sort(numsstring.begin(),numsstring.end(), [](string &a,string &b){
            return a+b > b+a;
        });
        
        string ans;
        for(string &s: numsstring)
            ans += s;
        
        if(ans[0]=='0') ans = "0";
        
        return ans;
    }
};