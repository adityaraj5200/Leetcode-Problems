void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '"' << x << '"';}
void __print(const string &x) {cout << '"' << x << '"';}
void __print(bool x) {cout << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#define nline cout<<endl
#else
#define debug(x...)
#endif


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums){
        sort(nums.begin(),nums.end());
        int n = nums.size(), maxdp = 1, prev = nums[0];
        vector<int> dp(n,1), result;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]>=dp[i]){
                    dp[i] = dp[j]+1;
                    if(dp[i] > maxdp){
                        maxdp = dp[i];
                        prev = nums[i];
                    }
                }
            }
        }
        
        for(int i=n-1;i>=0 ;i--){
            if(dp[i] == maxdp && prev%nums[i] == 0){
                result.push_back(nums[i]);
                maxdp--;
                prev = nums[i];
            }
        }
        return result;
    }
};