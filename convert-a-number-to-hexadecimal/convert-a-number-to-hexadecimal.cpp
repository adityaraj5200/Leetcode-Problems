class Solution {
public:
    string toHex(int num) {
        if(num==0) return "0";
        unsigned int mynum = num, base = 16, rem;
        string hex;
        while(mynum){
            rem = mynum % 16;
            hex += rem<10 ? '0'+rem : 'a'+rem%10;
            mynum /= base;
        }
        reverse(hex.begin(),hex.end());
        return hex;
    }
};