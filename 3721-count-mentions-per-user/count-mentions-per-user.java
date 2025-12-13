/*
Approach:
1. Parse and sort all events by (timestamp, event type) so that OFFLINE events
   at the same timestamp are processed before MESSAGE events.
2. Maintain:
   - an int[] nextOnline representing when each user will be online again
     (initially 0, meaning already online),
   - an int[] ans to count mentions per user,
   - a lazy counter for "ALL" mentions to add at the end.
3. For each event:
   - If OFFLINE: mark user offline by setting nextOnline[user] = timestamp + 60.
   - If MESSAGE ALL: increment lazy (to be applied at end).
   - If MESSAGE HERE: increment ans[i] for all i where nextOnline[i] <= current time.
   - If MESSAGE with specific ids: parse each "idX" and increment ans for each,
     counting duplicates separately.
4. After processing all events, add lazy to every user's count.

Time Complexity: O(m log m + m * u)  
 (m = number of events, u = number of users for "HERE" checks)
Space Complexity: O(u)
*/
class Solution {
    public int[] countMentions(int numberOfUsers, List<List<String>> events) {
        // Sort by timestamp, then OFFLINE before MESSAGE
        Collections.sort(events,
            (a, b) -> {
                int t1 = Integer.parseInt(a.get(1));
                int t2 = Integer.parseInt(b.get(1));
                if (t1 != t2) return Integer.compare(t1, t2);
                // "OFFLINE" should come before "MESSAGE"
                if (a.get(0).equals("OFFLINE") && !b.get(0).equals("OFFLINE")) return -1;
                if (!a.get(0).equals("OFFLINE") && b.get(0).equals("OFFLINE")) return 1;
                return 0;
            }
        );

        int[] ans = new int[numberOfUsers];
        int[] nextOnline = new int[numberOfUsers]; // when user becomes online next
        int lazyAll = 0;

        for (List<String> event : events) {
            String type = event.get(0);
            int time = Integer.parseInt(event.get(1));
            String data = event.get(2);

            if (type.equals("OFFLINE")) {
                int userId = Integer.parseInt(data);
                // offline for 60 time units
                nextOnline[userId] = time + 60;
            } else { // MESSAGE event
                if (data.equals("ALL")) {
                    lazyAll++;
                } else if (data.equals("HERE")) {
                    // Mention all currently online users
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (nextOnline[i] <= time) {
                            ans[i]++;
                        }
                    }
                } else {
                    // Mention specific users; duplicates count
                    String[] parts = data.split(" ");
                    for (String p : parts) {
                        int id = Integer.parseInt(p.substring(2)); // "idX"
                        ans[id]++;
                    }
                }
            }
        }

        // Add lazy "ALL" mentions to each user
        if (lazyAll > 0) {
            for (int i = 0; i < numberOfUsers; i++) {
                ans[i] += lazyAll;
            }
        }
        return ans;
    }
}
