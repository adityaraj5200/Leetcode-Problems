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
    bool isPossible(vector<int>& nums) {
        map<int,int> freqmap;
        for(int &val: nums)
            freqmap[val]++;
        
        vector<pair<int,int>> freq;
        for(auto p: freqmap)
            freq.push_back(p);
        
        // debug(freq);
        
        int prevfreq = 0, prevprevfreq = 0;
        int prevstarters = 0, prevprevstarters = 0;
        int prevvalue = nums[0]-1;
        
        for(int i=0;i<freq.size();i++){
            
            int currvalue = freq[i].first;
            
            if(currvalue > prevvalue+1){
                // there is a jump in a value
                if(prevstarters!=0 || prevprevstarters!=0)
                    return false;
                
                prevfreq = 0;
            }
            
            int currfreq = freq[i].second;
            int reqfreq = prevstarters + prevprevstarters;
            
            if(currfreq < reqfreq){
                // debug(i,currfreq,reqfreq);
                return false;
            }
            
            int newstarters = max(0, currfreq - prevfreq);
            
            // debug(i,currvalue,newstarters,currfreq,prevfreq);
            
            prevprevstarters = prevstarters;
            prevstarters = newstarters;
            prevvalue = currvalue;
            prevfreq = currfreq;
        }
        
        // debug(prevstarters,prevprevstarters);
        
        return prevstarters==0 && prevprevstarters==0;
    }
};