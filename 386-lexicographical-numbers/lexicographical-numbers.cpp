class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        result.reserve(n);
        
        int curr = 1;
        for(int i = 0; i < n; i++) {
            result.push_back(curr);
            
            // Try to go "deeper" by appending a '0': e.g., 1 → 10
            if(curr * 10 <= n) {
                curr *= 10;
            } 
            else {
                // If can't go deeper, try to increment
                // But if ending digit is 9, or curr == n, we need to backtrack
                while(curr % 10 == 9 || curr + 1 > n) {
                    curr /= 10;
                }
                curr += 1;
            }
        }
        
        return result;
    }
};
