class Solution {
public:
    string minRemoveToMakeValid(string s) {
        const int n = s.length();
        int stack = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                stack++;
            }
            else if(s[i]==')'){
                stack--;
                if(stack<0){
                    stack = 0;
                    s[i] = '*';
                }
            }
        }
        
        stack = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')'){
                stack++;
            }
            else if(s[i]=='('){
                stack--;
                if(stack<0){
                    stack = 0;
                    s[i] = '*';
                }
            }
        }
        
        string ans;
        for(char &ch: s){
            if(ch!='*')
                ans += ch;
        }
        
        return ans;
    }
};