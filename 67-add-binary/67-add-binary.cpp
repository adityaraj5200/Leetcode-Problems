class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int num1 = 0, num2 = 0, carry = 0;
        
        while(!a.empty() || !b.empty()){
            if(!a.empty()){
                num1 = a.back()=='1';
                a.pop_back();
            }
            else num1 = 0;
            
            if(!b.empty()){
                num2 = b.back()=='1';
                b.pop_back();
            }
            else num2 = 0;
            
            int sum = num1 + num2 + carry;
            res.push_back('0'+sum%2);
            carry = sum>=2;
        }
        
        if(carry) res.push_back('1');
        
        
        reverse(res.begin(), res.end());
        return res;
    }
};