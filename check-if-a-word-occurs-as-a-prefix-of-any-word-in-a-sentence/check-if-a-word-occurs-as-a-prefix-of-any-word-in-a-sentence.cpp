class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int nthword=1, i=0;
        while(i<sentence.length() ){
            int j=0;
            while(sentence[i]==searchWord[j] && i<sentence.length() && j<searchWord.length())
                i++,j++;
            if(j==searchWord.length())
                return nthword;
            
            nthword++;
            while(i<sentence.length() && sentence[i]!=' ')
                i++;
            i++;
        }
        return -1;
    }
};