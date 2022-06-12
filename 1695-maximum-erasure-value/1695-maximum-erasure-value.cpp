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
#define nline
#endif

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0, ans = 0;
        unordered_set<int> myset;
        int i=0,j=0,n=nums.size();
        while(i<n && j<n){
            // debug(i,j,nums[i],nums[j]);
            
            if(myset.find(nums[j]) == myset.end()){
                myset.insert(nums[j]);
                sum += nums[j++];
                ans = max(ans, sum);
            }
            else{
                myset.erase(nums[i]);
                sum -= nums[i++];
            }
        }
        
        return ans;
    }
};