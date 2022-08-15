class Solution {
public:
    int romanToInt(string s){
        map<char,int> m = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int ans = 0;
        
        for(int i=0,n=s.length();i<n;i++){
            if(s[i]=='I'){
                if(i+1<n && (s[i+1]=='V' || s[i+1]=='X')) ans += m[s[i+1]]-m[s[i]],i++;
                else ans += m[s[i]];
            }
            else if(s[i]=='X'){
                if(i+1<n && (s[i+1]=='L' || s[i+1]=='C')) ans += m[s[i+1]]-m[s[i]],i++;
                else ans += m[s[i]];
            }
            else if(s[i]=='C'){
                if(i+1<n && (s[i+1]=='D' || s[i+1]=='M')) ans += m[s[i+1]]-m[s[i]],i++;
                else ans += m[s[i]];
            }
            else ans += m[s[i]];
        }
        
        return ans;
    }
};