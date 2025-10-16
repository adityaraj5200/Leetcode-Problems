class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        // buckets will contain minimum excluded number for each bucket.
        vector<int> buckets(value);
        for(int i=0;i<value;i++){
            buckets[i] = i;
        }

        for(int &num: nums){
            // Ensuring that bucketNum is not -ve.
            int bucketNum = ((num%value)+value)%value;
            buckets[bucketNum] += value;
        }
        
        return *min_element(buckets.begin(), buckets.end());
    }
};