class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> uniqueORs, lastResult;
        for(int &num: arr){
            unordered_set<int> nextSet = {num};
            // lastResult contains all the ORs of the subarrays ending at the guy just before the 'num'
            for(int ORvalue: lastResult){
                nextSet.insert(num|ORvalue);
            }

            // Updating the lastResult for the inext iteration
            lastResult = nextSet;

            // Put the new nextSet in the final uniqueORs
            for(int nextSetOR: nextSet){
                uniqueORs.insert(nextSetOR);
            }
        }

        return (int)uniqueORs.size();
    }
};