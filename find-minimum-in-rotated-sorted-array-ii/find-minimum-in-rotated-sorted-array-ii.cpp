class Solution{
public:
    int findMin(vector<int> &num){
        int lo = 0, hi = num.size() - 1, mid;
        while(lo < hi){
            mid = lo + (hi - lo) / 2;
            if (num[mid] > num[hi]) lo = mid + 1;
            else if (num[mid] < num[hi]) hi = mid;
            else hi--;
        }
        return num[lo];
    }
};