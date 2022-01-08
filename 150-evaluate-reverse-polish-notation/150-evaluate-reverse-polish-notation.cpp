class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> stk;
        for(auto &s: tokens){
            stk.push(s);
            if(s=="+" || s=="-" || s=="*" || s=="/"){
                string op = stk.top();
                stk.pop();
                int num1 = stoi(stk.top());
                stk.pop();
                int num2 = stoi(stk.top());
                stk.pop();
                if(op == "+")
                    stk.push(to_string(num2 + num1));
                else if(op == "-")
                    stk.push(to_string(num2 - num1));
                else if(op == "/")
                    stk.push(to_string(num2 / num1));
                else
                    stk.push(to_string(num2 * num1));
            }
        }
        return stoi(stk.top());
    }
};