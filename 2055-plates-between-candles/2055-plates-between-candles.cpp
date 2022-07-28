class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        const int n = s.length();
        vector<int> nextCandle(n), prevCandle(n);
        
        int last = -1;
        for(int i=0;i<n;i++){
            if(s[i]=='|')
                last = i;
            prevCandle[i] = last;
        }
        
        last = n;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='|')
                last = i;
            nextCandle[i] = last;
        }
        
        vector<int> plates(n);
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='*') cnt++;
            plates[i] = cnt;
        }
        
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int left = queries[i][0];
            int right = queries[i][1];
            
            left = nextCandle[left];
            right = prevCandle[right];
            
            if(left>right) ans[i] = 0;
            else{
                ans[i] = plates[right] - (left==0 ? 0 :plates[left-1]);
            }
        }
        
        return ans;
    }
};