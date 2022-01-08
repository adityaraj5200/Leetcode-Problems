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
    vector<int> nsr(vector<int> &vec){
        int n = vec.size();
        vector<int> result(n,n);
        stack<int> stk;
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && vec[i] <= vec[stk.top()])
                stk.pop();
            result[i] = !stk.empty() ? stk.top() : n;
            stk.push(i);
        }
        return result;
    }
    
    vector<int> nsl(vector<int> &vec){
        int n = vec.size();
        vector<int> result(n,-1);
        stack<int> stk;
        for(int i=0;i<n;i++){
            while(!stk.empty() && vec[i] <= vec[stk.top()])
                stk.pop();
            result[i] = !stk.empty() ? stk.top() : -1;
            stk.push(i);
        }
        return result;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> NSR = nsr(heights);
        vector<int> NSL = nsl(heights);
        int ans = 0, n = heights.size();
        
        for(int i=0;i<n;i++){
            ans = max(ans, (NSR[i]-NSL[i]-1) * heights[i]);
        }
        return ans;
    }
};