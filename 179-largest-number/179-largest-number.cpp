class Solution {
public:
    string largestNumber(vector<int>& nums){
        vector<string> numsstring(nums.size());
        for(int i=0;i<nums.size();i++){
            numsstring[i] = to_string(nums[i]);
        }
        
        sort(numsstring.begin(),numsstring.end(), [](string &a,string &b){
            // return compare(a,b);
            return a+b > b+a;
            
            for(int i=0;i<min(a.length(), b.length()); i++)
                if(a[i] != b[i])
                    return a[i] > b[i];
            
            
            if(a.length() < b.length()){
                return a[0] < b[a.length()];
            }
            else if(a.length() > b.length()){
                return b[0] < a[b.length()];
            }
            
            else return true;
        });
        
        string ans;
        for(string &s: numsstring)
            ans += s;
        
        if(ans[0]=='0') ans = "0";
        
        return ans;
    }
};