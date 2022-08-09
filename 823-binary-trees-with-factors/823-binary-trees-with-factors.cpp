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
    int isPresent(int key, int end, vector<int>& arr){
        int low = 0, high = end;
        while(low<=high){
            int mid = (low+high)>>1;
            if(arr[mid] > key)
                high = mid-1;
            else if(arr[mid] < key)
                low = mid+1;
            else return mid;
        }
        
        return -1;
    }
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        const long long n = arr.size(), mod = 1e9+7;
        sort(arr.begin(),arr.end());
        vector<long long> dp(n,1LL);
        for(int i=1;i<n;i++){
            long long curr_num = 1LL*arr[i];
            for(int j=2;j*j<=curr_num;j++){
                if(curr_num%j == 0){
                    long long factor1 = curr_num/j;
                    long long factor2 = curr_num/factor1;
                    int idx1 = isPresent(factor1,i-1,arr);
                    int idx2 = isPresent(factor2,i-1,arr);
                    // debug(curr_num,factor1,factor2,idx1,idx2);
                    if(idx1 != -1 && idx2 != -1){
                        dp[i] += ((idx1!=idx2 ? 2 : 1) * dp[idx1] * dp[idx2])%mod;
                    }
                }
            }
        }
        
        long long ans = 0;
        for(long long &value: dp){
            ans = (ans + value)%mod;
        }
        
        // debug(dp);
        
        return (int)ans;
    }
};