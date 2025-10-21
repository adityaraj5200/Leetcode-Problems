// Time Complexity: O(n log n)
// Space Complexity: O(n)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int,int> cnt;
        map<long long,int> reachable;
        
        for (long long v : nums) {
            cnt[v]++;

            // first just mark which points are starting and ending points
            reachable[v - k] += 1;
            reachable[v + k + 1] -= 1;
        }

        // -----s----s--e---e-----
        //      1    1   -1  -1

        int firstStartingPoint = reachable.begin()->first;
        int lastEndingPoint = prev(reachable.end())->first;
        int answer = 1;
        // Now populate reachable by doing line sweep and also calculate the answer in the go
        // -----s----s--e---e-----
        //      1111122221111000...
        for(int currValue=firstStartingPoint, lastValue = 0;currValue<lastEndingPoint;currValue++){
            reachable[currValue] += lastValue;
            lastValue = reachable[currValue];

            int freqCurrValue = cnt.count(currValue) ? cnt[currValue] : 0;
            int numCandidatesWhoGotChanged = min(reachable[currValue]-freqCurrValue, numOperations);
            int maxFreqOfCurrValue = freqCurrValue + numCandidatesWhoGotChanged;
            answer = max(answer, maxFreqOfCurrValue);
        }
        
        return answer;
    }
};