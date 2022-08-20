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
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit){
        const int n = startTime.size();
        vector<vector<int>> jobs(n);
        
        for(int i=0;i<n;i++)
            jobs[i] = {endTime[i],startTime[i],profit[i]};
        
        sort(jobs.begin(),jobs.end());
        
        map<int,int> dp = {{0,0}}; // dp[t] will tell me what is the best profit I can make with the time from 0 to t.
           
        int overallBestProfit = 0;
        
        for(int i=0;i<n;i++){
            int currEndTime = jobs[i][0];
            int currStartTime = jobs[i][1];
            int associatedProfit = jobs[i][2];
            
            int currBestProfit = prev(dp.upper_bound(currStartTime))->second + associatedProfit;
            
            overallBestProfit = max(overallBestProfit,currBestProfit);
            
            dp[currEndTime] = overallBestProfit;
        }
        
        return overallBestProfit;
    }
};