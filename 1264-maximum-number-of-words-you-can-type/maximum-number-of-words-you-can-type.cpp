class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int countFullyType = 0;
        vector<bool> broken(26,false);
        for(char &ch: brokenLetters){
            broken[ch-'a'] = true;
        }

        bool canType=true;
        for(char &ch: text){
            if(ch==' '){
                if(canType){
                    countFullyType++;
                }
                canType = true;
            }
            else if(broken[ch-'a']){
                canType = false;
            }

        }

        if(canType){
            countFullyType++;
        }

        return countFullyType;
    }
};