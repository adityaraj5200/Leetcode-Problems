class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int val = 0;
        for(string &op: operations){
            val += op[1]=='+' ? 1 : -1;
        }
        return val;
    }
};