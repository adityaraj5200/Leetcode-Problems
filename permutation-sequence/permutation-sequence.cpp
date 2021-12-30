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

    string getPermutation(int n, int k) {
        vector<int> fact = vector<int>(n+1,1);
        for(int i=2;i<=n;i++)
            fact[i] = fact[i-1]*i;
        // debug(fact);
        string result;
        
        vector<int> notTaken(n+1,false);
        
        while(n>0){
            int newk = k % fact[n-1] ? k % fact[n-1] : fact[n-1];
            int group = k/fact[n-1] + (k%fact[n-1]!=0);
            // debug(k,fact[n-1],group);
            int cnt = 0, idx = 1;
            while(cnt < group){
                cnt += !notTaken[idx++];
                // debug(cnt,group,idx);
            }
            // nline;
            notTaken[--idx] = true;
            // debug(idx);
            result.push_back(idx+'0');
            
            k = newk;
            n--;
        }
        // cout<<"here";
        // debug(result);
        
        return result;
    }
};