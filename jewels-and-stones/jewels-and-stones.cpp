class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<bool> hash(256,0);
        for(char &ch: jewels)
            hash[ch] = true;
        int cnt = 0;
        for(char &ch: stones)
            if(hash[ch] == true)
                cnt++;
        return cnt;
    }
};