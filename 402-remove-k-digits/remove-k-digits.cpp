class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string ans;
        for(char& ch: num){
            while(k>0 && ans.size()>0 && ans.back()>ch){
                ans.pop_back();
                k--;
            }

            ans += ch;
        }

        if(!ans.empty() && ans[0]=='0'){
            int firstNonZeroIndex = 0;
            while(firstNonZeroIndex<n && ans[firstNonZeroIndex]=='0'){
                firstNonZeroIndex++;
            }

            ans = ans.substr(firstNonZeroIndex);
        }

        while(k>0 && !ans.empty()){
            ans.pop_back();
            k--;
        }

        if(ans.empty()){
            ans += '0';
        }

        return ans;
    }
};
