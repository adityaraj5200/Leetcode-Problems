class Solution {
public:
    int calculate(string s) {
        s.push_back('+');
        int n = s.length(), num = 0;
        char lastSign = '+';
        stack<int> stk;
        for(char &ch: s){
            if(ch==' ') continue;
        
            if(isdigit(ch))
                num = num*10 + (ch-'0');
            else{
                if(lastSign=='+' || lastSign=='-'){
                    if(lastSign=='-')
                        num *= -1;
                    stk.push(num);
                }
                else{
                    int temp = stk.top();
                    stk.pop();
                    stk.push(lastSign=='*' ? temp * num : temp / num);
                }
                lastSign = ch;
                num = 0;
            }
        }
        
        int ans = 0;
        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }
        
        return ans;
    }
};