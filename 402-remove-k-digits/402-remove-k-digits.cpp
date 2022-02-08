class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;
        
        for(char &ch: num){
            while(!result.empty() && ch<result.back() && k>0){
                result.pop_back();
                k--;
            }
            
            if(!result.empty() || ch!='0')
                result += ch;
        }
        
        while(!result.empty() && k>0){
            result.pop_back();
            k--;
        }
        
        return result=="" ? "0" : result;
    }
};