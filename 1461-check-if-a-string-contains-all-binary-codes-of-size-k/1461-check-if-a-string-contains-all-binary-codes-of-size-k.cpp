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
    int called = 0; 
    
    void decimalToBinary(int val,int bits=8){
        called++;
        debug(called);
        
        cout<<setw(4)<<val<<" -> ";
        stack<int> stk;
        while(bits--){
            stk.push(val&1);
            val >>= 1;
        }
        while(!stk.empty()){
            cout<<stk.top();
            stk.pop();
        }
        cout<<endl;
    }
    
    bool hasAllCodes(string s, int k) {
        const int n = s.length();
        if(n < k) return false;
        
        // Using a vector whose index will tell whether a value has been found in string s or not
        vector<bool> binary_code(1<<k,false);
        
        
        int mask = 0;
        for(int i=0;i<k;i++){
            // if k = 5, then
            // if i = 0, then j = 4
            // if i = 1, then j = 3
            // and so on..
            int j = k-i-1;
            mask |= s[i]=='1' ? (1<<j) : 0;
        }
        
        // decimalToBinary(mask,k);
        mask >>= 1;
        
        int num_of_codes_found = 0, total_codes = (1<<k);
        
        // Iterate through s and check how many of those generated binary codes are matched
        for(int i=k-1;i<n;i++){
            mask <<= 1;
            if(mask & (1<<k))
                mask ^= (1<<k);
            
            // decimalToBinary(mask);
            
            mask |= (s[i]=='1') ? 1 : 0;
            if(binary_code[mask] == false){
                binary_code[mask] = true;
                
                num_of_codes_found++;
                if(num_of_codes_found == total_codes)
                    return true;
            }
        }
        
        return false;
    }
};