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
        long long mod = 1e9+7, ans = 0LL;
        sort(arr.begin(),arr.end());
        map<int,long long> dp;
        
        for(int i=0;i<arr.size();i++){
            dp[arr[i]] = 1LL;
            for(int j=0;j<i;j++){
                int factor1 = arr[j];
                int factor2 = arr[i]/arr[j];                
                // Checking if arr[j] is even a factor or not?
                // And, does factor2 exists in array or not?
                if(arr[i]%arr[j]==0 && dp.count(factor2)){
                    dp[arr[i]] = (dp[arr[i]] + dp[factor1] * dp[factor2])%mod;
                }
            }
            
            ans = (ans + dp[arr[i]])%mod;
        }
        
        return (int)ans;
    }
};