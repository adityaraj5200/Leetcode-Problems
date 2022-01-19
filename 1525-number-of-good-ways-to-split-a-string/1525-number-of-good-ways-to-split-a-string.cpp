class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        vector<int> fromleft(n), fromright(n);
        
        set<int> unique;
        for(int i=0;i<n;i++){
            unique.insert(s[i]);
            fromleft[i] = unique.size();
        }
        
        unique.clear();
        for(int i=n-1;i>=0;i--){
            unique.insert(s[i]);
            fromright[i] = unique.size();
        }
        
        int ans = 0;
        for(int i=0;i<n-1;i++){
            if(fromleft[i] == fromright[i+1])
                ans++;
        }
        
        return ans;
    }
};