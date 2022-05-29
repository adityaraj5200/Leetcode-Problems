class Solution {
public:
    bool non_intersecting(set<char>& s1,set<char>& s2){
        auto it1 = s1.begin(),it2 = s2.begin();
        while(it1!=s1.end() && it2!=s2.end()){
            if(*it1<*it2) it1++;
            else if(*it1>*it2) it2++;
            else return false;
        }
        return true;
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
                if(non_intersecting(words_set[i], words_set[j])){
                    int len = words[i].length() * words[j].length();
                    ans = max(ans ,len);
                }
            }
        }
        
        return ans;
    }
};