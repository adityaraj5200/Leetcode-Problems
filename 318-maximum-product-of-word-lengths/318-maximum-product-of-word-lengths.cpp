class Solution {
public:
    bool hasCommon(set<char> &s, set<char> &t){
        for(char ch: s){
            if(t.find(ch) != t.end())
                return true;
        }
        
        return false;
    }
    
    int maxProduct(vector<string>& words) {
        int n = words.size(), ans = 0;
        
        vector<set<char>> words_set(n);
        for(int i=0;i<n;i++){
            for(char &ch: words[i]){
                words_set[i].insert(ch);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(!hasCommon(words_set[i], words_set[j])){
                    int len = words[i].length()*words[j].length();
                    if(len > ans)
                        ans = len;
                }
            }
        }
        
        return ans;
    }
};