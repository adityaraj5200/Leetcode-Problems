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
    string convert(string s, int numRows) {
        const int n = s.length();
        if(numRows==1) return s;
        string ans;
        
        for(int curr_row = 0; curr_row<numRows ; curr_row++){
            int idx = curr_row;
            bool alternate = true;
            
            while(idx<n){
                ans += s[idx];
                if(alternate){
                    int rows_down = numRows-1-curr_row;
                    int skip_down = 2*rows_down;
                    if(skip_down==0) ans.pop_back();
                    idx += skip_down;
                }
                else{
                    int rows_up = curr_row;
                    int skip_up = 2*rows_up;
                    if(skip_up==0) ans.pop_back();
                    idx += skip_up;
                }
                
                alternate = !alternate;
            }
        }
        
        return ans;
    }
};