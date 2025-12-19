/*
Approach:
1. Sort all meetings by time.
2. Track who knows the secret in a boolean array; initially person 0 and firstPerson know it.
3. For each group of meetings at the same time:
   - Build a temporary graph connecting people who meet at this time.
   - Starting from those in this group who already know the secret,
     do BFS/DFS to spread the secret across all reachable people in the group.
4. After processing all times, collect and return all people who know the secret.

Time Complexity: O(m log m + m + n)  
Space Complexity: O(m + n)
*/
class Solution {
    public List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {
        // Sort meetings by time
        Arrays.sort(meetings, Comparator.comparingInt(a -> a[2]));

        boolean[] knows = new boolean[n];
        knows[0] = true;
        knows[firstPerson] = true;

        int i = 0;
        while (i < meetings.length) {
            int time = meetings[i][2];
            
            // Build adjacency for all meetings at this time
            Map<Integer, List<Integer>> adj = new HashMap<>();
            Set<Integer> persons = new HashSet<>();
            
            int j = i;
            while (j < meetings.length && meetings[j][2] == time) {
                int x = meetings[j][0], y = meetings[j][1];
                adj.computeIfAbsent(x, k -> new ArrayList<>()).add(y);
                adj.computeIfAbsent(y, k -> new ArrayList<>()).add(x);
                persons.add(x);
                persons.add(y);
                j++;
            }

            // BFS from those who already know the secret
            ArrayDeque<Integer> queue = new ArrayDeque<>();
            Set<Integer> visited = new HashSet<>();
            for (int p : persons) {
                if (knows[p]) {
                    queue.add(p);
                    visited.add(p);
                }
            }

            while (!queue.isEmpty()) {
                int u = queue.poll();
                knows[u] = true;
                List<Integer> neighbors = adj.getOrDefault(u, Collections.emptyList());
                for (int v : neighbors) {
                    if (!visited.contains(v)) {
                        visited.add(v);
                        queue.add(v);
                    }
                }
            }

            i = j;
        }

        List<Integer> result = new ArrayList<>();
        for (int p = 0; p < n; p++) {
            if (knows[p]){
                result.add(p);
            }
        }
        return result;
    }
}
