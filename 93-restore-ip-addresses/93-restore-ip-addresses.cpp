class Solution {
public:
    int n;
    string curr;
    string s;
    vector<string> result;
    
    void helper(int i,int num,int dotsInserted){
        if(dotsInserted > 3 || num>255) return;
        if(i==n){
            if(dotsInserted==3)
                result.push_back(curr);
            return;
        }
        
        curr += '.';
        curr += s[i];
        helper(i+1,s[i]-'0',dotsInserted+1);
        curr.pop_back();
        curr.pop_back();
        
        if((curr.length()>=2 && curr.back()=='0' && curr[curr.length()-2]=='.') || (curr.length()==1 && curr.back()=='0')){
            // If so far our current string ends with a (dot and a zero, which is ".0") 
            // or starts with a zero "0" ,
            // then we can't take more numbers with as numbers with leading zeroes are not allowed.
            // for e.g."0.011.255.245" is not allowed as "011" as leading zero
            return;
        }
        
        num = num*10 + (s[i]-'0');
        curr += s[i];
        helper(i+1,num,dotsInserted);
        curr.pop_back();
    }
    
    vector<string> restoreIpAddresses(string s) {
        n = s.length();
        if(n==0) return {};
        this->s = s;
        curr += s[0];
        helper(1,s[0]-'0',0);
        return result;
    }
};