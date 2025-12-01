/*
    Approach:
    - We binary-search on the answer: guess a runtime t (minutes).  
    - To check if runtime t is feasible: each battery contributes min(battery_capacity, t) minutes.  
      Sum these contributions across all batteries: if sum >= n * t → we can power all n computers for t minutes (with swaps).  
    - Use binary search over t from 0 to (sum of all battery capacities) / n.  
    - Return the maximum feasible t.  

    Time Complexity: O(m * log S), where m = batteries.size(), S = sum of capacities  
    Space Complexity: O(1) extra (besides input)
*/
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = accumulate(batteries.begin(), batteries.end(), 0LL);

        long long low = 0;
        long long high = sum / n;
        long long ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;
            long long total = 0;
            for (long long b : batteries) {
                total += min(b, mid);
            }
            if (total >= mid * n) {
                ans = mid;      // feasible: try longer
                low = mid + 1;
            } else {
                high = mid - 1; // not feasible: shorten
            }
        }

        return ans;
    }
};
