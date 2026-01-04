/**
 * Approach:
 * 1. Each row of 3 cells can be painted in 12 valid ways (no two adjacent cells same):
 *    - 6 ways where the first and third color are the same (“type2”),
 *    - 6 ways where all three colors are different (“type3”). :contentReference[oaicite:0]{index=0}
 * 2. Let:
 *    - dp2 = number of ways where the current row has pattern type2,
 *    - dp3 = number of ways where the current row has pattern type3.
 *    For n = 1, both dp2 and dp3 are 6. :contentReference[oaicite:1]{index=1}
 * 3. For each next row, valid transitions between row patterns are:
 *    - A type2 row can be followed by 3 type2 or 2 type3,
 *    - A type3 row can be followed by 2 type2 or 2 type3. :contentReference[oaicite:2]{index=2}
 *    So the recurrence is:
 *      next2 = (dp2 * 3 + dp3 * 2) % MOD,
 *      next3 = (dp2 * 2 + dp3 * 2) % MOD.
 * 4. Use these recurrences iteratively up to n, keeping values modulo 10^9+7.
 * 5. The total number of valid paint ways for the whole grid is dp2 + dp3 after n rows.
 */

// Time Complexity: O(n)  Space Complexity: O(1)
class Solution {
    public int numOfWays(int n) {
        final int MOD = 1_000_000_007;

        // For first row:
        // - dp2: configurations where ends are same (6 ways)
        // - dp3: configurations where all three are different (6 ways)
        long dp2 = 6; 
        long dp3 = 6;

        for (int i = 1; i < n; i++) {
            long next2 = (dp2 * 3 + dp3 * 2) % MOD;
            long next3 = (dp2 * 2 + dp3 * 2) % MOD;
            dp2 = next2;
            dp3 = next3;
        }
        return (int)((dp2 + dp3) % MOD);
    }
}
