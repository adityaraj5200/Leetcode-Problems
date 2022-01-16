class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int i = 0, n = seats.size(), ans = 0, last;
        while(i<n && seats[i]==0)
            i++;
        last = ans = i;
        while(i<n){
            if(seats[i]==1){
                ans = max(ans, (i-last)/2);
                last = i;
            }
            i++;
        }
        ans = max(ans,n-1-last);
        return ans;
    }
};