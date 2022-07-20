class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        // next[i][j] tells that if I start traversing from ith character in s, then where will I earliest encounter j-th character(j==0 -> 'a', j==1-> 'b' and so on).
        // This search also includes the ith character (search is from ith to n-1 th).
        // Which means that if I am sitting on character 'b' and I am finding the next[i][1] (j==1 -> 'b')
        // Then I will the get the current index as answer because that is the earliest encounter of that character        
        vector<vector<int>> next(s.length()+1,vector<int>(26,1e9));
        
        
        for(int i=s.length()-1;i>=0;i--){
            int character = s[i]-'a';
            for(int j=0;j<26;j++){
                next[i][j] = next[i+1][j];
            }
            next[i][character] = i;
        }
        
        int ans = 0;
        for(string &word: words){
            int n = word.length(), i = 0, s_idx = 0;
            bool works = true;
            for(i=0;i<n;i++){
                int to_find = word[i]-'a'; // this is the index I need to find
                s_idx = (next[s_idx][to_find])+1;
                if(s_idx == 1e9+1){
                    works = false;
                    break;
                }
            }
            
            if(works) ans++;            
        }
        
        return ans;
    }
};