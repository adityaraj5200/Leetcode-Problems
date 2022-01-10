class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length(), sign = 1;
        while(i<n && s[i]==' ')
            i++;
        
        if(s[i]=='-' || s[i]=='+'){
            if(s[i]=='-') 
                sign = -1;
            i++;
        }
        
        long long res = 0;
        while(i<n && isdigit(s[i])){
            res = res*10 + (s[i++]-'0');
            if(res > INT_MAX)
                return sign==1 ? INT_MAX : INT_MIN;
        }
        
        return int(res * sign);
    }
};