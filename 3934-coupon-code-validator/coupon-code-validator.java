/*
Approach:
1. Loop over each coupon and check if it's valid:
   - The code must be non-empty.
   - The code can only contain alphanumeric characters or underscores.
   - The business line must be one of the allowed categories.
   - The coupon must be active.
2. For each valid coupon, store its index so we can sort later.
3. Sort the valid coupon indices first by business line in the required order
   ("electronics", "grocery", "pharmacy", "restaurant"), and then by code lexicographically.
4. Build and return the list of sorted coupon codes.

Time Complexity: O(n log n)  
Space Complexity: O(n)
*/
class Solution {
    public List<String> validateCoupons(String[] code, String[] businessLine, boolean[] isActive) {
        int n = code.length;
        List<Integer> valid = new ArrayList<>();

        // Allowed business categories
        Set<String> allowed = Set.of(
            "electronics", "grocery", "pharmacy", "restaurant"
        );

        for (int i = 0; i < n; i++) {
            if (isActive[i] && allowed.contains(businessLine[i]) && isValid(code[i])) {
                valid.add(i);
            }
        }

        // Define custom order for business lines
        Map<String, Integer> order = Map.of(
            "electronics", 0,
            "grocery", 1,
            "pharmacy", 2,
            "restaurant", 3
        );

        // Sort by business order first, then by code lexicographically
        valid.sort((a, b) -> {
            int cmp = Integer.compare(
                order.get(businessLine[a]),
                order.get(businessLine[b])
            );
            if (cmp != 0) return cmp;
            return code[a].compareTo(code[b]);
        });

        List<String> result = new ArrayList<>();
        for (int idx : valid) {
            result.add(code[idx]);
        }
        return result;
    }

    private boolean isValid(String s) {
        if (s == null || s.length() == 0) return false;
        for (char c : s.toCharArray()) {
            if (!Character.isLetterOrDigit(c) && c != '_') {
                return false;
            }
        }
        return true;
    }
}
