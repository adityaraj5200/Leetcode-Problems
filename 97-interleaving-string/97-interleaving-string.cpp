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
    int len1,len2,len3;
    vector<vector<int>> dp;
    // dp[i][j] = -1; // yet to be decided
    // dp[i][j] = 1; // upto s1[i] and s2[j], is Interleave
    // dp[i][j] = 0; // upto s1[i] and s2[j], is not Interleave
    
    bool check(string &s1,string &s2,string &s3,int p1,int p2,int p3){
        if(p3==len3)
            return p1==len1 && p2==len2;
        
        if(dp[p1][p2] != -1)
            return dp[p1][p2];
        
        bool way1 = false, way2 = false;
        
        
        if(p1 != len1)
            way1 = s1[p1]==s3[p3] && check(s1,s2,s3,p1+1,p2,p3+1);
        if(p2 != len2)
            way2 = s2[p2]==s3[p3] && check(s1,s2,s3,p1,p2+1,p3+1);
        
        
        dp[p1][p2] = way1 || way2;
        
        return (way1 || way2);
    }
    
    bool isInterleave(string s1, string s2, string s3){
        len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        dp = vector<vector<int>>(len1+1,vector<int>(len2+1,-1));
        
        if(len3 != len1+len2) 
            return false;
        
        return check(s1,s2,s3,0,0,0);
    }
};