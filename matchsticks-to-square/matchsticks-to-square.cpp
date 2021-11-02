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
#else
#define debug(x...)
#endif

class Solution{
public:
    int n,reqsum;
    bool helper(vector<int>& nums,int index,vector<int>&sides){
        if(index==n)
            return all_of(sides.begin(),sides.end(),[&](int x){return x==0;});
        for(int k=0;k<4;k++){
            if(sides[k]-nums[index] < 0) continue;
            sides[k] -= nums[index];
            if(helper(nums,index+1,sides)) return true;
            sides[k] += nums[index];
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        n = matchsticks.size();
        reqsum = sum/4;
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        // sort(matchsticks.begin(),matchsticks.end());
        if(sum%4 || matchsticks.size()<4) return false;
        vector<int> sides(4,sum/4);
        return helper(matchsticks,0,sides);
    }
};