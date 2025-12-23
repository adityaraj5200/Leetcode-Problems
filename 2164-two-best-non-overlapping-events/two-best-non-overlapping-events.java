/*
Approach:
- We are allowed to attend at most two non-overlapping events.
- Each event is represented as [start, end, value].
- Two events do not overlap if the second event starts strictly after the first one ends.
- First, sort all events by their start time so that binary search can be applied.
- Precompute a suffix array `suffixMax` where:
    suffixMax[i] = maximum event value among events from index i to n-1.
  This allows us to quickly know the best single event we can take after any index.
- For each event i:
    1) Consider taking only this event.
    2) Binary search to find the earliest event j > i such that events[j][0] > events[i][1].
       If such an event exists, combine:
           events[i][2] + suffixMax[j]
- Track the maximum value across all possibilities.
- Return the maximum achievable value.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
    public int maxTwoEvents(int[][] events) {
        int n = events.length;

        // Sort events by start time
        Arrays.sort(events, (a, b) -> Integer.compare(a[0], b[0]));

        // suffixMax[i] = maximum value among events[i..n-1]
        int[] suffixMax = new int[n];
        suffixMax[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = Math.max(suffixMax[i + 1], events[i][2]);
        }

        int ans = 0;

        // Try each event as the first event
        for (int i = 0; i < n; i++) {
            // Case 1: take only this event
            ans = Math.max(ans, events[i][2]);

            // Case 2: take this event + best non-overlapping event after it
            int nextIdx = findNextEvent(events, i + 1, events[i][1]);
            if (nextIdx != -1) {
                ans = Math.max(ans, events[i][2] + suffixMax[nextIdx]);
            }
        }

        return ans;
    }

    // Finds the smallest index >= start such that events[index][0] > endTime
    private int findNextEvent(int[][] events, int start, int endTime) {
        int left = start, right = events.length - 1;
        int res = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (events[mid][0] > endTime) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return res;
    }
}
