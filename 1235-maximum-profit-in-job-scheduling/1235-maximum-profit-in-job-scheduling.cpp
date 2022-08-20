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
        vector<vector<int>> jobs(n,vector<int>(3));
        
        for(int i=0;i<n;i++){
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        
        sort(jobs.begin(),jobs.end(),[](vector<int> &v1,vector<int> &v2){
            if(v1[1] == v2[1]){ // If end times are equal then sort by start time
                if(v1[0] == v2[0]) // If start times are equal then sort by profit
                    return v1[2] < v2[2];
                else // otherwise sort by start time
                    return v1[0] < v2[0];
            }
            else // otherwise sort by end time
                return v1[1] < v2[1]; 
        });
        
        map<int,int> dp = {{0,0}}; // dp[t] will tell me what is the best profit I can make with the time from 0 to t.
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            int currStartTime = jobs[i][0];
            int currEndTime = jobs[i][1];
            int currProfit = jobs[i][2];
            
            auto it = dp.lower_bound(-currStartTime);
            int prevBestProfit = it->second;
            
            dp[-currEndTime] = max(prevBestProfit + currProfit, ans);
            
            ans = max(ans, dp[-currEndTime]);
        }
        
        return ans;
    }
};