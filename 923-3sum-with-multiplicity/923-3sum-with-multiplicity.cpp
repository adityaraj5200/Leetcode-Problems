class Solution {
public:    
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        unordered_map<int,int> freq;
        const int n = arr.size(), mod = 1e9+7;
        int ans = 0;
        
        for(int i=0;i<n;i++){
            int left = target-arr[i];
            if(freq.find(left) != freq.end()){
                ans = (ans + freq[left])%mod;
            }
            
            for(int j=0;j<i;j++){
                freq[arr[i]+arr[j]]++;
            }
        }
        
        return ans;
    }
};