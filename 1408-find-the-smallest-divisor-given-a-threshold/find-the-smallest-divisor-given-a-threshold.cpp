class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int mx = *max_element(nums.begin(), nums.end());
        int low = 1, high = mx;
        while(low < high){
            int mid = (low+high)/2;
            if(getResult(nums, threshold, mid) <= 1LL*threshold){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }

        return high;
    }
private:
    long long getResult(vector<int>& nums, int threshold, int divisor){
        long long result = 0;
        for(int &num: nums){
            result += ((num+divisor-1)/divisor);
        }
        // cout<<"divisor="<<divisor<<"  result="<<result<<endl;
        return result;
    }
};