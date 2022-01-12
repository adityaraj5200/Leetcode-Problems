// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        int n = s.length();
        vector<int> freq(26,0);
        for(char &ch: s){
            freq[ch-'a']++;
        }
        
        k = min(k,n);
        while(k--){
            (*max_element(freq.begin(),freq.end()))--;
        }
        
        int ans = 0;
        for(int &val: freq){
            ans += val*val;
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends