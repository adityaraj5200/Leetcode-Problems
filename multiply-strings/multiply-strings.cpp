class Solution{
public:
    string multiply(string num1, string num2){
        if(num1 == "0" || num2 == "0") return "0";
        string res(num1.size()+num2.size(),'0');
        for(int i=num1.length()-1;i>=0;i--){
            int carry = 0;
            for(int j=num2.length()-1;j>=0;j--){
                int val = (res[i+j+1]-'0')+(num1[i]-'0')*(num2[j]-'0')+carry;
                res[i+j+1] = val%10 + '0';
                carry = val/10;
            }
            res[i] += carry;
        }
        int k=0;
        while(res[k] == '0')
            k++;
        return k==res.length() ? "0" : res.substr(k);
    }
};