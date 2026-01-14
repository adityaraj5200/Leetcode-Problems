/**
 * Approach:
 * 1. We want to find Y such that the union area of all squares below Y
 *    equals the union area above Y. Let TotalArea be the union area of all squares.
 *    Target = TotalArea / 2.
 * 2. Compute TotalArea using a vertical sweep: create events for entering a square
 *    at y = y_i and leaving at y = y_i + l_i, process events sorted by y.
 *    Between events we know the union width at that horizontal slice, so we can
 *    integrate width * deltaY to get total area.
 * 3. Once we have TotalArea and events sorted, do a second sweep to find the
 *    smallest Y where areaBelow(Y) >= Target.
 *    - Maintain active x-intervals’ union width via a segment tree over compressed x's.
 *    - For each event (y_k), compute area gained since previous Y: width * (y_k - prevY).
 *    - If accumulated area + gain crosses Target, we solve for Y exactly:
 *        Y = prevY + (Target - accumulatedArea) / currentUnionWidth.
 *    - Otherwise update segment tree by adding/removing x intervals and continue.
 * 4. Return Y when the target is reached.
 */

// Time & Space Complexity:
// Time Complexity: O(n log n)  Space Complexity: O(n)
class Solution {
    public double separateSquares(int[][] squares) {
        int n = squares.length;
        List<Event> events = new ArrayList<>(2 * n);
        TreeSet<Integer> xs = new TreeSet<>();

        // Build events for sweep line and collect x coordinates
        for (int[] s : squares) {
            int x = s[0], y = s[1], l = s[2];
            events.add(new Event(y, 1, x, x + l));
            events.add(new Event(y + l, -1, x, x + l));
            xs.add(x);
            xs.add(x + l);
        }
        // Sort events by y
        Collections.sort(events, (a, b) -> Integer.compare(a.y, b.y));

        // Compute total union area with one sweep
        long totalArea = computeTotalArea(events, xs);
        double target = totalArea / 2.0;

        // Second sweep: find smallest Y reaching half area
        SegmentTree st = new SegmentTree(xs);
        long area = 0;
        int prevY = events.get(0).y;

        for (Event e : events) {
            int y = e.y;
            long width = st.getCoveredWidth();
            long deltaY = (long) y - prevY;
            long areaGain = width * deltaY;
            if (area + areaGain >= target) {
                // The dividing line lies between prevY and y
                return prevY + (target - area) / (double) width;
            }
            area += areaGain;
            st.add(e.x1, e.x2, e.delta);
            prevY = y;
        }
        return prevY;
    }

    // Sweep to compute union area of all squares
    private long computeTotalArea(List<Event> events, TreeSet<Integer> xs) {
        SegmentTree st = new SegmentTree(xs);
        long area = 0;
        int prevY = events.get(0).y;
        for (Event e : events) {
            int y = e.y;
            long width = st.getCoveredWidth();
            area += width * ((long) y - prevY);
            st.add(e.x1, e.x2, e.delta);
            prevY = y;
        }
        return area;
    }

    // Event for sweep
    private static class Event {
        int y, delta, x1, x2;
        Event(int y, int delta, int x1, int x2) {
            this.y = y;
            this.delta = delta;
            this.x1 = x1;
            this.x2 = x2;
        }
    }

    // Segment tree for union width of active x intervals
    private static class SegmentTree {
        private final int n;
        private final int[] xs;
        private final int[] count;
        private final long[] coverLen;

        SegmentTree(TreeSet<Integer> coord) {
            this.xs = new int[coord.size()];
            int idx = 0;
            for (int v : coord) xs[idx++] = v;
            this.n = xs.length - 1;
            this.count = new int[4 * n];
            this.coverLen = new long[4 * n];
        }

        void add(int L, int R, int val) {
            add(0, 0, n - 1, L, R, val);
        }

        // Returns total union width on current sweep line
        long getCoveredWidth() {
            return coverLen[0];
        }

        private void add(int idx, int lo, int hi, int L, int R, int val) {
            if (R <= xs[lo] || xs[hi + 1] <= L) {
                return;
            }
            if (L <= xs[lo] && xs[hi + 1] <= R) {
                count[idx] += val;
            } else {
                int mid = (lo + hi) / 2;
                add(2 * idx + 1, lo, mid, L, R, val);
                add(2 * idx + 2, mid + 1, hi, L, R, val);
            }
            if (count[idx] > 0) {
                coverLen[idx] = (long) xs[hi + 1] - xs[lo];
            } else if (lo == hi) {
                coverLen[idx] = 0;
            } else {
                coverLen[idx] = coverLen[2 * idx + 1] + coverLen[2 * idx + 2];
            }
        }
    }
}
