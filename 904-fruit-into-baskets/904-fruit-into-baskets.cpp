class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> mp;
        int i=0,j=0,n=fruits.size(),ans=0;
        while(j<n){
            while(j<n){
                mp[fruits[j++]]++;
                if(mp.size()==3) break;
                ans = max(ans,j-i);
            }
            
            if(j==n)
                break;
            
            while(mp.size()==3){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0)
                    mp.erase(fruits[i]);
                i++;
            }
        }
        return ans;
    }
};