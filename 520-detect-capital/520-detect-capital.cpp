class Solution {
public:
    bool detectCapitalUse(string word) {
        int i = 1, n = word.length();
        if(n==1) return true;
        if(islower(word[0]) || (isupper(word[0]) && islower(word[1]))){
            while(i<n)
                if(!islower(word[i++]))
                    return false;
        }
        else{
            while(i<n)
                if(!isupper(word[i++]))
                    return false;
        }
        return true;
    }
};