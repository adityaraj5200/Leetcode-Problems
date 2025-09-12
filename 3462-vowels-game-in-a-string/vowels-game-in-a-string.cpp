class Solution {
public:
    bool doesAliceWin(string s) {
        for(char& ch: s){
            if(ch=='a' || ch=='e' || ch=='o' || ch=='u' || ch=='i'){
                return true;
            }
        }
        
        return false;
    }
};