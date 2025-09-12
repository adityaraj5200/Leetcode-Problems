class Solution {
public:
    bool doesAliceWin(string s) {
        int cntVowels = 0;
        for(char& ch: s){
            if(ch=='a' || ch=='e' || ch=='o' || ch=='u' || ch=='i'){
                cntVowels++;
            }
        }

        bool aliceWins = (cntVowels%2==0 && cntVowels>0) || (cntVowels&1);
        return aliceWins;
    }
};