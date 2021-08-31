#define print(u)              for(auto it=u.begin();it!=u.end();it++)\
                        cout<<*it<<' '; cout<<endl
#define printii(u)            for(auto it=u.begin();it!=u.end();it++)\
                        cout<<it->first<<' '<<it->second<<endl

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


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s){
        int n = s.length();
        if(n<=10) return vector<string>();
        string curr;
        for(int i=0; i<10; i++)
            curr.push_back(s[i]);
        
        // debug(curr);
        unordered_set<string> encountered,resultset;
        encountered.insert(curr);
        
        // debug(encountered);
        for(int i=10;i<n;i++){
            curr.erase(curr.begin());
            curr.push_back(s[i]);
            // debug(curr);
            if(encountered.find(curr) != encountered.end()){
                resultset.insert(curr);
            }
            encountered.insert(curr);
        }
        
        vector<string> result(resultset.begin(),resultset.end());
        return result;
    }
};