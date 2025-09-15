class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        int countFullyType = 0;
        boolean[] broken = new boolean[26];
        for(char ch: brokenLetters.toCharArray()){
            int index = ch-'a';
            broken[index] = true;
        }

        boolean canType = true;
        for(char ch: text.toCharArray()){
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
}