/*
    Approach:
    - Cars at the far left moving left (‘L’) will never meet anyone — they go off the road.  
    - Cars at the far right moving right (‘R’) will never collide — they go off the road.  
    - So remove (logically ignore) the prefix of 'L's and the suffix of 'R's.  
    - In the remaining substring, any car that is moving ('L' or 'R') will eventually collide:
        * Because it’s trapped between some car or stationary car (or series of collisions).  
    - Each moving car in this “collision zone” eventually stops — so count all non-'S' in that substring.  

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int l = 0;
        int r = n - 1;

        // Skip all left-moving cars at the start — they never collide.
        while (l < n && directions[l] == 'L') {
            ++l;
        }
        // Skip all right-moving cars at the end — they never collide.
        while (r >= 0 && directions[r] == 'R') {
            --r;
        }

        int collisions = 0;
        // Every moving car in [l..r] will eventually collide
        for (int i = l; i <= r; ++i) {
            if (directions[i] != 'S') {
                ++collisions;
            }
        }
        return collisions;
    }
};
