// Approach:
// 1. Each child must get ≥ 1 candy. And if a child has a higher rating than a neighbor, they must get more.
// 2. The key is we must satisfy **both** left-neighbor and right-neighbor constraints.
// 3. First pass (left→right): ensure for any i: if rating[i] > rating[i-1], then candies[i] = candies[i-1] + 1.
// 4. Second pass (right→left): ensure for any i: if rating[i] > rating[i+1], then candies[i] = max(candies[i], candies[i+1] + 1).
// 5. Summing the result gives minimum total candies under both constraints (because we enforce the stricter of the two directions at each i).
//
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;

        vector<int> candies(n, 1);

        // Left to right pass: handle left neighbor constraint
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right to left pass: handle right neighbor constraint
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Sum up candies
        return accumulate(candies.begin(), candies.end(), 0);
    }
};