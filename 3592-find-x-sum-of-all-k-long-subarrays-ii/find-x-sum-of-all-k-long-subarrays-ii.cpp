// Time Complexity: O(n * log k)  // (each insertion/removal in set costs log k)
// Space Complexity: O(k)         // storing frequencies and top/bot sets for current window

// Approach:
// • Maintain frequency of each number within the current window using a hash map (cnt).
// • Keep two balanced sets (top, bot):
//     → top stores top-x (count,value) pairs contributing to the running sum (count * value).
//     → bot stores the remaining pairs.
// • For each new incoming element:
//     → Update its frequency, move its old record from top/bot, and re-insert it with new count.
//     → If top exceeds x, move the smallest from top → bot and adjust the running sum.
// • When window exceeds size k, remove the outgoing element and rebalance sets similarly.
// • After each valid window (size ≥ k), record current running_sum into result.

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        vector<long long> res;
        unordered_map<int,int> cnt;  // frequency map for current window
        set<pair<long long,int>, greater<pair<long long,int>>> top, bot; // sorted by (count, value)

        long long running_sum = 0; // sum of count*value for top-x elements

        for (int i = 0; i < nums.size(); ++i) {
            int incoming = nums[i];
            long long count = cnt[incoming];

            // Remove old frequency record of incoming element
            if (count) {
                if (auto it = bot.find({count, incoming}); it != bot.end())
                    bot.erase(it);
                else {
                    top.erase({count, incoming});
                    running_sum -= count * incoming;
                }
            }

            // Update frequency and add new record to top
            cnt[incoming] = count + 1;
            top.insert({count + 1, incoming});
            running_sum += (count + 1) * incoming;

            // Ensure only top-x remain in 'top'
            if (top.size() > x) {
                auto it = prev(top.end());
                running_sum -= it->first * it->second;
                bot.insert(*it);
                top.erase(it);
            }

            // Remove outgoing element when window exceeds size k
            if (i >= k) {
                int outgoing = nums[i - k];
                int countOut = cnt[outgoing];

                // Remove old record of outgoing
                if (auto it = bot.find({countOut, outgoing}); it != bot.end())
                    bot.erase(it);
                else {
                    it = top.find({countOut, outgoing});
                    running_sum -= it->first * it->second;
                    top.erase(it);
                }

                // Decrease frequency and possibly move reduced record to bot
                if (countOut > 1)
                    bot.insert({countOut - 1, outgoing});
                --cnt[outgoing];
                if (cnt[outgoing] == 0){ // saving space
                    cnt.erase(outgoing);
                }


                // Rebalance: if top < x, move best element from bot → top
                if (top.size() < x && !bot.empty()) {
                    auto it = bot.begin();
                    running_sum += it->first * it->second;
                    top.insert(*it);
                    bot.erase(it);
                }
            }

            // Record current window’s x-sum
            if (i + 1 >= k){
                res.push_back(running_sum);
            }
        }

        return res;
    }
};
