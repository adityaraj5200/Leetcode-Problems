class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> result;
        int currlen = 0, n = chars.size();
        char prev = chars[0];
        for(int i=0;i<n;i++){
            if(chars[i] != prev){ 
                result.push_back(prev);
                if(currlen != 1){
                    string str = to_string(currlen);
                    for(char &c: str)
                        result.push_back(c);
                }
                currlen = 1;
                prev = chars[i];
            }
            else 
                currlen++;
        }
        
        result.push_back(prev);
        if(currlen != 1){
            string str = to_string(currlen);
            for(char &c: str)
                result.push_back(c);
        }
        currlen = 1;
        
        chars = result;
        return result.size();
    }
};