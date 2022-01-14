class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0,i = 0,ans = 0;
        while(i < k)
            sum += arr[i++];
        
        if(sum/k >= threshold)
            ans++;
        
        while(i<arr.size()){
            sum -= arr[i-k];
            sum += arr[i++];
            if(sum/k >= threshold)
                ans++;
        }
        return ans;
    }
};