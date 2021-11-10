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
    string longestNiceSubstring(string s) {
        int n = s.length();
        string res;
        for(int i=0;i<n;i++){
            int mismatches = 0;
            vector<bool> vec(52,false);
            for(int j=i;j<n;j++){
                int index = (islower(s[j])) ? s[j]-'a' : s[j]-'A'+26;
                int otherIndex = index<26 ? index+26 : index-26;
                
                if(!vec[index]){
                    if(vec[otherIndex]) mismatches--;
                    else mismatches++;
                    vec[index] = true;
                }
                
                if(mismatches==0 && j-i+1>res.length())
                    res = s.substr(i,j-i+1);
            }
        }
        return res;
    }
};