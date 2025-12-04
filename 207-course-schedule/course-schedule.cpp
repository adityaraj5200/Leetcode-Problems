/*
    Approach:
    - Model the courses + prerequisites as a directed graph:
        * Each course is a node 0..numCourses-1.
        * For each prerequisite pair [a, b], add a directed edge b → a (meaning “to take a, you must first complete b”).
    - The problem reduces to: can we order the courses so that all prerequisites are satisfied? 
      That’s possible iff the directed graph has **no cycle**.
    - We detect cycles using **Kahn’s algorithm (BFS / in-degree method)**:
        1. Compute in-degree for every node (number of incoming edges = number of prerequisites).
        2. Initialize a queue with all courses whose in-degree is 0 (i.e. no prerequisites).
        3. Process the queue: repeatedly take a course, and for each dependent course (neighbors), decrement its in-degree.
           If any neighbor’s in-degree becomes 0, add it to the queue.
        4. Keep a count of how many courses we processed. If by the end that count equals numCourses → no cycle → return true. 
           Otherwise (some course never became in-degree 0) → there is a cycle → return false.

    Time Complexity: O(numCourses + prerequisites.size())
    Space Complexity: O(numCourses + prerequisites.size())
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build adjacency list + in-degree array
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto &pr : prerequisites) {
            int a = pr[0];
            int b = pr[1];
            // b -> a
            graph[b].push_back(a);
            indegree[a]++;
        }

        // Initialize queue with courses having no prerequisites
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int taken = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            taken++;

            // “Take” this course, reduce in-degree of dependents
            for (int nxt : graph[cur]) {
                indegree[nxt]--;
                if (indegree[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }

        // If we were able to take all courses, return true
        return (taken == numCourses);
    }
};
