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
    int n,m;
    int getSum(vector<vector<int>> &matrix,int i1,int j1,int i2,int j2){
        return matrix[i2][j2] - (i1>0?matrix[i1-1][j2]:0) - (j1>0?matrix[i2][j1-1]:0) + (i1>0&&j1>0?matrix[i1-1][j1-1]:0);
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        // vector<vector<int>> copy = matrix;
        n = matrix.size();
        m = matrix[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                matrix[i][j] += matrix[i][j-1];
            }    
        }
        
        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                matrix[i][j] += matrix[i-1][j];
            }    
        }
        
        // return -1;
        
        int ans = INT_MIN;
        for(int stcol=0;stcol<m;stcol++){
            for(int endcol=stcol;endcol<m;endcol++){
                int inf = 1e9;
                set<int> pos = {0,inf};
                set<int> neg = {0,inf};
                for(int row=0;row<n;row++){
                    int sumOfCurrBox = getSum(matrix,0,stcol,row,endcol);
                    
                    // if(sum)
                    
                    if(sumOfCurrBox == k)
                        return k;
                    
                    int exceed = sumOfCurrBox - k;
                    int bestSum = sumOfCurrBox;
                    
                    int toDrop = 0;
                    if(sumOfCurrBox > k){
                        auto it = lower_bound(pos.begin(),pos.end(),exceed);
                        toDrop = *it;
                        bestSum = sumOfCurrBox - toDrop;
                    }
                    else{
                        auto it = lower_bound(neg.begin(),neg.end(),exceed);
                        toDrop = *it;
                        bestSum = sumOfCurrBox - toDrop;
                    }
                    
                    // debug(stcol,endcol,row,sumOfCurrBox,bestSum,toDrop);
                    
                    if(sumOfCurrBox >= 0){
                        pos.insert(sumOfCurrBox);
                    }
                    else{
                        neg.insert(sumOfCurrBox);
                    }
                    
                    if(bestSum <= k)
                        ans = max(ans, bestSum);                    
                }
                // cout<<endl;
            }
        }
        
        
        
//         for(int =0;<m;++){
//             for(int =stcol;<m;++){
//                 set<int> pos = {0};
//                 set<int> neg = {0};
//                 for(int row=0;row<n;row++){
//                     int sumOfCurrBox = getSum(matrix,0,stcol,row,endcol);
                    
//                     // if(sum)
                    
//                     if(sumOfCurrBox == k)
//                         return k;
                    
//                     int exceed = sumOfCurrBox - k;
//                     int bestSum = sumOfCurrBox;
                    
//                     int toDrop = 0;
//                     if(sumOfCurrBox > k){
//                         auto it = lower_bound(pos.begin(),pos.end(),exceed);
//                         toDrop = *it;
//                         bestSum = sumOfCurrBox - toDrop;
//                     }
//                     else{
//                         auto it = lower_bound(neg.begin(),neg.end(),exceed);
//                         toDrop = *it;
//                         bestSum = sumOfCurrBox - toDrop;
//                     }
                    
//                     // debug(stcol,endcol,row,sumOfCurrBox,bestSum,toDrop);
                    
//                     if(sumOfCurrBox >= 0){
//                         pos.insert(sumOfCurrBox);
//                     }
//                     else{
//                         neg.insert(sumOfCurrBox);
//                     }
                    
//                     if(bestSum <= k)
//                         ans = max(ans, bestSum);                    
//                 }
//                 // cout<<endl;
//             }
//         }
        
        
        
        return ans;
    }
};