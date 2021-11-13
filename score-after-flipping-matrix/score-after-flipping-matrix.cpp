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
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0] == 0)
                for(int j=0;j<m;j++)
                    grid[i][j] = grid[i][j] ? 0 : 1;
        }
        for(int j=0;j<m;j++){
            int cnt1 = 0;
            for(int i=0;i<n;i++)
                cnt1 += grid[i][j];
            
            if(cnt1 < n-cnt1)
                for(int i=0;i<n;i++)
                    grid[i][j] = grid[i][j] ? 0 : 1;
            
        }
        
        // debug(grid);
        int ans = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j])
                    ans +=  1<<(m-j-1);
        
        return ans;
    }
};