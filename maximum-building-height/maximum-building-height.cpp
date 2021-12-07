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
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});
        sort(restrictions.begin(),restrictions.end());
        if(restrictions.back()[0] != n)
            restrictions.push_back({n,n-1});
        
        // debug(restrictions);
        int ans = 0, size = restrictions.size();
        for(int i=0 ; i < size-1 ; i++){
            int &pos1 = restrictions[i][0], &pos2 = restrictions[i+1][0];
            int &h1 = restrictions[i][1], &h2 = restrictions[i+1][1];
            
            if(h2 <= h1 || h2-h1 <= pos2-pos1) continue;
            h2 = h1+pos2-pos1;
        }
        
        for(int i=size-2;i>=0;i--){
            int &pos1 = restrictions[i][0], &pos2 = restrictions[i+1][0];
            int &h1 = restrictions[i][1], &h2 = restrictions[i+1][1];
            
            if(h1 <= h2 || h1-h2 <= pos2-pos1) continue;
            h1 = h2+pos2-pos1;
        }
        
        // debug(restrictions);
        
        for(int i=0 ; i < size-1 ; i++){
            int &pos1 = restrictions[i][0], &pos2 = restrictions[i+1][0];
            int &h1 = restrictions[i][1], &h2 = restrictions[i+1][1];
            
            if(pos2-pos1 >= abs(h1-h2))
                ans = max(ans,(h1+pos2-pos1+h2)/2);
        }
        return ans;
        // nline;nline;
        // debug(restrictions);
//         for(int i=0 ; i < size-1 ; i++){
//             int val = getPeak(restrictions[i],restrictions[i+1]);
//             // restrictions[i][1] = min(restrictions[i][1],val);
//             // restrictions[i+1][1] = min(restrictions[i+1][1],val);
//             int pos1 = restrictions[i][0], pos2 = restrictions[i+1][0];
//             debug(pos1,pos2,val);
//             ans = max(ans,val);
//         }
        
//         // for(vector<int> vec: restrictions)
//         // nline;
//         debug(restrictions);
//         return ans;
    }
};