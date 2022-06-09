// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> ans;
    
    void helper(vector<int> &arr,int sum,int idx,int n){
        if(idx==n){
            ans.push_back(sum);
            return;
        }
        
        helper(arr,sum+arr[idx],idx+1,n);
        helper(arr,sum         ,idx+1,n);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        helper(arr,0,0,N);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends