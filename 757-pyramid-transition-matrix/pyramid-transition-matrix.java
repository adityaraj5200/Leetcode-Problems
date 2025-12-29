/**
 * Approach:
 * 1. We are given a bottom row and a list of allowed triples (X Y -> Z),
 *    which means if two adjacent blocks are X and Y, we may place Z above them.
 * 2. Build a mapping: for each adjacent pair XY, store all possible Z’s that can
 *    be placed above them.
 * 3. Recursively attempt to build the pyramid level by level:
 *    - If we have reduced the current row to a single character, we succeeded.
 *    - Otherwise, generate all possible next rows by choosing for each adjacent
 *      pair in the current row all allowed blocks above.
 *    - Use backtracking to try all combinations for the next row.
 * 4. If any combination leads to a valid top, return true; if all fail, return false.
 * 5. Since the length is small (<= 7), DFS with backtracking is feasible.
 */

// Time & Space Complexity:
// Time Complexity: O(n * 3^n) in the worst case (branching from allowed transitions).
// Space Complexity: O(n^2) for recursion depth and mapping storage.
class Solution {
    public boolean pyramidTransition(String bottom, List<String> allowed) {
        // Build mapping: key = pair (XY), value = list of possible top blocks Z
        Map<String, List<Character>> map = new HashMap<>();
        for (String triplet : allowed) {
            String key = triplet.substring(0, 2);
            char top = triplet.charAt(2);
            map.computeIfAbsent(key, k -> new ArrayList<>()).add(top);
        }
        // Invoke recursive build
        return canBuild(bottom, map);
    }

    private boolean canBuild(String current, Map<String, List<Character>> map) {
        // If only one block remains, we built successfully
        if (current.length() == 1) {
            return true;
        }
        // List of possible next row options
        List<StringBuilder> nextRows = new ArrayList<>();
        nextRows.add(new StringBuilder());

        // For each adjacent pair, extend all partial next rows
        for (int i = 0; i < current.length() - 1; i++) {
            String pair = current.substring(i, i + 2);
            List<Character> candidates = map.get(pair);
            if (candidates == null) {
                // This pair has no allowed top block
                return false;
            }
            // Build a new list of partial next rows by combining with each candidate
            List<StringBuilder> updated = new ArrayList<>();
            for (StringBuilder prefix : nextRows) {
                for (char c : candidates) {
                    StringBuilder sb = new StringBuilder(prefix);
                    sb.append(c);
                    updated.add(sb);
                }
            }
            nextRows = updated;
        }
        // Recursively attempt all next row options
        for (StringBuilder next : nextRows) {
            if (canBuild(next.toString(), map)) {
                return true;
            }
        }
        return false;
    }
}