// Time Complexity: O(n * 26 * 2 * average_distinct_masks)
// Space Complexity: O(n * 2 * average_distinct_masks)
class Solution {
public:
    int n,k;
    string s;
    unordered_map<long long,int> dp;

    long long encode(int idx,int canChange,int mask){
        return ((long long)idx<<27) | ((long long)canChange<<26) | mask;
    }

    int solve(int idx,int canChange,int mask){
        if(idx==n) return 0;
        long long key=encode(idx,canChange,mask);
        if(dp.count(key)) return dp[key];

        int ans=0;
        int bit=1<<(s[idx]-'a');
        int updatedMask=mask|bit;

        if(__builtin_popcount(updatedMask)>k){
            ans=max(ans,1+solve(idx+1,canChange,bit));
        }else{
            ans=max(ans,solve(idx+1,canChange,updatedMask));
        }

        if(canChange){
            for(char c='a';c<='z';c++){
                if(c==s[idx]) continue;
                int newBit=1<<(c-'a');
                int changedMask=mask|newBit;
                if(__builtin_popcount(changedMask)>k){
                    ans=max(ans,1+solve(idx+1,0,newBit));
                }else{
                    ans=max(ans,solve(idx+1,0,changedMask));
                }
            }
        }

        return dp[key]=ans;
    }

    int maxPartitionsAfterOperations(string s_,int k_){
        s=s_; k=k_; n=s.size();
        dp.clear();
        return solve(0,1,0)+1;
    }
};
