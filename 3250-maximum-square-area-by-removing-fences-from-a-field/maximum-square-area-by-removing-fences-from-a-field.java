/**
 * Approach:
 * 1. To construct a square, we need to pick two horizontal lines (positions from
 *    hFences plus boundaries at 1 and m) and two vertical lines (positions from
 *    vFences plus boundaries at 1 and n) such that the distance between the chosen
 *    horizontal pair equals the distance between the chosen vertical pair.
 * 2. Generate a set of all possible distances between any two horizontal lines 
 *    (including boundaries). Do the same for vertical lines.
 * 3. Compute the intersection of these distance sets and find the maximum common
 *    distance. That distance is the side length of the largest possible square.
 * 4. If such a distance exists, return its square modulo 10^9+7; otherwise return -1.
 */

// Time Complexity: O(h^2 + v^2)  Space Complexity: O(h^2 + v^2)
class Solution {
    public int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
        final int MOD = 1_000_000_007;

        // Include boundaries (1 and m) in horizontal fences
        int[] allH = Arrays.copyOf(hFences, hFences.length + 2);
        allH[hFences.length] = 1;
        allH[hFences.length + 1] = m;
        Arrays.sort(allH);

        // Include boundaries (1 and n) in vertical fences
        int[] allV = Arrays.copyOf(vFences, vFences.length + 2);
        allV[vFences.length] = 1;
        allV[vFences.length + 1] = n;
        Arrays.sort(allV);

        Set<Integer> hGaps = new HashSet<>();
        Set<Integer> vGaps = new HashSet<>();

        // Compute all horizontal distances
        for (int i = 0; i < allH.length; i++) {
            for (int j = 0; j < i; j++) {
                hGaps.add(allH[i] - allH[j]);
            }
        }

        // Compute all vertical distances
        for (int i = 0; i < allV.length; i++) {
            for (int j = 0; j < i; j++) {
                vGaps.add(allV[i] - allV[j]);
            }
        }

        int maxSide = -1;
        for (int d : hGaps) {
            if (vGaps.contains(d)) {
                maxSide = Math.max(maxSide, d);
            }
        }

        return (maxSide <= 0) ? -1 : (int) ((1L * maxSide * maxSide) % MOD);
    }
}
