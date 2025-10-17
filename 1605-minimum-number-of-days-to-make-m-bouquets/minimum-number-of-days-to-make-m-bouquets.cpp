class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(1LL*n < 1LL*m*k) return -1;

        int mx = *max_element(bloomDay.begin(), bloomDay.end());
        int low = 1, high = mx;
        while(low < high){
            int mid = (low+high)/2;
            if(isPossible(bloomDay, m, k, mid)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }

        return low;
    }

private:
    bool isPossible(vector<int>& bloomDay, int m, int k, int daysLimit){
        int numBouquets=0, runningCount=0;
        for(int &day: bloomDay){
            if(day <= daysLimit){
                runningCount++;
                if(runningCount == k){
                    runningCount = 0;
                    numBouquets++;
                    if(numBouquets == m){
                        return true;
                    }
                }
            }
            else{
                runningCount = 0;
            }
        }

        return false;
    }
};