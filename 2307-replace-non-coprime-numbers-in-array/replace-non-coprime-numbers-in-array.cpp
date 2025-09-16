class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        int lastNum = 1;
        for(int& num: nums){
            ans.push_back(num);

            while(ans.size()>=2 && __gcd(ans[ans.size()-1], ans[ans.size()-2])>1){
                int num1 = ans.back(); ans.pop_back();
                int num2 = ans.back(); ans.pop_back();
                int gcd =__gcd(num1, num2);
                int lcm = (1LL*num1*num2)/gcd;
                ans.push_back(lcm);
            }
        }

        return ans;
    }
};