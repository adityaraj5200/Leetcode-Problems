// TC: O(limit^2)
// SC: O(1)
class Solution {
public:
    int distributeCandies(int n, int limit) {
        int result = 0;
        for (int i = 0; i <= limit; i++) {
            for (int j = 0; j <= limit; j++) {
                // k is number of candies left after distributing to first 2 kids, so it must be >=0 && <=limit to distribute to the 3rd kid also.
                int k = n - (i + j); 
                if ((0 <= k) && (k <= limit)) result++;
            }
        }
        return result;
    }
};