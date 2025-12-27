/**
 * Approach:
 * 1. Sort all meetings by start time so they are processed in chronological order.
 * 2. Use two priority queues to strictly follow the problem’s room-selection rules:
 *    - availableRooms: a min-heap of room indices, ensuring we always pick the
 *      smallest indexed free room.
 *    - busyRooms: a min-heap storing {endTime, roomIndex}, ordered by:
 *         a) earliest end time
 *         b) smallest room index (tie-breaker)
 * 3. Maintain an array meetingCount[] to track how many meetings each room hosts.
 * 4. For each meeting (start, end):
 *    a. Free all rooms whose meetings have ended (endTime <= start) by moving
 *       them from busyRooms to availableRooms.
 *    b. If there is at least one available room:
 *       - Assign the meeting to the smallest indexed available room.
 *       - Push it into busyRooms with its original end time.
 *    c. Otherwise (no room is free):
 *       - Take the room that finishes earliest from busyRooms.
 *       - Delay the meeting to start at that room’s end time.
 *       - New end time = earliestEnd + (end - start).
 *       - Push it back into busyRooms.
 *    d. Increment the meeting count for the chosen room.
 * 5. After processing all meetings, return the room index with the maximum
 *    meeting count (smallest index in case of ties).
 */

// Time & Space Complexity:
// Time Complexity: O(m log m + m log n)
//   - m log m for sorting meetings
//   - m log n for heap operations per meeting
// Space Complexity: O(n)
class Solution {
    public int mostBooked(int n, int[][] meetings) {
        // Sort meetings by start time
        Arrays.sort(meetings, (a, b) -> Integer.compare(a[0], b[0]));

        // Min-heap of available room indices
        PriorityQueue<Integer> availableRooms =
                new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            availableRooms.offer(i);
        }

        // Min-heap of busy rooms: {endTime, roomIndex}
        PriorityQueue<long[]> busyRooms =
                new PriorityQueue<>((a, b) -> {
                    if (a[0] != b[0]) {
                        return Long.compare(a[0], b[0]); // earlier end first
                    }
                    return Long.compare(a[1], b[1]);     // smaller index first
                });

        int[] meetingCount = new int[n];

        // Process each meeting
        for (int[] meeting : meetings) {
            long start = meeting[0];
            long end = meeting[1];
            long duration = end - start;

            // Free rooms that have finished before or at current start time
            while (!busyRooms.isEmpty() && busyRooms.peek()[0] <= start) {
                long[] finished = busyRooms.poll();
                availableRooms.offer((int) finished[1]);
            }

            if (!availableRooms.isEmpty()) {
                // Assign to smallest indexed available room
                int room = availableRooms.poll();
                meetingCount[room]++;
                busyRooms.offer(new long[]{end, room});
            } else {
                // Delay meeting to the earliest finishing room
                long[] earliest = busyRooms.poll();
                int room = (int) earliest[1];
                long newEnd = earliest[0] + duration;

                meetingCount[room]++;
                busyRooms.offer(new long[]{newEnd, room});
            }
        }

        // Find the room with the maximum number of meetings
        int bestRoom = 0;
        for (int i = 1; i < n; i++) {
            if (meetingCount[i] > meetingCount[bestRoom]) {
                bestRoom = i;
            }
        }
        return bestRoom;
    }
}
