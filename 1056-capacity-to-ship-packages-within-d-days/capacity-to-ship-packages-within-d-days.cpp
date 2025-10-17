class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        auto [minIt, maxIt] = minmax_element(weights.begin(),weights.end());
        int min = *minIt, max = *maxIt;
        int low = max, high = (weights.size()*max);
        int ans = high;
        while(low<=high){
            int mid = (low+high)/2;
            if(isPossible(weights,days,mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;
    }

private:
    bool isPossible(vector<int>& weights, int reqDays, int certainCapacity){
        int daysTook = 1, currLoad = 0;
        for(int &wt: weights){
            currLoad += wt;
            if(currLoad > certainCapacity){
                daysTook++;
                currLoad = wt;
                if(daysTook > reqDays){
                    return false;
                }
            }
        }

        return true;
    }
};