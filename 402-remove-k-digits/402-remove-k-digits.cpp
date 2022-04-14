class Solution {
public:
    string removeKdigits(string num, int k) {
        string s;
        
        for(char &ch: num){
            while(k>0 && s.length()>0 && ch<s.back()){
                s.pop_back();
                k--;
            }
            
            if(!(ch=='0' && s.length()==0))
                s += ch;
        }
        
        while(k>0 && s.length()>0){
            s.pop_back();
            k--;
        }
        
        return s.length()==0 ? "0" : s;
    }
};