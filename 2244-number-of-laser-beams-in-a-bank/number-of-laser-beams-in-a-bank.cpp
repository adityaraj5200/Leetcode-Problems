class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int lastNumSecurityDevies = 0, ans = 0;
        for(string& s: bank){
            int numSecurityDeviesInCurrentRow = 0;
            for(char& ch: s){
                if(ch=='1'){
                    numSecurityDeviesInCurrentRow++;
                }
            }
            if(numSecurityDeviesInCurrentRow > 0){
                ans += numSecurityDeviesInCurrentRow*lastNumSecurityDevies;
                lastNumSecurityDevies = numSecurityDeviesInCurrentRow;
            }
        }

        return ans;
    }
};