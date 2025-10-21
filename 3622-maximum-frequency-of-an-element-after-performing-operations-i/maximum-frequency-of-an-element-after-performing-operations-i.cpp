// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        const int N=1e5+2;
        int freq[N]={0}, sweep[N]={0}, mm=N, MM=0;

        for(int x: nums){
            freq[x]++;

            // Each number x can be changed to any value in range [x-k, x+k]
            // To mark that range, we do line-sweep style difference updates
            const int x0=max(1, x-k);     // start of reachable range
            const int xN=min(x+k+1, N-1); // end+1 (to cancel effect after x+k)
            sweep[x0]++;                  
            sweep[xN]--;

            mm=min(mm, x0);
            MM=max(MM, xN);
        }

        // Example visualization:
        // Suppose nums=[4,8] and k=2
        // 4 contributes +1 at 2 and -1 at 7  (range [2,6])
        // 8 contributes +1 at 6 and -1 at 11 (range [6,10])
        //
        // sweep:      -----s----e----s----e-----
        // value:           2    6    7   11
        //
        // After prefix sum (line sweep):
        // counts:      000112222111000...
        // meaning at each point how many numbers can reach that value

        int ans=0, xReachableCount=0;
        for(int x=mm; x<=MM; x++){
            xReachableCount+=sweep[x]; // running prefix sum — how many nums can reach x

            int freqCurr=freq[x]; // actual count of nums that are already x
            int changeable=min(xReachableCount-freqCurr, numOperations); // can modify limited nums
            int totalFreq=freqCurr+changeable; // total possible frequency of x
            ans=max(ans,totalFreq);
        }

        return ans;
    }
};
