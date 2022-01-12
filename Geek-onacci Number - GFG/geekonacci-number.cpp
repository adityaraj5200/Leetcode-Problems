/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Code written by Aditya ;)   ||  Codechef/codeforces: @adityaraj5200 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include<bits/stdc++.h>
using namespace std;

//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template<class T> using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update >;

#define fastio                        \
    ios_base::sync_with_stdio(false);   \
    cin.tie(NULL);                      \
    cout.tie(NULL)
#define endl                  "\n" 
#define mod                   1000000007
#define mod2                  998244353
#define PI                    3.14159265358979323846
#define all(u)                u.begin(), u.end()
#define rall(v)               v.rbegin(), v.rend()
#define sortall(u)            sort(all(u))
#define lcm(a,b)              (a*b)/__gcd(a,b)
#define gcd(a,b)              __gcd(a,b)
#define summation(n)          (((n)*((n)+1))/2)
#define lb(u,val)             lower_bound(all(u),val)
#define ub(u,val)             upper_bound(all(u),val)
#define digits(n)             (1+floor(log10(n)))
#define setbits(u)            __builtin_popcount(u)
#define ctz(u)                __builtin_ctz(u)
#define clz(u)                __builtin_clz(u)
#define checkbit(num,i)       (num&(1<<i))  //select the bit of position i of val
#define lowbit(u)             ((u)&((u)^((u)-1))) //get the lowest bit of u
#define trav(u,it)            for(auto it = u.begin(); it != u.end(); it++)
#define in(u, a, b)           (min(a,b) <= u && u <= max(a,b))
#define print(u)              for(auto it=u.begin();it!=u.end();it++)\
                        cout<<*it<<' '; cout<<endl
#define printpair(u)            for(auto it=u.begin();it!=u.end();it++)\
                        cout<<it->first<<' '<<it->second<<endl
#define yes                   "YES"
#define no                    "NO"
typedef unsigned int          uint;
typedef long long             ll;
typedef unsigned long long    ull;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '"' << x << '"';}
void __print(const string &x) {cerr << '"' << x << '"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#define nline cerr << endl
#else
#define debug(x...)
#define nline 
#endif
/*/------------------------------ CODE BEGINS ------------------------------/*/

int solve(){
    vector<int> vec(10);
    int n;
    for(int i=0;i<3;i++){
        cin>>vec[i];
    }
    cin>>n;
    
    // if(n<4) return vec[n-1];
    // debug(n);
    for(int i=3;i<n;i++){
        vec[i] = vec[i-1]+vec[i-2]+vec[i-3];
    }
    // debug(vec.size());
    // debug(vec);
    
    return vec[n-1];
}
/*/------------------------------- CODE ENDS -------------------------------/*/

int main(){
    // fastio;
    // cout << setprecision(12) << fixed;
    int tc=1;
    cin>>tc;

    for(int t=1;t<=tc;t++){
        // cout<<"Case #" << t  << ": ";
        cout<<solve()<<endl;
    }

    return 0;
}
